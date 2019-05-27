using System;

namespace Autopocusing
{
    class Protocal
    {
        //header var
        public byte[] identifier = { 0x4d, 0x4e, 0x56, 0x53 };
        public UInt16 headerSize;
        public UInt16 dataSize;
        public byte Msg;
        public byte Req;
        public UInt16 Reserve0;
        public UInt16 Reserve1;

        //header_byte[] var
        public byte[] headerSize_byte;
        public byte[] dataSize_byte;
        public byte[] Reserve0_byte;
        public byte[] Reserve1_byte;

        //head complete var
        public byte[] byteArray = new byte[16];

        //move var
        public UInt16 Reserve_m0;
        public UInt16 Position;
        public UInt32 Reserve_m1;

        //move_byte[] var
        public byte[] Reserve_m0_byte;
        public byte[] Position_byte = new byte[2];
        public byte[] Reserve_m1_byte;

        //move complete var;
        public byte[] move_byteArray = new byte[8];

        //==============================================================
        //header 초기화
        public void initHead()
        {
            headerSize = 16;
            dataSize = 0;
            Msg = 0;
            Req = 0;
            Reserve0 = 0;
            Reserve1 = 0;

            header_IntTobyteArray();
        }

        public void Head_head_format()
        {
            SetHeaderData();
            header_Make_ByteArray();
        }

        public void Head_keepAlive()
        {
            SetHeaderData();
            header_Make_ByteArray();
        }

        public void Head_Req_status()
        {
            dataSize = 16;
            Msg = 10;

            SetHeaderData(dataSize, Msg);
            header_Make_ByteArray();
        }

        public void Head_Homing()
        {
            Msg = 50;

            SetHeaderData(Msg);
            header_Make_ByteArray();
        }

        public void Head_Move()
        {
            dataSize = 8;
            Msg = 60;

            SetHeaderData(dataSize, Msg);
            header_Make_ByteArray();
        }

        public void Head_Alarm()
        {
            dataSize = 8;
            Msg = 255;

            SetHeaderData(dataSize, Msg);
            header_Make_ByteArray();
        }

        //=====================================================================
        public void initMove()
        {
            Reserve_m0 = 0;
            //Position = 0;
            Reserve_m1 = 0;

        }
        public void initMove(UInt16 Position)
        {
            Reserve_m0 = 0;
            this.Position = Position;
            Reserve_m1 = 0;
        }

        public void move_Position()
        {
            if (Position == 0)
                initMove();
            else
            initMove(Position);
            
            move_IntTobyteArray();
        }
        public void move_set()
        {
            
        }
        //=====================================================================
        // header int to byte[]
        public void header_IntTobyteArray()
        {
            headerSize_byte = GetBytesUInt16(headerSize);
            dataSize_byte = GetBytesUInt16(dataSize);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);
        }
        // move int to byte[]
        public void move_IntTobyteArray()
        {
            Reserve_m0_byte = GetBytesUInt16(Reserve_m0);
            Position_byte = GetBytesUInt16(Position);
            Reserve_m1_byte = GetBytesUInt32(Reserve_m1);
        }

        //set header overloading
        public void SetHeaderData()
        {
            initHead();
        }

        public void SetHeaderData(byte Msg)
        {
            initHead();
            this.Msg = Msg;
        }

        public void SetHeaderData(UInt16 dataSize, byte Msg)
        {
            initHead();
            dataSize_byte = GetBytesUInt16(dataSize);
            this.Msg = Msg;
        }

        //set move overloading 입력값이 있어서 불필요
        //public void SetMoveData()
        //{
        //    initMove();
        //}

        //public void SetMoveData(UInt16 Position)
        //{
        //    Position_byte = GetBytesUInt16(Position);
        //}

        //header make byteArray
        public void header_Make_ByteArray()
        {
            Buffer.BlockCopy(identifier, 0, byteArray, 0, identifier.Length);
            Buffer.BlockCopy(headerSize_byte, 0, byteArray, 4, headerSize_byte.Length);
            Buffer.BlockCopy(dataSize_byte, 0, byteArray, 6, dataSize_byte.Length);
            byteArray[8] = Msg;
            byteArray[9] = Req;
            Buffer.BlockCopy(Reserve0_byte, 0, byteArray, 10, Reserve0_byte.Length);
            Buffer.BlockCopy(Reserve1_byte, 0, byteArray, 12, Reserve1_byte.Length);
        }

        //move make byteArray
        public void move_Make_ByteArray()
        {
            //byte[] move_byteArray= new byte[8]; //예외처리
            Buffer.BlockCopy(Reserve_m0_byte, 0, move_byteArray, 0, Reserve_m0_byte.Length);
            Buffer.BlockCopy(Position_byte, 0, move_byteArray, Reserve_m0_byte.Length, Position_byte.Length);
            Buffer.BlockCopy(Reserve_m1_byte, 0, move_byteArray, Reserve_m0_byte.Length + Position_byte.Length, Reserve_m1_byte.Length);
            //this.move_byteArray = move_byteArray;   //예외처리
        }

        //============================================================
        //uint16 to byteArray
        public byte[] GetBytesUInt16(UInt16 argument)
        {
            byte[] byteArray = BitConverter.GetBytes(argument);
            return byteArray;
        }

        //uint32 to byteArray
        public byte[] GetBytesUInt32(UInt32 argument)
        {
            byte[] byteArray = BitConverter.GetBytes(argument);
            return byteArray;
        }

    }
}
