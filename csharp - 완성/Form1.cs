using System;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;

using Sentech.StApiDotNET;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;

namespace csharp
{

    public partial class Form1 : Form
    {
        IStImage stImage;
        Bitmap map;
        bool stop = false;

        CStApiAutoInit api;
        CStSystem system;
        CStDevice device;
        CStDataStream dataStream;

        Thread th2;
        private delegate void myDelegate2();

        private void updateProgress2()
        {
            pictureBox1.Image = map;
        }

        private void myThread2()
        {
            for (;;)
            {
                if (stop == false)
                    this.Invoke(new myDelegate2(updateProgress2));
                else
                    break;
            }
            th2.Abort();
        }

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
        public void dispose()
        {
            dataStream.Dispose();
            device.Dispose();
            system.Dispose();
            api.Dispose();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            start();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            stop = true;
            stop1();
            dispose();

        }


        private void button4_Click(object sender, EventArgs e)
        {
            th2.Abort();
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


        private void button7_Click(object sender, EventArgs e)
        {
            stop = false;
            th2 = new Thread(new ThreadStart(myThread2));
            th2.Start();
        }
    }
}
