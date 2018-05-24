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

namespace OpenCV_CamTest
{
    public partial class Form1 : Form,IDisposable
    {

        IplImage m_cvImg;
        CvCapture m_cvCap;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            m_cvCap = CvCapture.FromCamera(0);
            m_cvCap.FrameWidth = 1260;
            m_cvCap.FrameHeight = 860;

            timer1.Interval = 20;
            timer1.Enabled = true;
            timer2.Interval = 1000;
            timer2.Enabled = true;

        }


        private void timer1_Tick(object sender, EventArgs e)
        {
                m_cvImg = m_cvCap.QueryFrame();
                pictureBox1.Image = m_cvImg.ToBitmap();
                
        }

        private void button1_Click(object sender, EventArgs e)
        {

            Dispose();
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            GC.Collect(); 
        }
    }
}
