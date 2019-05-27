namespace Autopocusing
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.init_btn = new System.Windows.Forms.Button();
            this.start_btn = new System.Windows.Forms.Button();
            this.live_btn = new System.Windows.Forms.Button();
            this.capture_btn = new System.Windows.Forms.Button();
            this.stop_btn = new System.Windows.Forms.Button();
            this.live_stop_btn = new System.Windows.Forms.Button();
            this.txtAddress = new System.Windows.Forms.TextBox();
            this.txtPort = new System.Windows.Forms.TextBox();
            this.btnConnect = new System.Windows.Forms.Button();
            this.txtHistory = new System.Windows.Forms.TextBox();
            this.txtTTS = new System.Windows.Forms.TextBox();
            this.btnSend = new System.Windows.Forms.Button();
            this.txtSTT = new System.Windows.Forms.TextBox();
            this.current_Position = new System.Windows.Forms.TextBox();
            this.chang_Position = new System.Windows.Forms.TextBox();
            this.head_format_btn = new System.Windows.Forms.Button();
            this.keep_alive_btn = new System.Windows.Forms.Button();
            this.req_status_btn = new System.Windows.Forms.Button();
            this.homing_btn = new System.Windows.Forms.Button();
            this.move_btn = new System.Windows.Forms.Button();
            this.alarm_btn = new System.Windows.Forms.Button();
            this.glControl1 = new OpenTK.GLControl();
            this.forwardstep = new System.Windows.Forms.Button();
            this.backstep = new System.Windows.Forms.Button();
            this.close_btn = new System.Windows.Forms.Button();
            this.auto_btn = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(12, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(578, 429);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click_1);
            // 
            // init_btn
            // 
            this.init_btn.Location = new System.Drawing.Point(14, 458);
            this.init_btn.Name = "init_btn";
            this.init_btn.Size = new System.Drawing.Size(75, 23);
            this.init_btn.TabIndex = 1;
            this.init_btn.Text = "init";
            this.init_btn.UseVisualStyleBackColor = true;
            this.init_btn.Click += new System.EventHandler(this.init_btn_Click);
            // 
            // start_btn
            // 
            this.start_btn.Location = new System.Drawing.Point(106, 458);
            this.start_btn.Name = "start_btn";
            this.start_btn.Size = new System.Drawing.Size(75, 23);
            this.start_btn.TabIndex = 2;
            this.start_btn.Text = "start";
            this.start_btn.UseVisualStyleBackColor = true;
            this.start_btn.Click += new System.EventHandler(this.start_btn_Click);
            // 
            // live_btn
            // 
            this.live_btn.Location = new System.Drawing.Point(203, 458);
            this.live_btn.Name = "live_btn";
            this.live_btn.Size = new System.Drawing.Size(75, 23);
            this.live_btn.TabIndex = 3;
            this.live_btn.Text = "live";
            this.live_btn.UseVisualStyleBackColor = true;
            this.live_btn.Click += new System.EventHandler(this.live_btn_Click);
            // 
            // capture_btn
            // 
            this.capture_btn.Location = new System.Drawing.Point(203, 501);
            this.capture_btn.Name = "capture_btn";
            this.capture_btn.Size = new System.Drawing.Size(75, 23);
            this.capture_btn.TabIndex = 4;
            this.capture_btn.Text = "capture";
            this.capture_btn.UseVisualStyleBackColor = true;
            this.capture_btn.Click += new System.EventHandler(this.capture_btn_Click);
            // 
            // stop_btn
            // 
            this.stop_btn.Location = new System.Drawing.Point(365, 458);
            this.stop_btn.Name = "stop_btn";
            this.stop_btn.Size = new System.Drawing.Size(75, 23);
            this.stop_btn.TabIndex = 5;
            this.stop_btn.Text = "stop";
            this.stop_btn.UseVisualStyleBackColor = true;
            this.stop_btn.Click += new System.EventHandler(this.stop_btn_Click);
            // 
            // live_stop_btn
            // 
            this.live_stop_btn.Location = new System.Drawing.Point(284, 458);
            this.live_stop_btn.Name = "live_stop_btn";
            this.live_stop_btn.Size = new System.Drawing.Size(75, 23);
            this.live_stop_btn.TabIndex = 6;
            this.live_stop_btn.Text = "live_stop";
            this.live_stop_btn.UseVisualStyleBackColor = true;
            this.live_stop_btn.Click += new System.EventHandler(this.live_stop_btn_Click);
            // 
            // txtAddress
            // 
            this.txtAddress.Location = new System.Drawing.Point(629, 31);
            this.txtAddress.Name = "txtAddress";
            this.txtAddress.Size = new System.Drawing.Size(100, 25);
            this.txtAddress.TabIndex = 7;
            this.txtAddress.Text = "192.168.0.52";
            // 
            // txtPort
            // 
            this.txtPort.Location = new System.Drawing.Point(754, 30);
            this.txtPort.Name = "txtPort";
            this.txtPort.Size = new System.Drawing.Size(100, 25);
            this.txtPort.TabIndex = 8;
            this.txtPort.Text = "5050";
            // 
            // btnConnect
            // 
            this.btnConnect.Location = new System.Drawing.Point(860, 31);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(75, 23);
            this.btnConnect.TabIndex = 9;
            this.btnConnect.Text = "연결";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.OnConnectToServer);
            // 
            // txtHistory
            // 
            this.txtHistory.Location = new System.Drawing.Point(629, 76);
            this.txtHistory.Multiline = true;
            this.txtHistory.Name = "txtHistory";
            this.txtHistory.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txtHistory.Size = new System.Drawing.Size(306, 260);
            this.txtHistory.TabIndex = 10;
            this.txtHistory.TextChanged += new System.EventHandler(this.txtHistory_TextChanged);
            // 
            // txtTTS
            // 
            this.txtTTS.Location = new System.Drawing.Point(629, 343);
            this.txtTTS.Name = "txtTTS";
            this.txtTTS.Size = new System.Drawing.Size(206, 25);
            this.txtTTS.TabIndex = 11;
            // 
            // btnSend
            // 
            this.btnSend.Location = new System.Drawing.Point(842, 343);
            this.btnSend.Name = "btnSend";
            this.btnSend.Size = new System.Drawing.Size(75, 23);
            this.btnSend.TabIndex = 12;
            this.btnSend.Text = "보내기";
            this.btnSend.UseVisualStyleBackColor = true;
            this.btnSend.Click += new System.EventHandler(this.OnSendData);
            // 
            // txtSTT
            // 
            this.txtSTT.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.txtSTT.Location = new System.Drawing.Point(629, 392);
            this.txtSTT.Name = "txtSTT";
            this.txtSTT.ReadOnly = true;
            this.txtSTT.Size = new System.Drawing.Size(206, 25);
            this.txtSTT.TabIndex = 13;
            // 
            // current_Position
            // 
            this.current_Position.Location = new System.Drawing.Point(629, 435);
            this.current_Position.Name = "current_Position";
            this.current_Position.ReadOnly = true;
            this.current_Position.Size = new System.Drawing.Size(157, 25);
            this.current_Position.TabIndex = 14;
            this.current_Position.TextChanged += new System.EventHandler(this.current_Position_TextChanged);
            // 
            // chang_Position
            // 
            this.chang_Position.Location = new System.Drawing.Point(629, 485);
            this.chang_Position.Name = "chang_Position";
            this.chang_Position.Size = new System.Drawing.Size(157, 25);
            this.chang_Position.TabIndex = 15;
            this.chang_Position.Click += new System.EventHandler(this.chang_Position_Click);
            // 
            // head_format_btn
            // 
            this.head_format_btn.Location = new System.Drawing.Point(629, 527);
            this.head_format_btn.Name = "head_format_btn";
            this.head_format_btn.Size = new System.Drawing.Size(75, 23);
            this.head_format_btn.TabIndex = 16;
            this.head_format_btn.Text = "head";
            this.head_format_btn.UseVisualStyleBackColor = true;
            this.head_format_btn.Click += new System.EventHandler(this.head_format_btn_Click);
            // 
            // keep_alive_btn
            // 
            this.keep_alive_btn.Location = new System.Drawing.Point(728, 527);
            this.keep_alive_btn.Name = "keep_alive_btn";
            this.keep_alive_btn.Size = new System.Drawing.Size(75, 23);
            this.keep_alive_btn.TabIndex = 17;
            this.keep_alive_btn.Text = "keepAlive";
            this.keep_alive_btn.UseVisualStyleBackColor = true;
            this.keep_alive_btn.Click += new System.EventHandler(this.keep_alive_btn_Click);
            // 
            // req_status_btn
            // 
            this.req_status_btn.Location = new System.Drawing.Point(823, 527);
            this.req_status_btn.Name = "req_status_btn";
            this.req_status_btn.Size = new System.Drawing.Size(75, 23);
            this.req_status_btn.TabIndex = 18;
            this.req_status_btn.Text = "Req_status";
            this.req_status_btn.UseVisualStyleBackColor = true;
            this.req_status_btn.Click += new System.EventHandler(this.req_status_btn_Click);
            // 
            // homing_btn
            // 
            this.homing_btn.Location = new System.Drawing.Point(629, 557);
            this.homing_btn.Name = "homing_btn";
            this.homing_btn.Size = new System.Drawing.Size(75, 23);
            this.homing_btn.TabIndex = 19;
            this.homing_btn.Text = "Homing";
            this.homing_btn.UseVisualStyleBackColor = true;
            this.homing_btn.Click += new System.EventHandler(this.homing_btn_Click);
            // 
            // move_btn
            // 
            this.move_btn.Location = new System.Drawing.Point(728, 556);
            this.move_btn.Name = "move_btn";
            this.move_btn.Size = new System.Drawing.Size(75, 23);
            this.move_btn.TabIndex = 20;
            this.move_btn.Text = "Move";
            this.move_btn.UseVisualStyleBackColor = true;
            this.move_btn.Click += new System.EventHandler(this.move_btn_Click);
            // 
            // alarm_btn
            // 
            this.alarm_btn.Location = new System.Drawing.Point(823, 556);
            this.alarm_btn.Name = "alarm_btn";
            this.alarm_btn.Size = new System.Drawing.Size(75, 23);
            this.alarm_btn.TabIndex = 21;
            this.alarm_btn.Text = "Alarm";
            this.alarm_btn.UseVisualStyleBackColor = true;
            this.alarm_btn.Click += new System.EventHandler(this.alarm_btn_Click);
            // 
            // glControl1
            // 
            this.glControl1.BackColor = System.Drawing.Color.Black;
            this.glControl1.Location = new System.Drawing.Point(465, 461);
            this.glControl1.Margin = new System.Windows.Forms.Padding(6, 5, 6, 5);
            this.glControl1.Name = "glControl1";
            this.glControl1.Size = new System.Drawing.Size(135, 159);
            this.glControl1.TabIndex = 22;
            this.glControl1.VSync = false;
            this.glControl1.Load += new System.EventHandler(this.glControl1_Load);
            this.glControl1.Paint += new System.Windows.Forms.PaintEventHandler(this.glControl1_Paint);
            this.glControl1.Resize += new System.EventHandler(this.glControl1_Resize);
            // 
            // forwardstep
            // 
            this.forwardstep.Location = new System.Drawing.Point(929, 527);
            this.forwardstep.Name = "forwardstep";
            this.forwardstep.Size = new System.Drawing.Size(75, 23);
            this.forwardstep.TabIndex = 23;
            this.forwardstep.Text = "forwardstep";
            this.forwardstep.UseVisualStyleBackColor = true;
            this.forwardstep.Click += new System.EventHandler(this.forwardstep_Click);
            // 
            // backstep
            // 
            this.backstep.Location = new System.Drawing.Point(929, 556);
            this.backstep.Name = "backstep";
            this.backstep.Size = new System.Drawing.Size(75, 23);
            this.backstep.TabIndex = 24;
            this.backstep.Text = "backstep";
            this.backstep.UseVisualStyleBackColor = true;
            this.backstep.Click += new System.EventHandler(this.backstep_Click);
            // 
            // close_btn
            // 
            this.close_btn.Location = new System.Drawing.Point(942, 31);
            this.close_btn.Name = "close_btn";
            this.close_btn.Size = new System.Drawing.Size(75, 23);
            this.close_btn.TabIndex = 25;
            this.close_btn.Text = "연결해제";
            this.close_btn.UseVisualStyleBackColor = true;
            this.close_btn.Click += new System.EventHandler(this.close_btn_Click);
            // 
            // auto_btn
            // 
            this.auto_btn.Location = new System.Drawing.Point(14, 526);
            this.auto_btn.Name = "auto_btn";
            this.auto_btn.Size = new System.Drawing.Size(75, 23);
            this.auto_btn.TabIndex = 26;
            this.auto_btn.Text = "auto";
            this.auto_btn.UseVisualStyleBackColor = true;
            this.auto_btn.Click += new System.EventHandler(this.auto_btn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1191, 634);
            this.Controls.Add(this.auto_btn);
            this.Controls.Add(this.close_btn);
            this.Controls.Add(this.backstep);
            this.Controls.Add(this.forwardstep);
            this.Controls.Add(this.glControl1);
            this.Controls.Add(this.alarm_btn);
            this.Controls.Add(this.move_btn);
            this.Controls.Add(this.homing_btn);
            this.Controls.Add(this.req_status_btn);
            this.Controls.Add(this.keep_alive_btn);
            this.Controls.Add(this.head_format_btn);
            this.Controls.Add(this.chang_Position);
            this.Controls.Add(this.current_Position);
            this.Controls.Add(this.txtSTT);
            this.Controls.Add(this.btnSend);
            this.Controls.Add(this.txtTTS);
            this.Controls.Add(this.txtHistory);
            this.Controls.Add(this.btnConnect);
            this.Controls.Add(this.txtPort);
            this.Controls.Add(this.txtAddress);
            this.Controls.Add(this.live_stop_btn);
            this.Controls.Add(this.stop_btn);
            this.Controls.Add(this.capture_btn);
            this.Controls.Add(this.live_btn);
            this.Controls.Add(this.start_btn);
            this.Controls.Add(this.init_btn);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.OnFormLoaded);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button init_btn;
        private System.Windows.Forms.Button start_btn;
        private System.Windows.Forms.Button live_btn;
        private System.Windows.Forms.Button capture_btn;
        private System.Windows.Forms.Button stop_btn;
        private System.Windows.Forms.Button live_stop_btn;
        private System.Windows.Forms.TextBox txtAddress;
        private System.Windows.Forms.TextBox txtPort;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.TextBox txtHistory;
        private System.Windows.Forms.TextBox txtTTS;
        private System.Windows.Forms.Button btnSend;
        private System.Windows.Forms.TextBox txtSTT;
        private System.Windows.Forms.TextBox current_Position;
        private System.Windows.Forms.TextBox chang_Position;
        private System.Windows.Forms.Button head_format_btn;
        private System.Windows.Forms.Button keep_alive_btn;
        private System.Windows.Forms.Button req_status_btn;
        private System.Windows.Forms.Button homing_btn;
        private System.Windows.Forms.Button move_btn;
        private System.Windows.Forms.Button alarm_btn;
        private OpenTK.GLControl glControl1;
        private System.Windows.Forms.Button forwardstep;
        private System.Windows.Forms.Button backstep;
        private System.Windows.Forms.Button close_btn;
        private System.Windows.Forms.Button auto_btn;
    }
}

