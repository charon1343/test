using System;
using System.Net;
using System.Net.Sockets;
using System.Windows.Forms;
using System.Collections.Generic;
using System.Text;
using OpenTK;
using OpenTK.Graphics.OpenGL;

namespace MultiChatServer {
    public partial class ChatForm : Form {
        delegate void AppendTextDelegate(Control ctrl, string s);
        AppendTextDelegate _textAppender;
        Socket mainSock;
        IPAddress thisAddress;
        Protocal protocal = new Protocal();
        
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
        

        void OnFormLoaded(object sender, EventArgs e) {
            IPHostEntry he = Dns.GetHostEntry(Dns.GetHostName());

            // 처음으로 발견되는 ipv4 주소를 사용한다.
            foreach (IPAddress addr in he.AddressList) {
                if (addr.AddressFamily == AddressFamily.InterNetwork) {
                    thisAddress = addr;
                    break;
                }    
            }

            // 주소가 없다면..
            if (thisAddress == null)
                // 로컬호스트 주소를 사용한다.
                thisAddress = IPAddress.Loopback;

            txtAddress.Text = thisAddress.ToString();
        }

        void BeginStartServer(object sender, EventArgs e) {
            int port;
            if (!int.TryParse(txtPort.Text, out port)) {
                MsgBoxHelper.Error("포트 번호가 잘못 입력되었거나 입력되지 않았습니다.");
                txtPort.Focus();
                txtPort.SelectAll();
                return;
            }

            // 서버에서 클라이언트의 연결 요청을 대기하기 위해
            // 소켓을 열어둔다.
            IPEndPoint serverEP = new IPEndPoint(thisAddress, port);
            mainSock.Bind(serverEP);
            mainSock.Listen(10);

            // 비동기적으로 클라이언트의 연결 요청을 받는다.
            mainSock.BeginAccept(AcceptCallback, null);
            AppendText(txtSTT, string.Format("서버시작"));

        }

        List<Socket> connectedClients = new List<Socket>();
        void AcceptCallback(IAsyncResult ar) {
            // 클라이언트의 연결 요청을 수락한다.
            Socket client = mainSock.EndAccept(ar);

            // 또 다른 클라이언트의 연결을 대기한다.
            mainSock.BeginAccept(AcceptCallback, null);

            AsyncObject obj = new AsyncObject(16);
            obj.WorkingSocket = client;

            // 연결된 클라이언트 리스트에 추가해준다.
            connectedClients.Add(client);

            foreach (Socket dinosaur in connectedClients) //확인
            {
                Console.WriteLine(dinosaur);
            }

            // 텍스트박스에 클라이언트가 연결되었다고 써준다.
            AppendText(txtHistory, string.Format("클라이언트 (@ {0})가 연결되었습니다.", client.RemoteEndPoint));

            // 클라이언트의 데이터를 받는다.
            client.BeginReceive(obj.Buffer, 0, 16, 0, DataReceived, obj);
        }

