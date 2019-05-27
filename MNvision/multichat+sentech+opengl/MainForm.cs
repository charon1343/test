// *****************************************************************************
//
//     Copyright (c) 2012, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;
using PvDotNet;
using PvGUIDotNet;
using System.Net;
using System.Net.Sockets;
using OpenTK;
using OpenTK.Graphics.OpenGL;



namespace PvSimpleUISample
{
    public partial class MainForm : Form
    {
        //multichat header
        delegate void AppendTextDelegate(Control ctrl, string s);
        AppendTextDelegate _textAppender;
        public Socket mainSock;

        Protocal protocal = new Protocal(); //프로토콜 선언
        byte[] move_receive = new byte[2];  //무브에 사용
        /// <summary>
        /// Constructor.
        /// </summary>
        public MainForm()
        {
            InitializeComponent();
            //multichat 
            mainSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
            _textAppender = new AppendTextDelegate(AppendText);

            // Handlers used to callbacks in the UI thread
            mDisconnectedHandler += new GenericHandler(OnDisconnected);
            mAcquisitionModeChangedHandler += new GenericHandler(OnAcquisitionModeChanged);
            mAcquisitionStateChangedHandler += new GenericHandler(OnAcquisitionStateChanged);

            // Create pipeline - requires stream
            mPipeline = new PvPipeline(mStream);

            //Set browser form owners
            mCommBrowser.Owner = this;
            mDeviceBrowser.Owner = this;
            mStreamBrowser.Owner = this;

            // Create display thread, hook display event
            mDisplayThread = new PvDisplayThread();
            mDisplayThread.OnBufferDisplay += new OnBufferDisplay(OnBufferDisplay);
        }



        // Handler used to bring link disconnected event in the main UI thread
        private delegate void GenericHandler();
        private GenericHandler mDisconnectedHandler = null;

        // Handler used to bring acquisition mode changed event in the main UI thread
        private GenericHandler mAcquisitionModeChangedHandler = null;

        // Handler used to bring acquisition state manager callbacks in the main UI thread
        private GenericHandler mAcquisitionStateChangedHandler = null;

        // Main application objects: device, stream, pipeline
        private PvDevice mDevice = new PvDevice();
        private PvStream mStream = new PvStream();
        private PvPipeline mPipeline = null;

        // Acquisition state manager
        private PvAcquisitionStateManager mAcquisitionManager = null;

        // Display thread
        private PvDisplayThread mDisplayThread = null;

        // Parameter browsers
        private BrowserForm mCommBrowser = new BrowserForm();
        private BrowserForm mDeviceBrowser = new BrowserForm();
        private BrowserForm mStreamBrowser = new BrowserForm();

        /// <summary>
        /// Method that syncs the whole UI enabled state
        /// </summary>
        private void EnableInterface()
        {
            // Connect and disconnect button
            connectButton.Enabled = !mDevice.IsConnected && !mStream.IsOpened;
            disconnectButton.Enabled = mDevice.IsConnected || mStream.IsOpened;

            // Tree browser buttons
            //EnableTreeBrowsers();

            // Acquisition controls
            EnableControls();
        }

        /// <summary>
        /// Connect button click handler
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void connectButton_Click(object sender, EventArgs e)
        {
            // create a device finder wnd and open the select device dialog
            PvDeviceFinderForm lFinder = new PvDeviceFinderForm();
            // Show device finder
            if ((lFinder.ShowDialog() != DialogResult.OK) ||
                (lFinder.Selected == null))
            {
                return;
            }

            // Display hourglass
            Cursor lOld = Cursor;
            Cursor = Cursors.WaitCursor;

            // Connect to device
            Connect(lFinder.Selected);

            // Restore cursor
            Cursor = lOld;
        }

        /// <summary>
        /// Disconnect button event handler
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void disconnectButton_Click(object sender, EventArgs e)
        {
            // Show hourglass
            Cursor lOld = Cursor;
            Cursor = Cursors.WaitCursor;

            // Disconnect from device
            Disconnect();

            // Restore cursor
            Cursor = lOld;
        }

