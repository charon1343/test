﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace d
{
    class Program
    {
        static void Main(string[] args)
        {
            // Create and initialize a GroupBox and a Button control.
            GroupBox groupBox1 = new GroupBox();
            Button button1 = new Button();
            button1.Location = new Point(20, 10);

            // Set the FlatStyle of the GroupBox.
            groupBox1.FlatStyle = FlatStyle.Flat;

            // Add the Button to the GroupBox.
            groupBox1.Controls.Add(button1);

            // Add the GroupBox to the Form.
            Controls.Add(groupBox1);

            // Create and initialize a GroupBox and a Button control.
            GroupBox groupBox2 = new GroupBox();
            Button button2 = new Button();
            button2.Location = new Point(20, 10);
            groupBox2.Location = new Point(0, 120);

            // Set the FlatStyle of the GroupBox.
            groupBox2.FlatStyle = FlatStyle.Standard;

            // Add the Button to the GroupBox.
            groupBox2.Controls.Add(button2);

            // Add the GroupBox to the Form.
            Controls.Add(groupBox2);
        }
    }
}
