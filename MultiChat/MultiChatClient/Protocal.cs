using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MultiChatClient
{
    class Protocal
    {
        //header var;
        public byte[] identifier = { 0x4d, 0x4e, 0x56, 0x53 };
        public UInt16 headerSize;
        public UInt16 dataSize;
        public byte Msg;
        public byte Req;
        public UInt16 Reserve0;
        public UInt32 Reserve1;

        //header_byte[] var;
        public byte[] headerSize_byte;
        public byte[] dataSize_byte;
        public byte[] Reserve0_byte;
        public byte[] Reserve1_byte;

        //head complete var;
        public byte[] byteArray = new byte[16];

        //move var;
        public UInt16 Reservem0;
        public UInt16 Position;
        public UInt16 Reservem1;

        //move_byte[] var;
        public byte[] Reservem0_byte;
        public byte[] Position_byte;
        public byte[] Reservem1_byte;
        
        //move complete var;
        public byte[] Position_byteArray = new byte[8];


        
        //head를 0으로 초기화 및 변환
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

        //헤더포멧에 데이터 셋팅
        public void Head_head_format()
        {
            SetHeaderData();
        }

        //헤더포멧에 데이터 셋팅
        public void Head_keepAlive()
        {
            SetHeaderData();
            Make_ByteArray();
        }

        //헤더포멧에 데이터 셋팅
        public void Head_Req_status()
        {
            dataSize = 16;
            Msg = 10;

            SetHeaderData(dataSize,Msg);
            Make_ByteArray();
        }

        //헤더포멧에 데이터 셋팅
        public void Head_Homing()
        {
            dataSize = 0;
            Msg = 50;

            SetHeaderData(dataSize, Msg);
            Make_ByteArray();
        }

        //헤더포멧에 데이터 셋팅
        public void Head_Move()
        {
            dataSize = 8;
            Msg = 60;

            SetHeaderData(dataSize, Msg);
            Make_ByteArray();
        }

        //헤더포멧에 데이터 셋팅
        public void Head_Alarm()
        {
            dataSize = 8;
            Msg = 255;

            SetHeaderData(dataSize, Msg);
            Make_ByteArray();
        }

        //move를 0으로 초기화 및 변환
        public void initMove()
        {
            Reservem0 = 0;
            Position = 0;
            Reservem1 = 0;

            move_IntTobyteArray();
        }


        //something To byteArray 선언
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



        //head byteArray로 변환적용
        public void header_IntTobyteArray()
        {
            headerSize_byte = GetBytesUInt16(headerSize);
            dataSize_byte = GetBytesUInt16(dataSize);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);
        }

        //move byteArray로 변환적용
        public void move_IntTobyteArray()
        {
            Reservem0_byte = GetBytesUInt16(Reservem0);
            Position_byte = GetBytesUInt16(Position);
            Reservem1_byte = GetBytesUInt32(Reservem1);
        }
        //헤더 데이타 세팅
        public void SetHeaderData()
        {
            initHead();
        }

        //헤더 데이타 세팅 및 데이터사이즈 넣기
        public void SetHeaderData(UInt16 _dtSize)
        {
            initHead();
            dataSize_byte = GetBytesUInt16(_dtSize);
        }

        //헤더 데이타 세팅 및 데이터사이즈,메세지 넣기
        public void SetHeaderData(UInt16 _dtSize, byte _msg)
        {
            initHead();
            dataSize_byte = GetBytesUInt16(_dtSize);
            Msg = _msg;
        }

        //make byteArray
        public void Make_ByteArray()
        {
            byte[] result = new byte[8];    //예외처리문제로 지역변수 선언

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
