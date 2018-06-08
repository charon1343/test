//#define AUTO_ADDRESS

using System;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;
using System.Text;
using System.IO;

using Sentech.StApiDotNET;
using System.Runtime.InteropServices;

using System.Net;
using System.Net.Sockets;

using OpenTK;
using OpenTK.Graphics.OpenGL;

namespace Autopocusing
{
    enum AFMsg
    {
        Msg_KeepAlive = 0,
        Msg_ReqStatus = 10,
        Msg_Homing = 50,
        Msg_HomingDone = 51,
        Msg_Move = 60,
        Msg_MoveDone = 61,
        Msg_Alarm = 255,

    }
    public partial class Form1 : Form
    {
        //image header
        IStImage stImage;
        Bitmap map;

        CStApiAutoInit api;
        CStSystem system;
        CStDevice device;
        CStDataStream dataStream;

        Thread Image_thread;
        delegate void Image_Delegate();
        bool threadStop;
        bool threadisrun;

        //multichat header
        //delegate void OtherThread(Control ctrl);
        delegate void AppendTextDelegate(Control ctrl, string s);
        AppendTextDelegate _textAppender;

        Socket mainSock;

        static byte[] socket_ReceiveData;
        //public byte[] position = new byte[2];

        Protocal protocal = new Protocal();

        public Form1()
        {
            InitializeComponent();
        }


        //image function
        //callback function continuously image making
        public void OnCallback(IStCallbackParamBase paramBase, object[] param)
        {
            if (paramBase.CallbackType == eStCallbackType.TL_DataStreamNewBuffer)
            {
                IStCallbackParamGenTLEventNewBuffer callbackParam = paramBase as IStCallbackParamGenTLEventNewBuffer;

                if (callbackParam != null)
                {
                    IStDataStream dataStream = callbackParam.GetIStDataStream();

                    using (CStStreamBuffer streamBuffer = dataStream.RetrieveBuffer(0))

                    {

                        if (streamBuffer.GetIStStreamBufferInfo().IsImagePresent)
                        {

                            stImage = streamBuffer.GetIStImage();

                            byte[] imageData = stImage.GetByteArray();

                            map = new Bitmap((int)stImage.ImageWidth, (int)stImage.ImageHeight, (int)stImage.ImageWidth, System.Drawing.Imaging.PixelFormat.Format24bppRgb, Marshal.UnsafeAddrOfPinnedArrayElement(stImage.GetByteArray(), 0));
                        }
                    }
                }
            }
        }

        //image ready callback
        public void Image_Init()
        {

            api = new CStApiAutoInit();
            system = new CStSystem(eStSystemVendor.Sentech);
            device = system.CreateFirstStDevice();
            dataStream = device.CreateStDataStream(0);

            dataStream.RegisterCallbackMethod(OnCallback);
        }

        //callback start
        public void Image_Start()
        {
            dataStream.StartAcquisition();

            device.AcquisitionStart();
        }

        //callback stop
        public void Image_Stop()
        {
            if (device != null&& threadisrun)   //미접속 및 2중dispose 방지
            {
                device.AcquisitionStop();
                
                dataStream.StopAcquisition();
            }

        }

        //callback drop
        public void Image_Dispose()
        {
            if (dataStream != null)
            {
                dataStream.Dispose();
                device.Dispose();
                system.Dispose();
                api.Dispose();
            }
        }

        //thread function
        private void Image_ThreadFunction()
        {
            pictureBox1.Image = map;
        }

        //thread delegate
        private void Image_myThread()
        {
            while (true)
            {
                if (threadStop == false)
                {
                    this.Invoke(new Image_Delegate(Image_ThreadFunction));
                    threadisrun = true;
                }
                else
                    break;
            }
            Image_thread.Abort();
        }

