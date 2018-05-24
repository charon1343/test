using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MultiChatClient
{
    class Protocal : ToByteArray
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

        public byte[] byteArray = new byte[16];

        //head를 0으로 초기화 및 변환
        public void initHead()
        {
            headerSize = 16;
            dataSize = 0;
            Msg = 0;
            Req = 0;
            Reserve0 = 0;
            Reserve1 = 0;

            IntTobyteArray();
        }

        //Int에서 byteArray로 변환
        public void IntTobyteArray()
        {
            headerSize_byte = GetBytesUInt16(headerSize);
            dataSize_byte = GetBytesUInt16(dataSize);
            Reserve0_byte = GetBytesUInt16(Reserve0);
            Reserve1_byte = GetBytesUInt32(Reserve1);
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
        public void SetHeaderData(UInt16 _dtSize,byte _msg)
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

        //헤더포멧에 데이터 셋팅
        public void head_format()
        {
            SetHeaderData();
        }

        //헤더포멧에 데이터 셋팅
        public void keepAlive()
        {
            SetHeaderData();
            Make_ByteArray();
        }

        //헤더포멧에 데이터 셋팅
        public void Req_status()
        {
            dataSize = 16;
            Msg = 10;

            SetHeaderData(dataSize,Msg);
            Make_ByteArray();
        }

        //헤더포멧에 데이터 셋팅
        public void Homing()
        {
            dataSize = 0;
            Msg = 50;

            SetHeaderData(dataSize, Msg);
            Make_ByteArray();
        }

        //헤더포멧에 데이터 셋팅
        public void Move()
        {
            dataSize = 8;
            Msg = 60;

            SetHeaderData(dataSize, Msg);
            Make_ByteArray();
        }

        //헤더포멧에 데이터 셋팅
        public void Alarm()
        {
            dataSize = 8;
            Msg = 255;

            SetHeaderData(dataSize, Msg);
            Make_ByteArray();
        }
    }
}
