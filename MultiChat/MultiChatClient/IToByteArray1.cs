namespace MultiChatClient
{
    interface IToByteArray1
    {
        byte[] addByteToArray(byte[] bArray, byte newByte);
        byte[] GetBytesUInt16(ushort argument);
        byte[] GetBytesUInt32(uint argument);
        void ToByte(Protocal protocal);
    }
}