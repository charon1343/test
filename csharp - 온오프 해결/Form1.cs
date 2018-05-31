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
        //Thread camera;
        IStImage stImage;
        Bitmap map;
        bool stop = false;
        bool view = false;
        CStApiAutoInit api;
        CStSystem system;
        CStDevice device;
        CStDataStream dataStream;

        public Form1()
        {
            InitializeComponent();
        }

        public void OnCallback(IStCallbackParamBase paramBase, object[] param)
        {
            Console.WriteLine("8");

            if (paramBase.CallbackType == eStCallbackType.TL_DataStreamNewBuffer)
                Console.WriteLine("9");
            {
                IStCallbackParamGenTLEventNewBuffer callbackParam = paramBase as IStCallbackParamGenTLEventNewBuffer;
                Console.WriteLine("10");

                if (callbackParam != null)
                Console.WriteLine("11");
                {
                    IStDataStream dataStream = callbackParam.GetIStDataStream();
                    Console.WriteLine("12");

                    using (CStStreamBuffer streamBuffer = dataStream.RetrieveBuffer(0))

                    {
                        Console.WriteLine("13");

                        if (streamBuffer.GetIStStreamBufferInfo().IsImagePresent)
                        {
                            Console.WriteLine("14");

                            stImage = streamBuffer.GetIStImage();
                            Console.WriteLine("15");

                            byte[] imageData = stImage.GetByteArray();
                            map = new Bitmap((int)stImage.ImageWidth, (int)stImage.ImageHeight,
                           (int)stImage.ImageWidth, PixelFormat.Format24bppRgb, Marshal.UnsafeAddrOfPinnedArrayElement(stImage.GetByteArray(), 0));
                            Console.WriteLine("16");
                            //if(view==true) pictureBox1.Image = map;
                            Console.WriteLine("17");//인보크 딜리게이트
                        }
                    }
                }
            }
        }


        public void start()
        {
            {
                dataStream.StartAcquisition();
                Console.WriteLine("3");

                device.AcquisitionStart();
                Console.WriteLine("4");
            }
        }

        public void stop1()
        {
            Console.WriteLine("5");

            device.AcquisitionStop();
            Console.WriteLine("6");

            dataStream.StopAcquisition();
            Console.WriteLine("7");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //camera = new Thread(new ThreadStart(start));
            //camera.Start();
            //pictureBox1.Image = map;
            start();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            stop = true;
            stop1();
            
        }

        private void button3_Click(object sender, EventArgs e)
        {
            view = true;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            view = false;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = map;
        }

        private void btnInit_Click(object sender, EventArgs e)
        {
            api = new CStApiAutoInit();
            system = new CStSystem(eStSystemVendor.Sentech);
            device = system.CreateFirstStDevice();
            dataStream = device.CreateStDataStream(0);

            Console.WriteLine("1");
            dataStream.RegisterCallbackMethod(OnCallback);
            Console.WriteLine("2");
        }
    }
}
