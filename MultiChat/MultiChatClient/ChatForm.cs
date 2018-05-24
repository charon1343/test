using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;
using OpenTK;
using OpenTK.Graphics.OpenGL;

namespace MultiChatClient {
    public partial class ChatForm : Form {
        delegate void AppendTextDelegate(Control ctrl, string s);
        AppendTextDelegate _textAppender;
        public Socket mainSock;
        Protocal protocal = new Protocal();
        byte[] move_receive = new byte[2];  //무브에 사용
        bool when_move;

        public ChatForm() {
            InitializeComponent();
            mainSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
            _textAppender = new AppendTextDelegate(AppendText);
        }

        void AppendText(Control ctrl, string s) {
            if (ctrl.InvokeRequired) ctrl.Invoke(_textAppender, ctrl, s);
            else {
                string source = ctrl.Text;
                ctrl.Text = source + Environment.NewLine + s;
            }
        }

        //주소로드
        void OnFormLoaded(object sender, EventArgs e) {
            IPHostEntry he = Dns.GetHostEntry(Dns.GetHostName());

            // 처음으로 발견되는 ipv4 주소를 사용한다.
            IPAddress defaultHostAddress = null;
            foreach (IPAddress addr in he.AddressList) {
                if (addr.AddressFamily == AddressFamily.InterNetwork) {
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

        //서버연결
        void OnConnectToServer(object sender, EventArgs e) {
            if (mainSock.Connected) {
                MsgBoxHelper.Error("이미 연결되어 있습니다!");
                return;
            }

            int port;
            if (!int.TryParse(txtPort.Text, out port)) {
                MsgBoxHelper.Error("포트 번호가 잘못 입력되었거나 입력되지 않았습니다.");
                txtPort.Focus();
                txtPort.SelectAll();
                return;
            }

            try { mainSock.Connect(txtAddress.Text, port); }
            catch (Exception ex) {
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
        void DataReceived(IAsyncResult ar) {
            // BeginReceive에서 추가적으로 넘어온 데이터를 AsyncObject 형식으로 변환한다.
            AsyncObject obj = (AsyncObject) ar.AsyncState;

            // 데이터 수신을 끝낸다.
            int received = obj.WorkingSocket.EndReceive(ar);

            // 받은 데이터가 없으면(연결끊어짐) 끝낸다.
            if (received <= 0) {
                obj.WorkingSocket.Close();
                return;
            }

            if (obj.Buffer[2] != 86 && obj.Buffer[3] != 83)
            {
                move_receive[0] = obj.Buffer[2];
                move_receive[1] = obj.Buffer[3]; //Position 2바이트때 사용
                Console.WriteLine(move_receive[0]);
                Console.WriteLine(move_receive[1]);
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

        void OnSendData(object sender, EventArgs e) {
            if (!mainSock.IsBound) {
                MsgBoxHelper.Warn("서버가 실행되고 있지 않습니다!");
                return;
            }

            
            string tts = txtTTS.Text.Trim(); // 보낼 텍스트
            if (string.IsNullOrEmpty(tts)) {
                MsgBoxHelper.Warn("텍스트가 입력되지 않았습니다!");
                txtTTS.Focus();
                return;
            }

            // 서버 ip 주소와 메세지를 담도록 만든다.
            IPEndPoint ip = (IPEndPoint) mainSock.LocalEndPoint;
            string addr = ip.Address.ToString();

            //head_format 초기 선언
            protocal.head_format();

            // datasize 8의배수 계산
            UInt16 ttx_size = (UInt16)((((tts.Length - 1) / 8) + 1) * 8);

            //텍스트 사이즈를 dataSize에 넣음
            protocal.dataSize_byte = BitConverter.GetBytes(ttx_size);
            
            // head_format를 byteArray로 변환
            protocal.Make_ByteArray();


            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] byteArray_rcv=protocal.byteArray;
            byte[] tts_rcv = Encoding.UTF8.GetBytes(tts);
            byte[] bDts=new byte[tts_rcv.Length+byteArray_rcv.Length];
            System.Buffer.BlockCopy(byteArray_rcv, 0, bDts, 0, byteArray_rcv.Length);
            System.Buffer.BlockCopy(tts_rcv, 0, bDts, byteArray_rcv.Length, tts_rcv.Length);

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            
            txtSTT.Clear();
            AppendText(txtSTT, string.Format("[보냄]{0}: {1}", addr, tts));
            txtTTS.Clear();
        }

        private void tblMainLayout_Paint(object sender, PaintEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.head_format();
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
            protocal.keepAlive();
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
            protocal.Req_status();
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
            protocal.Homing();
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
            protocal.Move();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("Move 보냄"));
            txtTTS.Clear();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Alarm();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("Alarm 보냄"));
            txtTTS.Clear();
        }

        private void txtPort_TextChanged(object sender, EventArgs e)
        {

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

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Req_status();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("Req_status 보냄"));
            txtTTS.Clear();

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Req_status();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 서버에 전송한다.
            mainSock.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            AppendText(txtSTT, string.Format("Req_status 보냄"));
            txtTTS.Clear();


            textBox1.Text = BitConverter.ToInt16(move_receive, 0).ToString();

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

    }
}