        void DataReceived(IAsyncResult ar) {
            // BeginReceive에서 추가적으로 넘어온 데이터를 AsyncObject 형식으로 변환한다.
            AsyncObject obj = (AsyncObject)ar.AsyncState;

            // 데이터 수신을 끝낸다.
            int received = obj.WorkingSocket.EndReceive(ar);

            // 받은 데이터가 없으면(연결끊어짐) 끝낸다.
            if (received <= 0) {
                obj.WorkingSocket.Close();
                return;
            }
            if(obj.Buffer[8]==0)
            {
                txtSTT.Clear();
                protocal.keepAlive();
                // 문자열을 utf8 형식의 바이트로 변환한다.
                byte[] bDts = protocal.byteArray;

                // 연결된 모든 클라이언트에게 전송한다.
                for (int i = connectedClients.Count - 1; i >= 0; i--)
                {
                    Socket socket = connectedClients[i];
                    try { socket.Send(bDts); }
                    catch
                    {
                        // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                        try { socket.Dispose(); } catch { }
                        connectedClients.RemoveAt(i);
                    }
                }

                AppendText(txtSTT, string.Format("keepAlive 보냄"));
            }
            else if(obj.Buffer[8] == 10)
            {
                txtSTT.Clear();
                protocal.Req_status();
                // 문자열을 utf8 형식의 바이트로 변환한다.
                byte[] bDts = protocal.byteArray;

                // 연결된 모든 클라이언트에게 전송한다.
                for (int i = connectedClients.Count - 1; i >= 0; i--)
                {
                    Socket socket = connectedClients[i];
                    try { socket.Send(bDts); }
                    catch
                    {
                        // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                        try { socket.Dispose(); } catch { }
                        connectedClients.RemoveAt(i);
                    }
                }
                protocal.Req_status_data();
                // 문자열을 utf8 형식의 바이트로 변환한다.
                byte[] bDtsd = protocal.byteArray;

                // 연결된 모든 클라이언트에게 전송한다.
                for (int i = connectedClients.Count - 1; i >= 0; i--)
                {
                    Socket socket = connectedClients[i];
                    try { socket.Send(bDtsd); }
                    catch
                    {
                        // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                        try { socket.Dispose(); } catch { }
                        connectedClients.RemoveAt(i);
                    }
                }

                AppendText(txtSTT, string.Format("Req_status 보냄"));
                txtTTS.Clear();

            }

            else if (obj.Buffer[8] == 50)
            {
                txtSTT.Clear();
                protocal.Homing_done();
                // 문자열을 utf8 형식의 바이트로 변환한다.
                byte[] bDts = protocal.byteArray;

                // 연결된 모든 클라이언트에게 전송한다.
                for (int i = connectedClients.Count - 1; i >= 0; i--)
                {
                    Socket socket = connectedClients[i];
                    try { socket.Send(bDts); }
                    catch
                    {
                        // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                        try { socket.Dispose(); } catch { }
                        connectedClients.RemoveAt(i);
                    }
                }

                AppendText(txtSTT, string.Format("Homing 시작"));
                txtTTS.Clear();
            }
            //else if (obj.Buffer[8] == 51)
            //{
            //    txtSTT.Clear();
            //    protocal.Homing();
            //    // 문자열을 utf8 형식의 바이트로 변환한다.
            //    byte[] bDts = protocal.byteArray;

            //    // 연결된 모든 클라이언트에게 전송한다.
            //    for (int i = connectedClients.Count - 1; i >= 0; i--)
            //    {
            //        Socket socket = connectedClients[i];
            //        try { socket.Send(bDts); }
            //        catch
            //        {
            //            // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
            //            try { socket.Dispose(); } catch { }
            //            connectedClients.RemoveAt(i);
            //        }
            //    }

            //    AppendText(txtSTT, string.Format("Homing 완료"));
            //    txtTTS.Clear();
            //}

            else if (obj.Buffer[8] == 60)
            {
                
                txtSTT.Clear();
                protocal.Move();
                // 문자열을 utf8 형식의 바이트로 변환한다.
                byte[] bDts = protocal.byteArray;

                // 연결된 모든 클라이언트에게 전송한다.
                for (int i = connectedClients.Count - 1; i >= 0; i--)
                {
                    Socket socket = connectedClients[i];
                    try { socket.Send(bDts); }
                    catch
                    {
                        // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                        try { socket.Dispose(); } catch { }
                        connectedClients.RemoveAt(i);
                    }
                }
                //protocal.Move_data();
                //// 문자열을 utf8 형식의 바이트로 변환한다.
                //byte[] bDtsd = protocal.byteArray;

                //// 연결된 모든 클라이언트에게 전송한다.
                //for (int i = connectedClients.Count - 1; i >= 0; i--)
                //{
                //    Socket socket = connectedClients[i];
                //    try { socket.Send(bDtsd); }
                //    catch
                //    {
                //        // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                //        try { socket.Dispose(); } catch { }
                //        connectedClients.RemoveAt(i);
                //    }
                //}
                AppendText(txtSTT, string.Format("Move 보냄"));
                txtTTS.Clear();
            }
            else if (obj.Buffer[8] == 255)
            {
                txtSTT.Clear();
                protocal.Alarm();
                // 문자열을 utf8 형식의 바이트로 변환한다.
                byte[] bDts = protocal.byteArray;

                // 연결된 모든 클라이언트에게 전송한다.
                for (int i = connectedClients.Count - 1; i >= 0; i--)
                {
                    Socket socket = connectedClients[i];
                    try { socket.Send(bDts); }
                    catch
                    {
                        // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                        try { socket.Dispose(); } catch { }
                        connectedClients.RemoveAt(i);
                    }
                }

                AppendText(txtSTT, string.Format("Alarm 보냄"));
                txtTTS.Clear();
            }


            // 텍스트로 변환한다.
            string msg1 = Encoding.ASCII.GetString(obj.Buffer);
            char[] array = msg1.ToCharArray(); //ASCII to hex변환
            string text = "";
            foreach (var i in array)
            {
                string hex = String.Format("{0:X}", Convert.ToInt32(i));
                text += hex.Insert(0, "") + " ";
            }

            text = text.TrimEnd();
            // 0x01 기준으로 짜른다.
            // tokens[0] - 보낸 사람 IP
            // tokens[1] - 보낸 메세지
            string msg = text;

            // 텍스트박스에 추가해준다.
            // 비동기식으로 작업하기 때문에 폼의 UI 스레드에서 작업을 해줘야 한다.
            // 따라서 대리자를 통해 처리한다.
            AppendText(txtHistory, string.Format(msg));
            
            // for을 통해 "역순"으로 클라이언트에게 데이터를 보낸다.
            for (int i = connectedClients.Count - 1; i >= 0; i--) {
                Socket socket = connectedClients[i];
                if (socket != obj.WorkingSocket) {
                    try { socket.Send(obj.Buffer); }
                    catch {
                        // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                        try { socket.Dispose(); } catch { }
                        connectedClients.RemoveAt(i);
                    }
                }
            }

            // 데이터를 받은 후엔 다시 버퍼를 비워주고 같은 방법으로 수신을 대기한다.
            obj.ClearBuffer();

            // 수신 대기
            obj.WorkingSocket.BeginReceive(obj.Buffer, 0, 16, 0, DataReceived, obj);
        }