        //multichat function
        void AppendText(Control ctrl, string s)
        {
            if (ctrl.InvokeRequired) ctrl.Invoke(_textAppender, ctrl, s);
            else
            {
                string source = ctrl.Text;
                ctrl.Text = source + Environment.NewLine + s;
            }
        }
        //socket_recieve_try1(current_Position,BitConverter.ToUInt16(protocal.Position_byte, 0).ToString());
        //void txtSTTClear(Control ctrl) //thread 예외처리
        //{
        //    if (ctrl.InvokeRequired)
        //    {
        //        ctrl.Invoke(new OtherThread(txtSTTClear), ctrl);
        //        txtSTT.Clear();
        //    }
        //    else
        //    {
        //        txtSTT.Clear();
        //    }

        //}

        //주소로드
        void OnFormLoaded(object sender, EventArgs e)
        {
#if AUTO_ADDRESS
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

#endif
            //button select
            Button_InitImage();
            Button_InitMgs();

        }

        //서버연결
        void OnConnectToServer(object sender, EventArgs e)
        {
            OnServer();
        }
        void OnServer()
        {
            mainSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
            _textAppender = new AppendTextDelegate(AppendText);
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
            AppendText(txtHistory, "서버와 연결되었습니다.");



            AsyncObject obj = new AsyncObject(32);
            obj.WorkingSocket = mainSock;
            mainSock.BeginReceive(obj.Buffer, 0, obj.BufferSize, 0, DataReceived, obj);

            Button_Connect();
        }


        //데이터받기
        void DataReceived(IAsyncResult ar)
        {
            AsyncObject obj = (AsyncObject)ar.AsyncState;

            int received = obj.WorkingSocket.EndReceive(ar);

            if (received <= 0)
            {
                obj.WorkingSocket.Close();
                return;
            }

            socket_ReceiveData = obj.Buffer; //받은 데이터 사용

            // 텍스트로 변환한다.
            string socket_ASCII = Encoding.UTF7.GetString(obj.Buffer);


            //ASCII to hex변환된 메세지
            string socket_Hex = ASCIIToHex(socket_ASCII);

            // 텍스트박스에 추가해준다. 로그로 대체
            //AppendText(txtHistory, string.Format(socket_Hex));

            using (StreamWriter w = File.AppendText("log.txt"))
            {
                Log(socket_Hex, w);
            }
            if (socket_ReceiveData[0] == 77)
                switch (socket_ReceiveData[8])
                {
                    case (int)AFMsg.Msg_KeepAlive:
                        AppendText(txtHistory, string.Format("KeepAlive받음"));
                        break;
                    case (int)AFMsg.Msg_ReqStatus:
                        AppendText(txtHistory, string.Format("ReqStatus받음"));
                        protocal.Position_byte[0] = socket_ReceiveData[10];
                        protocal.Position_byte[1] = socket_ReceiveData[11];
                        break;
                    case (int)AFMsg.Msg_Homing:
                        AppendText(txtHistory, string.Format("Homing받음"));
                        break;
                    case (int)AFMsg.Msg_HomingDone:
                        AppendText(txtHistory, string.Format("HomingDone받음"));
                        break;
                    case (int)AFMsg.Msg_Move:
                        AppendText(txtHistory, string.Format("Move받음"));
                        break;
                    case (int)AFMsg.Msg_MoveDone:
                        AppendText(txtHistory, string.Format("MoveDone받음"));
                        protocal.Position_byte[0] = socket_ReceiveData[10];
                        protocal.Position_byte[1] = socket_ReceiveData[11];
                        break;
                    case (int)AFMsg.Msg_Alarm:
                        AppendText(txtHistory, string.Format("Alarm받음"));
                        break;
                    case 11:
                        AppendText(txtHistory, string.Format("Miss ReqStatus받음"));
                            protocal.Position_byte[0] = socket_ReceiveData[10];
                            protocal.Position_byte[1] = socket_ReceiveData[11];
                        break;
                    default:
                        AppendText(txtHistory, string.Format("default"));
                        break;
                }
            else
            {

            }
            // 데이터를 받은 후엔 다시 버퍼를 비워주고 같은 방법으로 수신을 대기한다.
            obj.ClearBuffer();

            // 수신 대기
            obj.WorkingSocket.BeginReceive(obj.Buffer, 0, 32, 0, DataReceived, obj);


        }
        