        /// <summary>
        /// Enable the tree browser buttons
        /// </summary>
        //private void EnableTreeBrowsers()
        //{
        //    // Device and stream: enabled if connected
        //    deviceButton.Enabled = mDevice.IsConnected;
        //    streamButton.Enabled = mStream.IsOpened;

        //    // Communication button is always enabled
        //    communicationButton.Enabled = true;
        //}

        /// <summary>
        /// Enables the acquisition controls
        /// </summary>
        private void EnableControls()
        {
            if (!mDevice.IsConnected)
            {
                // Not connected: acquisition state manager not available, directly disable all
                modeComboBox.Enabled = false;
                playButton.Enabled = false;
                stopButton.Enabled = false;
            }
            else
            {
                // Read current acquisition state
                bool lLocked = mAcquisitionManager.State == PvAcquisitionState.Unlocked;

                // Mode and play are enabled if not locked
                modeComboBox.Enabled = lLocked;
                playButton.Enabled = lLocked;

                // Stop is enabled only if locked
                stopButton.Enabled = !lLocked;
            }
        }

        /// <summary>
        /// Form load event handler. 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void MainForm_Load(object sender, EventArgs e)
        {
            // Just syncs the enabled state of the UI
            EnableInterface();

            //multichat
            //주소지정
            IPHostEntry he = Dns.GetHostEntry(Dns.GetHostName());

            // 처음으로 발견되는 ipv4 주소를 사용한다.
            IPAddress defaultHostAddress = null;
            foreach (IPAddress addr in he.AddressList)
            {
                if (addr.AddressFamily == AddressFamily.InterNetwork)
                {
                    defaultHostAddress = addr;
                    break;
                }
            }

            // 주소가 없다면..
            if (defaultHostAddress == null)
                // 로컬호스트 주소를 사용한다.
                defaultHostAddress = IPAddress.Loopback;

            txtAddress.Text = defaultHostAddress.ToString();
        }

        //opengl
        private void glControl1_Load(object sender, EventArgs e)
        {
            GL.ClearColor(0.1f, 0.2f, 0.5f, 0.0f);  // 배경색 alpha는 투명도
            GL.Enable(EnableCap.DepthTest);
        }
        private void glControl1_Resize(object sender, EventArgs e)
        {
            GL.Viewport(0, 0, glControl1.Width, glControl1.Height); //창을 기준으로 한다

            Matrix4 projection = Matrix4.CreatePerspectiveFieldOfView((float)Math.PI / 4, Width / (float)Height, 1.0f, 64.0f);
            GL.MatrixMode(MatrixMode.Projection);
            GL.LoadMatrix(ref projection);
        }

        private void glControl1_Paint(object sender, PaintEventArgs e)
        {
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);

            Matrix4 modelview = Matrix4.LookAt(Vector3.Zero, Vector3.UnitZ, Vector3.UnitY);
            GL.MatrixMode(MatrixMode.Modelview);
            GL.LoadMatrix(ref modelview);

            GL.Begin(BeginMode.Polygon);

            GL.Color3(1.0f, 0.0f, 0.0f); GL.Vertex3(1.0f, 1.0f, 4.0f);
            GL.Color3(0.0f, 1.0f, 0.0f); GL.Vertex3(1.0f, -1.0f, 4.0f);
            GL.Color3(0.0f, 0.0f, 1.0f); GL.Vertex3(-1.0f, -1.0f, 4.0f);
            GL.Color3(1.0f, 1.0f, 1.0f); GL.Vertex3(-1.0f, 1.0f, 4.0f);

            GL.End();
            glControl1.SwapBuffers();
        }


        /// <summary>
        /// Connects to the device from a device info
        /// </summary>
        /// <param name="aDI"></param>