        void OnSendData(object sender, EventArgs e) {
            // 서버가 대기중인지 확인한다.
            if (!mainSock.IsBound) {
                MsgBoxHelper.Warn("서버가 실행되고 있지 않습니다!");
                return;
            }
            
            // 보낼 텍스트
            string tts = txtTTS.Text.Trim();
            if (string.IsNullOrEmpty(tts)) {
                MsgBoxHelper.Warn("텍스트가 입력되지 않았습니다!");
                txtTTS.Focus();
                return;
            }

            //head_format 초기 선언
            protocal.head_format();

            // datasize 8의배수 계산
            int ttx_size = ((((tts.Length-1) / 8) + 1) * 8);

            //텍스트 사이즈를 dataSize에 넣음
            protocal.dataSize_byte = BitConverter.GetBytes(ttx_size);

            // head_format를 byteArray로 변환
            protocal.head_format_ttx();

            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] byteArray_rcv = protocal.byteArray;
            byte[] tts_rcv = Encoding.UTF8.GetBytes(tts);
            byte[] bDts = new byte[tts_rcv.Length + byteArray_rcv.Length];
            System.Buffer.BlockCopy(byteArray_rcv, 0, bDts, 0, byteArray_rcv.Length);
            System.Buffer.BlockCopy(tts_rcv, 0, bDts, byteArray_rcv.Length, tts_rcv.Length);


            //연결된 모든 클라이언트에게 전송한다.
            for (int i = connectedClients.Count - 1; i >= 0; i--)
            {
                Socket socket = connectedClients[i];
                try { socket.Send(bDts); }
                catch
                {
                    // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                    try { socket.Dispose(); } catch { }
                    connectedClients.RemoveAt(i);
                }
            }
            //Socket socket = connectedClients[0];
            //socket.Send(bDts);

