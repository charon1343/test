using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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
        public Form1()
        {
            InitializeComponent();
        }


        public void start()
        {
            try
            {
                using (CStApiAutoInit api = new CStApiAutoInit())
                using (CStSystem system = new CStSystem(eStSystemVendor.Sentech))
                using (CStDevice device = system.CreateFirstStDevice())
                using (CStDataStream dataStream = device.CreateStDataStream(0))
                {
                    dataStream.StartAcquisition(1);
                    device.AcquisitionStart();
                    while (dataStream.IsGrabbing)
                    {
                        using (CStStreamBuffer streamBuffer = dataStream.RetrieveBuffer(5000))
                        {
                            if (streamBuffer.GetIStStreamBufferInfo().IsImagePresent)
                            {
                                IStImage stImage = streamBuffer.GetIStImage();

                                byte[] imageData = stImage.GetByteArray();

                                pictureBox1.Image = new Bitmap((int)stImage.ImageWidth, (int)stImage.ImageHeight,
                                    (int)stImage.ImageWidth, PixelFormat.Format24bppRgb, Marshal.UnsafeAddrOfPinnedArrayElement(stImage.GetByteArray(), 0));

                            }
                            else
                            {

                            }
                        }
                    }

                    device.AcquisitionStop();
                    dataStream.StopAcquisition();

                }
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            start();

        }


    }
}