        void Connect(PvDeviceInfo aDI)
        {
            // Just in case we came here still connected...
            Disconnect();

            try
            {
                // Connect to device using device info
                mDevice.Connect(aDI);

                // Open stream using device IP address
                mStream.Open(aDI.IPAddress);

                // Negotiate packet size
                mDevice.NegotiatePacketSize();

                // Set stream destination to our stream object
                mDevice.SetStreamDestination(mStream.LocalIPAddress, mStream.LocalPort);
            }
            catch (PvException ex)
            {
                // Failure at some point, display and abort
                MessageBox.Show(ex.Message);
                Disconnect();

                return;
            }

            if (mDevice.IsConnected)
            {
                mDevice.OnEventGenICam += new OnEventGenICam(mDevice_OnEventGenICam);

                // Register to all events of the parameters in the device's node map
                foreach (PvGenParameter lParameter in mDevice.GenParameters)
                {
                    lParameter.OnParameterUpdate += new OnParameterUpdateHandler(OnParameterChanged);
                }

                // Connect link disconnection handler
                mDevice.OnLinkDisconnected += new OnLinkDisconnectedHandler(OnLinkDisconnected);

                // Add device information
                manufacturerTextBox.Text = aDI.Vendor;
                modelTextBox.Text = aDI.Model;
                ipAddressTextBox.Text = aDI.IPAddress;
                macAddressTextBox.Text = aDI.MACAddress;
                nameTextBox.Text = aDI.UserDefinedName;

                if (aDI.UserDefinedName == "")
                {
                    nameTextBox.Text = "N/A";
                }
                else
                {
                    nameTextBox.Text = aDI.UserDefinedName;
                }

                // Fill acquisition mode combo box
                modeComboBox.Items.Clear();
                PvGenEnum lMode = mDevice.GenParameters.GetEnum("AcquisitionMode");
                if (lMode != null)
                {
                    foreach (PvGenEnumEntry lEntry in lMode)
                    {
                        if (lEntry.IsAvailable)
                        {
                            int lIndex = modeComboBox.Items.Add(lEntry.ValueString);
                            if (lEntry.ValueInt == lMode.ValueInt)
                            {
                                modeComboBox.SelectedIndex = lIndex;
                            }
                        }
                    }
                }
            }

            if (mStream.IsOpened)
            {
                // Ready image reception
                StartStreaming();
            }

            // Sync the UI with our new status
            EnableInterface();
        }

        void mDevice_OnEventGenICam(PvDevice aDevice, ushort aEventID, ushort aChannel, ulong aBlockID, ulong aTimestamp, List<PvGenParameter> aData)
        {
            string lLog = "Event ID: 0x" + aEventID.ToString("X4") + "\n";
            if (aData != null)
            {
                foreach (PvGenParameter p in aData)
                {
                    lLog += "\t" + p.Name + ": " + p.ToString() + "\n";
                }
            }

            Debug.WriteLine(lLog);
        }

        /// <summary>
        /// Disconnects from the device
        /// </summary>
        private void Disconnect()
        {
            // Close all configuration child windows
            mDeviceBrowser.Browser.GenParameterArray = null;
            CloseGenWindow(mDeviceBrowser);
            mStreamBrowser.Browser.GenParameterArray = null;
            CloseGenWindow(mStreamBrowser);

            // If streaming, stop streaming
            if (mStream.IsOpened)
            {
                StopStreaming();
                mStream.Close();
            }

            if (mDevice.IsConnected)
            {
                // Disconnect events
                mDevice.OnLinkDisconnected -= new OnLinkDisconnectedHandler(OnLinkDisconnected);
                foreach (PvGenParameter lP in mDevice.GenParameters)
                {
                    lP.OnParameterUpdate -= new OnParameterUpdateHandler(OnParameterChanged);
                }

                mDevice.Disconnect(); 
            }

            display.Clear();

            manufacturerTextBox.Text = "";
            modelTextBox.Text = "";
            ipAddressTextBox.Text = "";
            macAddressTextBox.Text = "";
            nameTextBox.Text = "";

            //statusControl.Warning = "";

            // Sync the UI with our new status
            EnableInterface();
        }

        /// <summary>
        /// GenICam parameter invalidation event, registered for all parameters
        /// </summary>
        /// <param name="aParameter"></param>
        void OnParameterChanged(PvGenParameter aParameter)
        {
            string lName = aParameter.Name;
            if (lName == "AcquisitionMode")
            {
                // Have main UI thread update the acquisition mode combo box status
                BeginInvoke(mAcquisitionModeChangedHandler);
            }
        }