        //아스키코드 to Hex
        string ASCIIToHex(string msg1)
        {
            char[] array = msg1.ToCharArray();
            string text = "";
            foreach (var i in array)
            {
                string hex = String.Format("{0:X}", Convert.ToInt32(i));
                text += hex.Insert(0, "") + " ";
            }
            text = text.TrimEnd();
            return text;
        }




        //데이터 보내기
        void OnSendData(object sender, EventArgs e)
        {
            if (!mainSock.IsBound)
            {
                MsgBoxHelper.Warn("서버가 실행되고 있지 않습니다!");
                return;
            }


            string tts = txtTTS.Text.Trim();    //메세지 내용
            if (string.IsNullOrEmpty(tts))
            {
                MsgBoxHelper.Warn("텍스트가 입력되지 않았습니다!");
                txtTTS.Focus();
                return;
            }

            // 서버 ip 주소와 메세지를 담도록 만든다.
            IPEndPoint ip = (IPEndPoint)mainSock.LocalEndPoint;

            //헤더만들기
            socket_HeadFormat();

            // 해더와 텍스트를 붙인다
            byte[] socket_DataSend = socket_HeaderPlusText(tts);
            // 서버에 전송한다.
            mainSock.Send(socket_DataSend);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            txtSTT.Clear();
            AppendText(txtHistory, string.Format("[보냄]:{0}", tts));
            txtTTS.Clear();
        }

        //헤더만들기
        void socket_HeadFormat()
        {
            //head_format 초기 선언
            protocal.Head_head_format();

            //datasize 8의배수로 맞춤
            socket_DatasizeChange(txtTTS.Text.Trim());

            // head_format를 byteArray로 변환
            protocal.header_Make_ByteArray();
        }

        //datasize 8의배수로 맞춤
        void socket_DatasizeChange(string tts)
        {
            // datasize 8의배수 계산
            UInt16 ttx_size = (UInt16)((((tts.Length - 1) / 8) + 1) * 8);

            //텍스트 사이즈를 dataSize에 넣음
            protocal.dataSize_byte = BitConverter.GetBytes(ttx_size);
        }

        //해더와 데이터 합치기
        byte[] socket_HeaderPlusText(string tts)
        {
            byte[] headerByte = protocal.byteArray;
            byte[] ttsByte = Encoding.UTF8.GetBytes(tts);
            byte[] socket_SendData = new byte[ttsByte.Length + headerByte.Length];
            System.Buffer.BlockCopy(headerByte, 0, socket_SendData, 0, headerByte.Length);
            System.Buffer.BlockCopy(ttsByte, 0, socket_SendData, headerByte.Length, ttsByte.Length);
            return socket_SendData;
        }

        //head_format function
        void head_format()
        {
            protocal.Head_head_format();
            byte[] socket_SendData = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(socket_SendData);


            if (txtSTT.Text != "")
                txtSTT.Clear();
            AppendText(txtSTT, string.Format("header 보냄"));
        }

        //keep_alive function
        void keep_alive()
        {
            protocal.Head_keepAlive();
            byte[] socket_SendData = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(socket_SendData);

            if (txtSTT.Text != "")
                txtSTT.Clear();
            AppendText(txtSTT, string.Format("keepAlive 보냄"));
        }

        void req_status()
        {
            protocal.Head_Req_status();
            byte[] socket_SendData = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(socket_SendData);


            if (txtSTT.Text != "")
                txtSTT.Clear();
            AppendText(txtSTT, string.Format("Req_status 보냄"));
        }