            // 전송 완료 후 텍스트박스에 추가하고, 원래의 내용은 지운다.
            txtSTT.Clear();
            AppendText(txtSTT, string.Format("[보냄]{0}: {1}", thisAddress.ToString(), tts));
            txtTTS.Clear();
            
        }

        private void txtAddress_TextChanged(object sender, EventArgs e)
        {

        }
        

        private void tblMainLayout_Paint(object sender, PaintEventArgs e)
        {

        }

        private void txtTTS_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void button1_Click(object sender, EventArgs e)
        {

            txtSTT.Clear();
            protocal.head_format();
            protocal.head_format_ttx();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 연결된 모든 클라이언트에게 전송한다.
            for (int i = connectedClients.Count - 1; i >= 0; i--)
            {
                Socket socket = connectedClients[i];
                try { socket.Send(bDts); }
                catch
                {
                    // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                    try { socket.Dispose(); } catch { }
                    connectedClients.RemoveAt(i);
                }
            }

            AppendText(txtSTT, string.Format("header 보냄"));
            txtTTS.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.keepAlive();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 연결된 모든 클라이언트에게 전송한다.
            for (int i = connectedClients.Count - 1; i >= 0; i--)
            {
                Socket socket = connectedClients[i];
                try { socket.Send(bDts); }
                catch
                {
                    // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                    try { socket.Dispose(); } catch { }
                    connectedClients.RemoveAt(i);
                }
            }

            AppendText(txtSTT, string.Format("keepAlive 보냄"));
        }

        private void button3_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Req_status();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 연결된 모든 클라이언트에게 전송한다.
            for (int i = connectedClients.Count - 1; i >= 0; i--)
            {
                Socket socket = connectedClients[i];
                try { socket.Send(bDts); }
                catch
                {
                    // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                    try { socket.Dispose(); } catch { }
                    connectedClients.RemoveAt(i);
                }
            }

            AppendText(txtSTT, string.Format("Req_status 보냄"));
            txtTTS.Clear();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Homing();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 연결된 모든 클라이언트에게 전송한다.
            for (int i = connectedClients.Count - 1; i >= 0; i--)
            {
                Socket socket = connectedClients[i];
                try { socket.Send(bDts); }
                catch
                {
                    // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                    try { socket.Dispose(); } catch { }
                    connectedClients.RemoveAt(i);
                }
            }

            AppendText(txtSTT, string.Format("Homing 보냄"));
            txtTTS.Clear();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Move();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 연결된 모든 클라이언트에게 전송한다.
            for (int i = connectedClients.Count - 1; i >= 0; i--)
            {
                Socket socket = connectedClients[i];
                try { socket.Send(bDts); }
                catch
                {
                    // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                    try { socket.Dispose(); } catch { }
                    connectedClients.RemoveAt(i);
                }
            }

            AppendText(txtSTT, string.Format("Move 보냄"));
            txtTTS.Clear();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            txtSTT.Clear();
            protocal.Alarm();
            // 문자열을 utf8 형식의 바이트로 변환한다.
            byte[] bDts = protocal.byteArray;

            // 연결된 모든 클라이언트에게 전송한다.
            for (int i = connectedClients.Count - 1; i >= 0; i--)
            {
                Socket socket = connectedClients[i];
                try { socket.Send(bDts); }
                catch
                {
                    // 오류 발생하면 전송 취소하고 리스트에서 삭제한다.
                    try { socket.Dispose(); } catch { }
                    connectedClients.RemoveAt(i);
                }
            }

            AppendText(txtSTT, string.Format("Alarm 보냄"));
            txtTTS.Clear();
        }

        private void txtHistory_TextChanged(object sender, EventArgs e)
        {
            txtHistory.SelectionStart = txtHistory.TextLength;
            txtHistory.ScrollToCaret();
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


    }
}