        /// <summary>
        /// Acquisition mode event handler in main thread.
        /// </summary>
        private void OnAcquisitionModeChanged()
        {
            // Get parameter
            PvGenEnum lParameter = mDevice.GenParameters.GetEnum("AcquisitionMode");

            // Update value: find which matches in the combo box
            string lValue = lParameter.ValueString;
            foreach (string lString in modeComboBox.Items)
            {
                if (lValue == lString)
                {
                    modeComboBox.SelectedValue = lString;
                }
            }
        }

        /// <summary>
        /// Direct acquisition state changed handler. Bring back to main UI thread.
        /// </summary>
        /// <param name="aDevice"></param>
        /// <param name="aStream"></param>
        /// <param name="aSource"></param>
        /// <param name="aState"></param>
        void OnAcquisitionStateChanged(PvDevice aDevice, PvStreamBase aStream, uint aSource, PvAcquisitionState aState)
        {
            // Invoke event in main UI thread
            BeginInvoke(mAcquisitionStateChangedHandler);
        }
        
        /// <summary>
        /// OnAcquisitionStateChanged main UI thread counterpart. Syncs acquisition control status.
        /// </summary>
        private void OnAcquisitionStateChanged()
        {
            EnableControls();
        }

        /// <summary>
        /// Displays a GenICam browser form. If already visible, close it for toggle effect.
        /// </summary>
        /// <param name="aForm"></param>
        /// <param name="aParams"></param>
        /// <param name="aTitle"></param>
        private void ShowGenWindow(BrowserForm aForm, PvGenParameterArray aParams, string aTitle)
        {
            if (aForm.Visible)
            {
                CloseGenWindow(aForm);
                return;
            }

            // Create, assigne parameters, set title and show modeless
            aForm.Text = aTitle;
            aForm.Browser.GenParameterArray = aParams;
            aForm.Show();
        }

        /// <summary>
        /// Closes a GenICam browser form.
        /// </summary>
        /// <param name="aForm"></param>
        private void CloseGenWindow(Form aForm)
        {
            aForm.Hide();
        }

        /// <summary>
        /// Direct device disconnect handler. Just jump back to main UI thread.
        /// </summary>
        /// <param name="aDevice"></param>
        private void OnLinkDisconnected(PvDevice aDevice)
        {
            BeginInvoke(mDisconnectedHandler);
        }

        /// <summary>
        /// Reaction to device disconnected event: stop streaming, close device connection.
        /// </summary>
        private void OnDisconnected()
        {
            MessageBox.Show("Connection to device lost.", Text, 
                MessageBoxButtons.OK, MessageBoxIcon.Information);

            StopStreaming();
            Disconnect();
        }

        /// <summary>
        /// Setups streaming. After calling this method the application is ready to receive data.
        /// StartAcquisition will instruct the device to actually start sending data.
        /// </summary>
        private void StartStreaming()
        {
            // Configure status control
            //statusControl.Stream = mStream;
            //statusControl.DisplayThread = mDisplayThread;

            // Start threads
            mDisplayThread.Start(mPipeline, mDevice.GenParameters);
            mDisplayThread.Priority = PvThreadPriority.AboveNormal;

            // Configure acquisition state manager
            mAcquisitionManager = new PvAcquisitionStateManager(mDevice, mStream);
            mAcquisitionManager.OnAcquisitionStateChanged += new OnAcquisitionStateChanged(OnAcquisitionStateChanged);

            // Start pipeline
            mPipeline.Start();
        }

        /// <summary>
        /// Callback from display thread delegating buffer display task
        /// </summary>
        /// <param name="aDisplayThread">Display thread</param>
        /// <param name="aBuffer">Buffer to display</param>
        void OnBufferDisplay(PvDisplayThread aDisplayThread, PvBuffer aBuffer)
        {
            display.Display(aBuffer);
        }