        void homing()
        {
            protocal.Head_Homing();
            byte[] socket_SendData = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(socket_SendData);

            protocal.Position_byte[0] = 0;
            protocal.Position_byte[1] = 0;

            current_Position.Text = BitConverter.ToUInt16(protocal.Position_byte, 0).ToString();    //이동위치 출력

            if (txtSTT.Text != "")
                txtSTT.Clear();
            AppendText(txtSTT, string.Format("Homing 보냄"));
        }

        void move()
        {
            byte[] socket_MoveData;
            protocal.Head_Move();
            protocal.move_Position();
            textmovedata();
            makemovedata();
            socket_MoveData = headerplusmovedata();

            mainSock.Send(socket_MoveData);

            current_Position.Text = BitConverter.ToUInt16(protocal.Position_byte, 0).ToString();    //이동위치 출력

            if (txtSTT.Text != "")
                txtSTT.Clear();
            AppendText(txtSTT, string.Format("Move 보냄"));

        }
        //text를 position에 입력
        void textmovedata()
        {
            UInt16 value = Convert.ToUInt16(chang_Position.Text);
            byte[] write = BitConverter.GetBytes(value);
            protocal.Position_byte = write;
        }

        //movedata 만들기
        void makemovedata()
        {
            byte[] result = new byte[protocal.Reserve_m0_byte.Length + protocal.Position_byte.Length + protocal.Reserve_m0_byte.Length];
            System.Buffer.BlockCopy(protocal.Reserve_m0_byte, 0, result, 0, protocal.Reserve_m0_byte.Length);
            System.Buffer.BlockCopy(protocal.Position_byte, 0, result, 2, protocal.Position_byte.Length);
            System.Buffer.BlockCopy(protocal.Reserve_m1_byte, 0, result, 4, protocal.Reserve_m0_byte.Length);
            System.Buffer.BlockCopy(result, 0, protocal.move_byteArray, 0, result.Length);
        }

        //header와 movedata 합치기
        byte[] headerplusmovedata()
        {
            byte[] result = new byte[protocal.byteArray.Length + protocal.move_byteArray.Length];
            System.Buffer.BlockCopy(protocal.byteArray, 0, result, 0, protocal.byteArray.Length);
            System.Buffer.BlockCopy(protocal.move_byteArray, 0, result, protocal.byteArray.Length, protocal.move_byteArray.Length);
            return result;
        }

        void move_forwardstep()
        {
            {
                byte[] headermovedata;
                protocal.Head_Move();
                protocal.move_Position();
                protocal.Position_byte[0] = socket_ReceiveData[18];
                protocal.Position_byte[1] = socket_ReceiveData[19];
                UInt16 Int_Position = BitConverter.ToUInt16(protocal.Position_byte, 0);
                if (micro.Checked)
                    Int_Position += 20;                                     //원스텝
                else
                    Int_Position += 200;                                     //원스텝
                protocal.Position_byte = protocal.GetBytesUInt16(Int_Position);
                makemovedata();
                headermovedata = headerplusmovedata();
                mainSock.Send(headermovedata);

                current_Position.Text = BitConverter.ToUInt16(protocal.Position_byte, 0).ToString();    //이동위치 출력

                if (txtSTT.Text != "")
                    txtSTT.Clear();
                AppendText(txtSTT, string.Format("onestep 보냄"));
            }
        }

        void move_backstep()
        {
            byte[] headermovedata;
            protocal.Head_Move();
            protocal.move_Position();
            protocal.Position_byte[0] = socket_ReceiveData[18];
            protocal.Position_byte[1] = socket_ReceiveData[19];
            UInt16 Int_Position = BitConverter.ToUInt16(protocal.Position_byte, 0);
            if(Int_Position<20)
                AppendText(txtHistory, string.Format("음수값을 가질수 없습니다"));
            else {
                if (micro.Checked)
                    Int_Position -= 20;                                     //원스텝
                else
                    Int_Position -= 200;                                     //원스텝
            }
            protocal.Position_byte = protocal.GetBytesUInt16(Int_Position);
            makemovedata();
            headermovedata = headerplusmovedata();
            mainSock.Send(headermovedata);

            current_Position.Text = BitConverter.ToUInt16(protocal.Position_byte, 0).ToString();    //이동위치 출력

            if (txtSTT.Text != "")
                txtSTT.Clear();
            AppendText(txtSTT, string.Format("backstep 보냄"));
        }

