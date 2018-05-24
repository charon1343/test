using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MultiChatClient
{
    class ToByteArray
    {
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
    }
}