        /// <summary>
        /// Stops streaming. After calling this method the application is no longer armed or ready
        /// to receive data.
        /// </summary>
        private void StopStreaming()
        {
            if (!mDisplayThread.IsRunning)
            {
                return;
            }

            // Stop display thread
            mDisplayThread.Stop(false);

            // Release acquisition manager
            mAcquisitionManager = null;

            // Stop pipeline
            if (mPipeline.IsStarted)
            {
                mPipeline.Stop();
            }

            // Wait on display thread
            mDisplayThread.WaitComplete();
        }

        /// <summary>
        /// Starts acquisition.
        /// </summary>
        private void StartAcquisition()
        {
            // Get payload size
            UInt32 lPayloadSize = PayloadSize;
            if (lPayloadSize > 0)
            {
                // Propagate to pipeline to make sure buffers are big enough
                mPipeline.BufferSize = lPayloadSize;
            }

            // Reset pipeline
            mPipeline.Reset();

            // Reset stream statistics
            PvGenCommand lResetStats = mStream.Parameters.GetCommand("Reset");
            lResetStats.Execute();

            // Reset display thread stats (mostly frames displayed per seconds)
            mDisplayThread.ResetStatistics();

            // Use acquisition manager to send the acquisition start command to the device
            mAcquisitionManager.Start();
        }

        /// <summary>
        /// Stops the acquisition.
        /// </summary>
        private void StopAcquisition()
        {
            // Use acquisition manager to send the acquisition stop command to the device
            mAcquisitionManager.Stop();
        }

        /// <summary>
        /// Retrieve or guess the payload size
        /// </summary>
        private UInt32 PayloadSize
        {
            get
            {
                // Get parameters required
                PvGenInteger lPayloadSize = mDevice.GenParameters.GetInteger("PayloadSize");
                PvGenInteger lWidth = mDevice.GenParameters.GetInteger("Width");
                PvGenInteger lHeight = mDevice.GenParameters.GetInteger("Height");
                PvGenEnum lPixelFormat = mDevice.GenParameters.GetEnum("PixelFormat");

                // Try getting the payload size from the PayloadSize mandatory parameter
                Int64 lPayloadSizeValue = 0;
                if (lPayloadSize != null)
                {
                    lPayloadSizeValue = lPayloadSize.Value;
                }

                // Compute poor man's payload size - for devices not maintaining PayloadSize properly
                Int64 lPoorMansPayloadSize = 0;
                if ((lWidth != null) && (lHeight != null) && (lPixelFormat != null))
                {
                    Int64 lWidthValue = lWidth.Value;
                    Int64 lHeightValue = lHeight.Value;

                    Int64 lPixelFormatValue = lPixelFormat.ValueInt;
                    Int64 lPixelSizeInBits = PvImage.GetPixelBitCount((PvPixelType)lPixelFormatValue);

                    lPoorMansPayloadSize = (lWidthValue * lHeightValue * lPixelSizeInBits) / 8;
                }

                // Take max
                Int64 lBestPayloadSize = Math.Max(lPayloadSizeValue, lPoorMansPayloadSize);
                if ((lBestPayloadSize > 0) && (lBestPayloadSize < UInt32.MaxValue))
                {
                    // Round up to make it mod 32 (works around an issue with some devices)
                    if ((lBestPayloadSize % 32) != 0)
                    {
                        lBestPayloadSize = ((lBestPayloadSize / 32) + 1) * 32;
                    }

                    return (UInt32)lBestPayloadSize;
                }

                // Could not compute/retrieve payload size...
                return 0;
            }
        }

        /// <summary>
        /// Communication button event handler. Display communication parameters browser form.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void communicationButton_Click(object sender, EventArgs e)
        {
            ShowGenWindow(mCommBrowser, mDevice.GenLink, "Communication Control");
        }

        /// <summary>
        /// Device button event handler. Display device parameters browser form.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void deviceButton_Click(object sender, EventArgs e)
        {
            ShowGenWindow(mDeviceBrowser, mDevice.GenParameters, "Device Control");
        }

        /// <summary>
        /// Stream button event handler. Display stream parameters browser form.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void streamButton_Click(object sender, EventArgs e)
        {
            ShowGenWindow(mStreamBrowser, mStream.Parameters, "Image Stream Control");
        }