        void alarm()
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

        //로그
        public static void Log(string logMessage, TextWriter w)
        {
            w.Write("\r\nLog Entry : ");
            w.WriteLine("{0} {1}", DateTime.Now.ToLongDateString(), DateTime.Now.ToLongTimeString());
            w.WriteLine("  {0}", logMessage);
            w.WriteLine("---------------------------------------------------------------");
        }


        //opengl function
        private void glControl1_Load(object sender, EventArgs e)
        {
            GL.ClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // 배경색 alpha는 투명도
            GL.Enable(EnableCap.DepthTest);
            //timer2.Interval = 1;
            //timer2.Enabled = true;
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
            //Console.WriteLine("drawing...");
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);

            Matrix4 modelview = Matrix4.LookAt(Vector3.Zero, Vector3.UnitZ, Vector3.UnitY);
            GL.MatrixMode(MatrixMode.Modelview);
            GL.LoadMatrix(ref modelview);

            GL.Begin(BeginMode.Triangles);

            GL.Color3(1.0f, 0.0f, 0.0f); GL.Vertex3(1.0f, 1.0f, 4.0f);
            GL.Color3(0.0f, 1.0f, 0.0f); GL.Vertex3(1.0f, -1.0f, 4.0f);
            GL.Color3(0.0f, 0.0f, 1.0f); GL.Vertex3(-1.0f, -1.0f, 4.0f);
            GL.Color3(1.0f, 1.0f, 1.0f); GL.Vertex3(-1.0f, 1.0f, 4.0f);

            GL.End();
            glControl1.SwapBuffers();
        }

        //button function
        public void Button_InitImage()
        {
            init_btn.Enabled = true;
            start_btn.Enabled = false;
            live_btn.Enabled = false;
            capture_btn.Enabled = false;
            live_stop_btn.Enabled = false;
            stop_btn.Enabled = false;
        }

        public void initable()
        {
            start_btn.Enabled = true;
            init_btn.Enabled = false;
            auto_btn.Enabled = false;
        }
        public void startable()
        {
            live_btn.Enabled = true;
            capture_btn.Enabled = true;
            start_btn.Enabled = false;
            stop_btn.Enabled = true;
        }
        public void liveable()
        {
            capture_btn.Enabled = false;
            live_stop_btn.Enabled = true;
            live_btn.Enabled = false;
        }
        public void livestopable()
        {
            capture_btn.Enabled = true;
            live_btn.Enabled = true;
            live_stop_btn.Enabled = false;
        }

        public void Button_InitMgs()
        {
            btnConnect.Enabled = true;
            close_btn.Enabled = false;
            btnSend.Enabled = false;
            head_format_btn.Enabled = false;
            keep_alive_btn.Enabled = false;
            req_status_btn.Enabled = false;
            homing_btn.Enabled = false;
            move_btn.Enabled = false;
            alarm_btn.Enabled = false;
            forwardstep.Enabled = false;
            backstep.Enabled = false;
            chang_Position.Enabled = false;

        }
        public void Button_Connect()
        {
            btnConnect.Enabled = false;
            close_btn.Enabled = true;
            btnSend.Enabled = true;
            homing_btn.Enabled = true;
        }

        public void homingable()
        {
            head_format_btn.Enabled = true;
            keep_alive_btn.Enabled = true;
            req_status_btn.Enabled = true;
            alarm_btn.Enabled = true;
            chang_Position.Enabled = true;
            move_btn.Enabled = true;
            forwardstep.Enabled = true;
            backstep.Enabled = true;
        }

