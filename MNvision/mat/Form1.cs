using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using OpenCvSharp;
using System.Threading;
using OpenCvSharp.Extensions;

namespace WindowsFormsApplication6
{
    public partial class Form1 : Form
    {
        VideoCapture capture;
        Mat frame;
        Bitmap image;
        Thread camera;
        int isCameraRunning = 0;

        private void CaptureCamera()
        {
            camera = new Thread(new ThreadStart(CaptureCameraCallback));
            camera.Start();
        }

        private void CaptureCameraCallback()
        {
            frame = new Mat();
            capture = new VideoCapture();
            capture.Open(0);
            while (isCameraRunning == 1)
            {
                capture.Read(frame);
                image = BitmapConverter.ToBitmap(frame);
                pictureBox1.Image = image;
                image = null;
            }

        }

        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            CaptureCamera();
            isCameraRunning = 1;
        }
    }
}