        /// <summary>
        /// Acquisition mode combo box changed. Propagate to device.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void modeComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            // Nothing selected? Unexpected, just do nothing...
            if (modeComboBox.SelectedIndex < 0)
            {
                return;
            }

            PvGenEnum lMode = mDevice.GenParameters.GetEnum("AcquisitionMode");

            // Take selection, propagate to parameter
            string lSelected = (string)modeComboBox.SelectedItem;
            lMode.ValueString = lSelected;
        }

        /// <summary>
        /// Play button click handler. Start acquisition.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void playButton_Click(object sender, EventArgs e)
        {
            StartAcquisition();
        }

        /// <summary>
        /// Stop button click handler. Stop acquisition.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void stopButton_Click(object sender, EventArgs e)
        {
            StopAcquisition();
        }

        private void display_Load(object sender, EventArgs e)
        {

        }

        //multichat 
        void AppendText(Control ctrl, string s)
        {
            if (ctrl.InvokeRequired) ctrl.Invoke(_textAppender, ctrl, s);
            else
            {
                string source = ctrl.Text;
                ctrl.Text = source + Environment.NewLine + s;
            }
        }

        //주소로드
        void OnFormLoaded(object sender, EventArgs e)
        {
            
        }

        //서버연결
        void OnConnectToServer(object sender, EventArgs e)
        {
            Console.WriteLine("a");
            if (mainSock.Connected)
            {
                MsgBoxHelper.Error("이미 연결되어 있습니다!");
                return;
            }

            int port;
            if (!int.TryParse(txtPort.Text, out port))
            {
                MsgBoxHelper.Error("포트 번호가 잘못 입력되었거나 입력되지 않았습니다.");
                txtPort.Focus();
                txtPort.SelectAll();
                return;
            }

            try { mainSock.Connect(txtAddress.Text, port); }
            catch (Exception ex)
            {
                MsgBoxHelper.Error("연결에 실패했습니다!\n오류 내용: {0}", MessageBoxButtons.OK, ex.Message);
                return;
            }

            // 연결 완료되었다는 메세지를 띄워준다.
            AppendText(txtHistory, "서버와 연결되었습니다.");

            // 연결 완료, 서버에서 데이터가 올 수 있으므로 수신 대기한다.
            AsyncObject obj = new AsyncObject(16);
            obj.WorkingSocket = mainSock;
            mainSock.BeginReceive(obj.Buffer, 0, obj.BufferSize, 0, DataReceived, obj);
        }
        //데이터받기
        void DataReceived(IAsyncResult ar)
        {
            // BeginReceive에서 추가적으로 넘어온 데이터를 AsyncObject 형식으로 변환한다.
            AsyncObject obj = (AsyncObject)ar.AsyncState;

            // 데이터 수신을 끝낸다.
            int received = obj.WorkingSocket.EndReceive(ar);

            // 받은 데이터가 없으면(연결끊어짐) 끝낸다.
            if (received <= 0)
            {
                obj.WorkingSocket.Close();
                return;
            }

            if (obj.Buffer[2] != 86 && obj.Buffer[3] != 83)
            {
                move_receive[0] = obj.Buffer[2];
                move_receive[1] = obj.Buffer[3]; //Position 2바이트때 사용
            }

            // 텍스트로 변환한다.
            string msg1 = Encoding.ASCII.GetString(obj.Buffer);

            //ASCII to hex변환
            char[] array = msg1.ToCharArray();
            string text = "";
            foreach (var i in array)
            {
                string hex = String.Format("{0:X}", Convert.ToInt32(i));
                text += hex.Insert(0, "") + " ";
            }
            text = text.TrimEnd();

            //변환된 메세지
            string msg = text;

            // 텍스트박스에 추가해준다.
            AppendText(txtHistory, string.Format(msg));

            // 데이터를 받은 후엔 다시 버퍼를 비워주고 같은 방법으로 수신을 대기한다.
            obj.ClearBuffer();

            // 수신 대기
            obj.WorkingSocket.BeginReceive(obj.Buffer, 0, 16, 0, DataReceived, obj);
        }

        void OnSendData(object sender, EventArgs e)
        {
            if (!mainSock.IsBound)
            {
                MsgBoxHelper.Warn("서버가 실행되고 있지 않습니다!");
                return;
            }


            string tts = txtTTS.Text.Trim(); // 보낼 텍스트
            if (string.IsNullOrEmpty(tts))
            {
                MsgBoxHelper.Warn("텍스트가 입력되지 않았습니다!");
                txtTTS.Focus();
                return;
            }

            // 서버 ip 주소와 메세지를 담도록 만든다.
            IPEndPoint ip = (IPEndPoint)mainSock.LocalEndPoint;
            string addr = ip.Address.ToString();

            //head_format 초기 선언
            protocal.Head_head_format();

            // datasize 8의배수 계산
            UInt16 ttx_size = (UInt16)((((tts.Length - 1) / 8) + 1) * 8);

            //텍스트 사이즈를 dataSize에 넣음
            protocal.dataSize_byte = BitConverter.GetBytes(ttx_size);

            // head_format를 byteArray로 변환
            protocal.Make_ByteArray();


            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] byteArray_rcv = protocal.byteArray;
            byte[] tts_rcv = Encoding.UTF8.GetBytes(tts);
            byte[] bDts = new byte[tts_rcv.Length + byteArray_rcv.Length];
            System.Buffer.BlockCopy(byteArray_rcv, 0, bDts, 0, byteArray_rcv.Length);
            System.Buffer.BlockCopy(tts_rcv, 0, bDts, byteArray_rcv.Length, tts_rcv.Length);

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.

            txtSTT.Clear();
            AppendText(txtSTT, string.Format("[보냄]{0}: {1}", addr, tts));
            txtTTS.Clear();
        }

        private byte[] move() //move 초기화 , byte[] result로 만들기
        {
            protocal.initMove();
            //protocal.Position_byte = move_receive;


            if (radioButton1.Checked)
            {
                //예외처리 예정
                Int16 value = Convert.ToInt16(textBox2.Text);
                int add = value + BitConverter.ToUInt16(move_receive, 0);
                byte[] write = BitConverter.GetBytes((UInt16)add);
                protocal.Position_byte = write;
            }

            else if (radioButton2.Checked)
            {
                UInt16 value = Convert.ToUInt16(textBox2.Text);
                byte[] write = BitConverter.GetBytes(value);
                protocal.Position_byte = write;
            }

            byte[] result = protocal.Position_byteArray;
            System.Buffer.BlockCopy(protocal.Reservem0_byte, 0, result, 0, protocal.Reservem0_byte.Length);
            System.Buffer.BlockCopy(protocal.Position_byte, 0, result, 2, protocal.Position_byte.Length);
            System.Buffer.BlockCopy(protocal.Reservem1_byte, 0, result, 4, protocal.Reservem0_byte.Length);
            return result;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Head_head_format();
            protocal.Make_ByteArray();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("header 보냄"));
            txtTTS.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Head_keepAlive();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("keepAlive 보냄"));
            txtTTS.Clear();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Head_Req_status();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("Req_status 보냄"));
            txtTTS.Clear();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Head_Homing();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("Homing 보냄"));
            txtTTS.Clear();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Head_Move();
            byte[] move_data = move();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);
            mainSock.Send(move_data);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("Move 보냄"));
            txtTTS.Clear();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Head_Alarm();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("Alarm 보냄"));
            txtTTS.Clear();
        }

        private void txtHistory_TextChanged(object sender, EventArgs e)
        {
            txtHistory.SelectionStart = txtHistory.TextLength;
            txtHistory.ScrollToCaret();
        }

        private void Form_Closing(object sender, FormClosingEventArgs e)
        {
            try
            {
                mainSock.Disconnect(true);
            }
            catch
            {

            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Head_Req_status();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("Req_status 보냄"));
            txtTTS.Clear();


            textBox1.Text = BitConverter.ToUInt16(move_receive, 0).ToString();
        }
    }
}