        public void closeable()
        {
        }
        //image designe
        private void init_btn_Click(object sender, EventArgs e)
        {
            initable();
            Image_Init();
        }

        private void start_btn_Click(object sender, EventArgs e)
        {
            startable();
            Image_Start();
        }

        private void live_btn_Click(object sender, EventArgs e)
        {
            liveable();
            threadStop = false;
            Image_thread = new Thread(new ThreadStart(Image_myThread));
            Image_thread.Start();
        }

        private void capture_btn_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = map;
        }

        private void stop_btn_Click(object sender, EventArgs e)
        {
            Button_InitImage();
            threadStop = true;
            if (threadisrun == true)
            {
                Image_thread.Abort();
                threadisrun = false;
            }
            Image_Stop();
            Image_Dispose();
        }

        private void live_stop_btn_Click(object sender, EventArgs e)
        {
            livestopable();
            Image_thread.Abort();
        }

        private void pictureBox1_Click_1(object sender, EventArgs e)
        {

        }

        //multichat design
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (mainSock != null && mainSock.Connected == true)
                mainSock.Disconnect(false);
            Button_InitImage();
            threadStop = true;
            if (threadisrun == true)
            {
                Image_thread.Abort();
                threadisrun = false;
            }
            Image_Stop();
            Image_Dispose();

        }

        private void txtHistory_TextChanged(object sender, EventArgs e)
        {
            txtHistory.SelectionStart = txtHistory.TextLength;
            txtHistory.ScrollToCaret();
        }

        private void head_format_btn_Click(object sender, EventArgs e)
        {
            head_format();
        }

        private void keep_alive_btn_Click(object sender, EventArgs e)
        {
            keep_alive();
        }

        private void req_status_btn_Click(object sender, EventArgs e)
        {
            req_status();

        }

        private void homing_btn_Click(object sender, EventArgs e)
        {
            homingable();
            homing();
        }

        private void move_btn_Click(object sender, EventArgs e)
        {
            req_status();
            System.Threading.Thread.Sleep(1000);    //bad TCP 방지
            move();
        }

        private void alarm_btn_Click(object sender, EventArgs e)
        {
            alarm();
        }
        

        private void current_Position_TextChanged(object sender, EventArgs e)
        {


        }

        private void chang_Position_TextChanged(object sender, EventArgs e)
        {

        }

        private void forwardstep_Click(object sender, EventArgs e)
        {
            req_status();
            System.Threading.Thread.Sleep(1000);    //bad TCP 방지
            move_forwardstep();

        }


        private void backstep_Click(object sender, EventArgs e)
        {
            req_status();
            System.Threading.Thread.Sleep(1000);    //bad TCP 방지
            move_backstep();
        }

        private void close_btn_Click(object sender, EventArgs e)
        {
            Button_InitMgs();
            mainSock.Disconnect(false);
            Button_InitImage();
            threadStop = true;
            Image_Stop();
            Image_Dispose();

        }

        private void auto_btn_Click(object sender, EventArgs e)
        {
            OnServer();
            System.Threading.Thread.Sleep(1000);
            Image_Init();
            System.Threading.Thread.Sleep(1000);
            Image_Start();
            System.Threading.Thread.Sleep(1000);
            liveable();
            threadStop = false;
            Image_thread = new Thread(new ThreadStart(Image_myThread));
            Image_thread.Start();
            System.Threading.Thread.Sleep(3000);
            {//homing 버튼
                homingable();
                homing();
            }
            init_btn.Enabled = false;
            stop_btn.Enabled = true;
            auto_btn.Enabled = false;
        }

        private void txtAddress_TextChanged(object sender, EventArgs e)
        {

        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            glControl1.SwapBuffers();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //timer2.Dispose();
        }
    }
}