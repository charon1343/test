//#define AUTO_ADDRESS_MSG

using System;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;
using System.Text;
using System.IO;

using Sentech.StApiDotNET;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;

using System.Net;
using System.Net.Sockets;

using OpenTK;
using OpenTK.Graphics.OpenGL;

namespace Autopocusing
{
    public partial class Form1 : Form
    {
        //image header
        IStImage stImage;
        Bitmap map;
        bool stop = false;

        CStApiAutoInit api;
        CStSystem system;
        CStDevice device;
        CStDataStream dataStream;

        Thread th2;
        private delegate void myDelegate2();

        //multichat header
        delegate void AppendTextDelegate(Control ctrl, string s);
        AppendTextDelegate _textAppender;
        public Socket mainSock;
        bool isconnect;

        Protocal protocal = new Protocal(); //프로토콜 선언
        public byte[] receive_data;                //수신데이터 불안정한지 확인필요
        public byte[] position = new byte[2];      //임시
        
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

                            map = new Bitmap((int)stImage.ImageWidth, (int)stImage.ImageHeight,(int)stImage.ImageWidth, System.Drawing.Imaging.PixelFormat.Format24bppRgb, Marshal.UnsafeAddrOfPinnedArrayElement(stImage.GetByteArray(), 0));
                        }
                    }
                }
            }
        }

        //image ready callback
        public void image_init()
        {
            api = new CStApiAutoInit();
            system = new CStSystem(eStSystemVendor.Sentech);
            device = system.CreateFirstStDevice();
            dataStream = device.CreateStDataStream(0);

            dataStream.RegisterCallbackMethod(OnCallback);
        }

       //callback start
        public void start()
        {
            dataStream.StartAcquisition();

            device.AcquisitionStart();
        }

        //callback stop
        public void stop1()
        {

            device.AcquisitionStop();

            dataStream.StopAcquisition();


        }

        //callback drop
        public void dispose()
        {
            dataStream.Dispose();
            device.Dispose();
            system.Dispose();
            api.Dispose();
        }

        //thread function
        private void updateProgress2()
        {
            pictureBox1.Image = map;
        }

        //thread delegate
        private void myThread2()
        {
            while (true)
            {
                if (stop == false)
                    this.Invoke(new myDelegate2(updateProgress2));
                else
                    break;
            }
            th2.Abort();
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

            initbutton();
            initmgsbutton();

        }

        void onserver()
        {
            mainSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);  //재연결에 사용
            _textAppender = new AppendTextDelegate(AppendText); //재연결에 사용

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



            AsyncObject obj = new AsyncObject(16);
            obj.WorkingSocket = mainSock;
            mainSock.BeginReceive(obj.Buffer, 0, obj.BufferSize, 0, DataReceived, obj);

            connectable();
        }
        //서버연결
        void OnConnectToServer(object sender, EventArgs e)
        {
            onserver();
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

            receive_data = obj.Buffer; //받은 데이터 사용
            // 텍스트로 변환한다.
            string msg1 = Encoding.UTF7.GetString(obj.Buffer);


            //ASCII to hex변환된 메세지
            string msg = ASCIIToHex(msg1);

            // 텍스트박스에 추가해준다. 로그로 대체
            //AppendText(txtHistory, string.Format(msg));

            using (StreamWriter w = File.AppendText("log.txt"))
            {
                Log(msg, w);
            }

            // 데이터를 받은 후엔 다시 버퍼를 비워주고 같은 방법으로 수신을 대기한다.
            obj.ClearBuffer();

            // 수신 대기
            obj.WorkingSocket.BeginReceive(obj.Buffer, 0, 16, 0, DataReceived, obj);
            //임시
            if (obj.Buffer[1] == 1)
            {
                position[0] = receive_data[2];
                position[1] = receive_data[3]; //Position 2바이트때 사용
                protocal.Position_byte = position;
                current_Position.Text = BitConverter.ToUInt16(protocal.Position_byte, 0).ToString();
                //position_clickable();
            }

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


            string tts = txtTTS.Text.Trim();
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

            //datasize 8의배수로 맞춤
            datasize_change(tts);

            // head_format를 byteArray로 변환
            protocal.header_Make_ByteArray();

            // 해더와 텍스트를 붙인다
            byte[] bDts = headerplugtext(tts);
            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            txtSTT.Clear();
            AppendText(txtSTT, string.Format("[보냄]{0}: {1}", addr, tts));
            txtTTS.Clear();
        }

        //datasize 8의배수로 맞춤
        void datasize_change(string tts)
        {
            // datasize 8의배수 계산
            UInt16 ttx_size = (UInt16)((((tts.Length - 1) / 8) + 1) * 8);

            //텍스트 사이즈를 dataSize에 넣음
            protocal.dataSize_byte = BitConverter.GetBytes(ttx_size);
        }

        //해더와 데이터 합치기
        byte[] headerplugtext(string tts)
        {
            byte[] byteArray_rcv = protocal.byteArray;
            byte[] tts_rcv = Encoding.UTF8.GetBytes(tts);
            byte[] bDts = new byte[tts_rcv.Length + byteArray_rcv.Length];
            System.Buffer.BlockCopy(byteArray_rcv, 0, bDts, 0, byteArray_rcv.Length);
            System.Buffer.BlockCopy(tts_rcv, 0, bDts, byteArray_rcv.Length, tts_rcv.Length);
            return bDts;
        }

        //head_format function
        void head_format()
        {
            txtSTT.Clear();
            protocal.Head_head_format();
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            AppendText(txtSTT, string.Format("header 보냄"));
            txtTTS.Clear();
        }

        //keep_alive function
        void keep_alive()
        {
            txtSTT.Clear();
            protocal.Head_keepAlive();
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            AppendText(txtSTT, string.Format("keepAlive 보냄"));
            txtTTS.Clear();
        }

        void req_status()
        {
            txtSTT.Clear();
            protocal.Head_Req_status();
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            AppendText(txtSTT, string.Format("Req_status 보냄"));
            txtTTS.Clear();
        }

        void homing()
        {
            txtSTT.Clear();
            protocal.Head_Homing();
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            AppendText(txtSTT, string.Format("Homing 보냄"));
            txtTTS.Clear();
        }

        void move()
        {
            req_status();

            byte[] headermovedata;
            txtSTT.Clear();
            protocal.Head_Move();
            protocal.move_Position();
            textmovedata();
            makemovedata();
            headermovedata = headerplusmovedata();

            mainSock.Send(headermovedata);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("Move 보냄"));
            txtTTS.Clear();

            current_Position.Text = BitConverter.ToUInt16(protocal.Position_byte, 0).ToString();
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
            byte[] result = new byte[protocal.Reserve_m0_byte.Length+ protocal.Position_byte.Length+ protocal.Reserve_m0_byte.Length];
            System.Buffer.BlockCopy(protocal.Reserve_m0_byte, 0, result, 0, protocal.Reserve_m0_byte.Length);
            System.Buffer.BlockCopy(protocal.Position_byte, 0, result, 2, protocal.Position_byte.Length);
            System.Buffer.BlockCopy(protocal.Reserve_m1_byte, 0, result, 4, protocal.Reserve_m0_byte.Length);
            System.Buffer.BlockCopy(result, 0, protocal.move_byteArray, 0, result.Length);
        }

        //header와 movedata 합치기
        byte[] headerplusmovedata()
        {
            byte[] result = new byte[protocal.byteArray.Length+ protocal.move_byteArray.Length];
            System.Buffer.BlockCopy(protocal.byteArray, 0, result, 0, protocal.byteArray.Length);
            System.Buffer.BlockCopy(protocal.move_byteArray, 0, result, protocal.byteArray.Length, protocal.move_byteArray.Length);
            return result;
        }

        void move_forwardstep()
        {
            req_status();                       //연속해서 하려면 move_done신호가 필요함   

            byte[] headermovedata;
            txtSTT.Clear();
            protocal.Head_Move();
            protocal.move_Position();
            protocal.Position_byte = position;                      //초기화 후 포지션값 재배치
            UInt16 Int_Position = BitConverter.ToUInt16(protocal.Position_byte, 0);
            Int_Position += 20;                                     //원스텝
            protocal.Position_byte = protocal.GetBytesUInt16(Int_Position);
            makemovedata();
            headermovedata = headerplusmovedata();
            mainSock.Send(headermovedata);

            //current_Position.Text = BitConverter.ToUInt16(protocal.Position_byte, 0).ToString();
        }

        void move_backstep()
        {
            req_status();

            byte[] headermovedata;
            txtSTT.Clear();
            protocal.Head_Move();
            protocal.move_Position();
            protocal.Position_byte = position;                      //초기화 후 포지션값 재배치
            UInt16 Int_Position = BitConverter.ToUInt16(protocal.Position_byte, 0);
            Int_Position -= 20;                                     //원스텝
            protocal.Position_byte = protocal.GetBytesUInt16(Int_Position);
            makemovedata();
            headermovedata = headerplusmovedata();
            mainSock.Send(headermovedata);

            //current_Position.Text = BitConverter.ToUInt16(protocal.Position_byte, 0).ToString();

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

        //button function
        public void initbutton()
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

        public void initmgsbutton()
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
        public void connectable()
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
        }
        public void position_clickable()
        {
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
            image_init();
        }

        private void start_btn_Click(object sender, EventArgs e)
        {
            startable();
            start();
        }

        private void live_btn_Click(object sender, EventArgs e)
        {
            liveable();
            stop = false;
            th2 = new Thread(new ThreadStart(myThread2));
            th2.Start();
        }

        private void capture_btn_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = map;
        }

        private void stop_btn_Click(object sender, EventArgs e)
        {
            initbutton();
            stop = true;
            stop1();
            dispose();
        }

        private void live_stop_btn_Click(object sender, EventArgs e)
        {
            livestopable();
            th2.Abort();
        }

        private void pictureBox1_Click_1(object sender, EventArgs e)
        {

        }

        //multichat design
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                mainSock.Disconnect(true);
            }
            catch
            {

            }
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
            move();
        }

        private void alarm_btn_Click(object sender, EventArgs e)
        {
            alarm();
        }

        private void chang_Position_Click(object sender, EventArgs e)
        {
                position_clickable();
                req_status();
        }

        private void current_Position_TextChanged(object sender, EventArgs e)
        {
            
            
        }

        private void chang_Position_TextChanged(object sender, EventArgs e)
        {

        }

        private void forwardstep_Click(object sender, EventArgs e)
        {
            move_forwardstep();

        }
       

        private void backstep_Click(object sender, EventArgs e)
        {
            move_backstep();
        }

        private void close_btn_Click(object sender, EventArgs e)
        {
            initmgsbutton();
            try
            {
                mainSock.Disconnect(true);
                initbutton();
                stop = true;
                stop1();
                dispose();
            }
            catch
            {

            }
        }

        private void auto_btn_Click(object sender, EventArgs e)
        {
            onserver();
            System.Threading.Thread.Sleep(1000);
            image_init();
            System.Threading.Thread.Sleep(1000);
            start();
            System.Threading.Thread.Sleep(1000);
            liveable();
            stop = false;
            th2 = new Thread(new ThreadStart(myThread2));
            th2.Start();
            init_btn.Enabled = false;
        }
    }
}