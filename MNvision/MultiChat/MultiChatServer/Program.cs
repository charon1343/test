using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace MultiChatServer
{
    static class Program
    {
        /// <summary>
        /// 해당 응용 프로그램의 주 진입점입니다.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new ChatForm());
        }
    }
    class Protocal
    {
        public byte[] identifier = { 0x4d, 0x4e, 0x56, 0x53 };
        public UInt16 headerSize;
        public UInt16 dataSize;
        public byte Msg;
        public byte Req;
        public UInt16 Reserve0;
        public UInt32 Reserve1;

        public byte[] headerSize_byte;
        public byte[] dataSize_byte;
        public byte[] Reserve0_byte;
        public byte[] Reserve1_byte;


        public byte MovementFlag;
        public byte HomingFlag;
        public UInt16 Position;
        public byte AlarmNumber;
        public byte Reserveb0;  //1바이트(Reserveb0)와 2바이트(Reserve0) 합쳐서 3바이트 (Reserve0)로 사용
        public UInt32 Reserve2;

        public byte[] Position_byte;
        public byte[] Reserve2_byte;


        public byte[] byteArray = new byte[16];



        public byte[] addByteToArray(byte[] bArray, byte newByte) //byte to byteArray
        {
            byte[] newArray = new byte[bArray.Length + 1];
            bArray.CopyTo(newArray, 0);
            newArray[bArray.Length] = newByte;
            return newArray;
        }

        public byte[] GetBytesUInt16(UInt16 argument) //uint16 to byteArray
        {
            byte[] byteArray = BitConverter.GetBytes(argument);
            return byteArray;
        }
        public byte[] GetBytesUInt32(UInt32 argument) //uint32 to byteArray
        {
            byte[] byteArray = BitConverter.GetBytes(argument);
            return byteArray;
        }

        public void head_format()
        {
            headerSize = 16;
            dataSize = 0;
            Msg = 0;
            Req = 1;
            Reserve0 = 0;
            Reserve1 = 0;


            //int to byteArray
            headerSize_byte = GetBytesUInt16(headerSize);
            dataSize_byte = GetBytesUInt16(dataSize);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);
        }
        public void head_format_ttx()
        {
            byte[] result = new byte[10];
            //make byteArray
            System.Buffer.BlockCopy(identifier, 0, result, 0, identifier.Length);
            System.Buffer.BlockCopy(headerSize_byte, 0, result, 4, headerSize_byte.Length);
            System.Buffer.BlockCopy(dataSize_byte, 0, result, 6, dataSize_byte.Length);
            result = addByteToArray(result, Msg);
            result = addByteToArray(result, Req);
            System.Buffer.BlockCopy(result, 0, byteArray, 0, result.Length);
            System.Buffer.BlockCopy(Reserve0_byte, 0, byteArray, 10, Reserve0_byte.Length);
            System.Buffer.BlockCopy(Reserve1_byte, 0, byteArray, 12, Reserve1_byte.Length);

        }

        public void keepAlive()
        {
            headerSize = 16;
            dataSize = 0;
            Msg = 0;
            Req = 1;
            Reserve0 = 0;
            Reserve1 = 0;
            byte[] result = new byte[8];


            //int to byteArray
            headerSize_byte = GetBytesUInt16(headerSize);
            dataSize_byte = GetBytesUInt16(dataSize);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);

            //make byteArray
            System.Buffer.BlockCopy(identifier, 0, result, 0, identifier.Length);
            System.Buffer.BlockCopy(headerSize_byte, 0, result, 4, headerSize_byte.Length);
            System.Buffer.BlockCopy(dataSize_byte, 0, result, 6, dataSize_byte.Length);
            result = addByteToArray(result, Msg);
            result = addByteToArray(result, Req);
            System.Buffer.BlockCopy(result, 0, byteArray, 0, result.Length);
            System.Buffer.BlockCopy(Reserve0_byte, 0, byteArray, 10, Reserve0_byte.Length);
            System.Buffer.BlockCopy(Reserve1_byte, 0, byteArray, 12, Reserve1_byte.Length);
        }

        public void Req_status()
        {
            headerSize = 16;
            dataSize = 16;
            Msg = 10;
            Req = 1;
            Reserve0 = 0;
            Reserve1 = 0;
            byte[] result = new byte[8];


            //int to byteArray
            headerSize_byte = GetBytesUInt16(headerSize);
            dataSize_byte = GetBytesUInt16(dataSize);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);

            //make byteArray
            System.Buffer.BlockCopy(identifier, 0, result, 0, identifier.Length);
            System.Buffer.BlockCopy(headerSize_byte, 0, result, 4, headerSize_byte.Length);
            System.Buffer.BlockCopy(dataSize_byte, 0, result, 6, dataSize_byte.Length);
            result = addByteToArray(result, Msg);
            result = addByteToArray(result, Req);
            System.Buffer.BlockCopy(result, 0, byteArray, 0, result.Length);
            System.Buffer.BlockCopy(Reserve0_byte, 0, byteArray, 10, Reserve0_byte.Length);
            System.Buffer.BlockCopy(Reserve1_byte, 0, byteArray, 12, Reserve1_byte.Length);
        }
        public void Req_status_data()
        {
            MovementFlag = 0;
            HomingFlag = 1;
            Position = 60000;
            AlarmNumber = 0;
            Reserveb0 = 0;
            Reserve0 = 0;
            Reserve1 = 0;
            Reserve2 = 0;
            byte[] result = new byte[6];


            //int to byteArray
            Position_byte = GetBytesUInt16(Position);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);
            Reserve2_byte = GetBytesUInt32(Reserve2);

            //make byteArray
            result[0] = MovementFlag;
            result[1] = HomingFlag;
            System.Buffer.BlockCopy(Position_byte, 0, result, 2, Position_byte.Length);
            result[4] = AlarmNumber;
            result[5] = Reserveb0;
            System.Buffer.BlockCopy(result, 0, byteArray, 0, result.Length);
            System.Buffer.BlockCopy(Reserve0_byte, 0, byteArray, 6, Reserve0_byte.Length);
            System.Buffer.BlockCopy(Reserve1_byte, 0, byteArray, 8, Reserve1_byte.Length);
            System.Buffer.BlockCopy(Reserve2_byte, 0, byteArray, 12, Reserve2_byte.Length);
        }
        public void Homing()
        {
            headerSize = 16;
            dataSize = 0;
            Msg = 50;
            Req = 1;
            Reserve0 = 0;
            Reserve1 = 0;
            byte[] result = new byte[8];


            //int to byteArray
            headerSize_byte = GetBytesUInt16(headerSize);
            dataSize_byte = GetBytesUInt16(dataSize);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);

            //make byteArray
            System.Buffer.BlockCopy(identifier, 0, result, 0, identifier.Length);
            System.Buffer.BlockCopy(headerSize_byte, 0, result, 4, headerSize_byte.Length);
            System.Buffer.BlockCopy(dataSize_byte, 0, result, 6, dataSize_byte.Length);
            result = addByteToArray(result, Msg);
            result = addByteToArray(result, Req);
            System.Buffer.BlockCopy(result, 0, byteArray, 0, result.Length);
            System.Buffer.BlockCopy(Reserve0_byte, 0, byteArray, 10, Reserve0_byte.Length);
            System.Buffer.BlockCopy(Reserve1_byte, 0, byteArray, 12, Reserve1_byte.Length);
        }
        public void Homing_done()
        {
            headerSize = 16;
            dataSize = 0;
            Msg = 51;
            Req = 1;
            Reserve0 = 0;
            Reserve1 = 0;
            byte[] result = new byte[8];


            //int to byteArray
            headerSize_byte = GetBytesUInt16(headerSize);
            dataSize_byte = GetBytesUInt16(dataSize);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);

            //make byteArray
            System.Buffer.BlockCopy(identifier, 0, result, 0, identifier.Length);
            System.Buffer.BlockCopy(headerSize_byte, 0, result, 4, headerSize_byte.Length);
            System.Buffer.BlockCopy(dataSize_byte, 0, result, 6, dataSize_byte.Length);
            result = addByteToArray(result, Msg);
            result = addByteToArray(result, Req);
            System.Buffer.BlockCopy(result, 0, byteArray, 0, result.Length);
            System.Buffer.BlockCopy(Reserve0_byte, 0, byteArray, 10, Reserve0_byte.Length);
            System.Buffer.BlockCopy(Reserve1_byte, 0, byteArray, 12, Reserve1_byte.Length);
        }
        public void Move()
        {
            headerSize = 16;
            dataSize = 8;
            Msg = 60;
            Req = 1;
            Reserve0 = 0;
            Reserve1 = 0;
            byte[] result = new byte[8];


            //int to byteArray
            headerSize_byte = GetBytesUInt16(headerSize);
            dataSize_byte = GetBytesUInt16(dataSize);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);

            //make byteArray
            System.Buffer.BlockCopy(identifier, 0, result, 0, identifier.Length);
            System.Buffer.BlockCopy(headerSize_byte, 0, result, 4, headerSize_byte.Length);
            System.Buffer.BlockCopy(dataSize_byte, 0, result, 6, dataSize_byte.Length);
            result = addByteToArray(result, Msg);
            result = addByteToArray(result, Req);
            System.Buffer.BlockCopy(result, 0, byteArray, 0, result.Length);
            System.Buffer.BlockCopy(Reserve0_byte, 0, byteArray, 10, Reserve0_byte.Length);
            System.Buffer.BlockCopy(Reserve1_byte, 0, byteArray, 12, Reserve1_byte.Length);
        }
        public void Move_done()
        {
            headerSize = 16;
            dataSize = 8;
            Msg = 61;
            Req = 1;
            Reserve0 = 0;
            Reserve1 = 0;
            byte[] result = new byte[8];


            //int to byteArray
            headerSize_byte = GetBytesUInt16(headerSize);
            dataSize_byte = GetBytesUInt16(dataSize);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);

            //make byteArray
            System.Buffer.BlockCopy(identifier, 0, result, 0, identifier.Length);
            System.Buffer.BlockCopy(headerSize_byte, 0, result, 4, headerSize_byte.Length);
            System.Buffer.BlockCopy(dataSize_byte, 0, result, 6, dataSize_byte.Length);
            result = addByteToArray(result, Msg);
            result = addByteToArray(result, Req);
            System.Buffer.BlockCopy(result, 0, byteArray, 0, result.Length);
            System.Buffer.BlockCopy(Reserve0_byte, 0, byteArray, 10, Reserve0_byte.Length);
            System.Buffer.BlockCopy(Reserve1_byte, 0, byteArray, 12, Reserve1_byte.Length);
        }
        public void Move_data()
        {
            MovementFlag = 1;
            Reserveb0 = 0;
            Position = 60000;
            Reserve1 = 0;
            byte[] result = new byte[4];


            //int to byteArray
            Position_byte = GetBytesUInt16(Position);
            Reserve1_byte = GetBytesUInt32(Reserve1);

            //make byteArray
            result[0] = MovementFlag;
            result[1] = Reserveb0;
            System.Buffer.BlockCopy(Position_byte, 0, result, 2, Position_byte.Length);
            System.Buffer.BlockCopy(result, 0, byteArray, 0, result.Length);
            System.Buffer.BlockCopy(Reserve1_byte, 0, byteArray, 8, Reserve1_byte.Length);
        }
        public void Alarm()
        {
            headerSize = 16;
            dataSize = 8;
            Msg = 255;
            Req = 1;
            Reserve0 = 0;
            Reserve1 = 0;
            byte[] result = new byte[8];


            //int to byteArray
            headerSize_byte = GetBytesUInt16(headerSize);
            dataSize_byte = GetBytesUInt16(dataSize);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);

            //make byteArray
            System.Buffer.BlockCopy(identifier, 0, result, 0, identifier.Length);
            System.Buffer.BlockCopy(headerSize_byte, 0, result, 4, headerSize_byte.Length);
            System.Buffer.BlockCopy(dataSize_byte, 0, result, 6, dataSize_byte.Length);
            result = addByteToArray(result, Msg);
            result = addByteToArray(result, Req);
            System.Buffer.BlockCopy(result, 0, byteArray, 0, result.Length);
            System.Buffer.BlockCopy(Reserve0_byte, 0, byteArray, 10, Reserve0_byte.Length);
            System.Buffer.BlockCopy(Reserve1_byte, 0, byteArray, 12, Reserve1_byte.Length);
        }
    }
}
