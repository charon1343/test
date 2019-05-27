using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;

using Sentech.GenApiDotNET;
using Sentech.StApiDotNET;
using System.IO;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;

namespace csharp
{

    public partial class Form1 : Form
    {
        Thread camera;
        bool stop;

        public Form1()
        {
            InitializeComponent();
        }

        public void OnCallback(IStCallbackParamBase paramBase, object[] param)
        {
            if(stop==true)
            {
                return;
            }
            else
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

                            IStImage stImage = streamBuffer.GetIStImage();

                            Bitmap map = new Bitmap((int)stImage.ImageWidth, (int)stImage.ImageHeight,(int)stImage.ImageWidth, PixelFormat.Format24bppRgb, Marshal.UnsafeAddrOfPinnedArrayElement(stImage.GetByteArray(), 0));

                            pictureBox1.Image = map;    //출력

                        }
                    }
                }
            }
        }


        public void start()
        {
            using (CStApiAutoInit api = new CStApiAutoInit())
            using (CStSystem system = new CStSystem(eStSystemVendor.Sentech))
            using (CStDevice device = system.CreateFirstStDevice())
            using (CStDataStream dataStream = device.CreateStDataStream(0))
            {
                dataStream.RegisterCallbackMethod(OnCallback);
                dataStream.StartAcquisition();

                device.AcquisitionStart();

                Console.ReadLine();

                device.AcquisitionStop();
                dataStream.StopAcquisition();

            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            camera = new Thread(new ThreadStart(start));
            camera.Start();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            stop = true;
        }
    }
}
