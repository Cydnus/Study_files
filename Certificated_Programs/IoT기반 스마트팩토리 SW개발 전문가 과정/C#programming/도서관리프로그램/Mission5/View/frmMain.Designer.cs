
namespace Mission5.View
{
	partial class frmMain
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.lblNumOfOverdue = new System.Windows.Forms.Label();
			this.lblNumOfCheckOut = new System.Windows.Forms.Label();
			this.lblMemberName = new System.Windows.Forms.Label();
			this.lblOverdueFee = new System.Windows.Forms.Label();
			this.lblDaysOfOverdue = new System.Windows.Forms.Label();
			this.lblNumOfAvailable = new System.Windows.Forms.Label();
			this.lblMemberPhone = new System.Windows.Forms.Label();
			this.btnSearchMember = new System.Windows.Forms.Button();
			this.txtMember = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.label9 = new System.Windows.Forms.Label();
			this.label8 = new System.Windows.Forms.Label();
			this.label5 = new System.Windows.Forms.Label();
			this.label7 = new System.Windows.Forms.Label();
			this.label6 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.btnSearchBookCopy = new System.Windows.Forms.Button();
			this.label10 = new System.Windows.Forms.Label();
			this.lblTitle = new System.Windows.Forms.Label();
			this.label12 = new System.Windows.Forms.Label();
			this.label11 = new System.Windows.Forms.Label();
			this.txtBookCopyCode = new System.Windows.Forms.TextBox();
			this.lblPublisher = new System.Windows.Forms.Label();
			this.btnCheckOut = new System.Windows.Forms.Button();
			this.btnReturn = new System.Windows.Forms.Button();
			this.dgvBookList = new System.Windows.Forms.DataGridView();
			this.Column7 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.Column2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.Column3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.Column4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.Column5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.Column6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.btnClose = new System.Windows.Forms.Button();
			this.groupBox1.SuspendLayout();
			this.groupBox2.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.dgvBookList)).BeginInit();
			this.SuspendLayout();
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.lblNumOfOverdue);
			this.groupBox1.Controls.Add(this.lblNumOfCheckOut);
			this.groupBox1.Controls.Add(this.lblMemberName);
			this.groupBox1.Controls.Add(this.lblOverdueFee);
			this.groupBox1.Controls.Add(this.lblDaysOfOverdue);
			this.groupBox1.Controls.Add(this.lblNumOfAvailable);
			this.groupBox1.Controls.Add(this.lblMemberPhone);
			this.groupBox1.Controls.Add(this.btnSearchMember);
			this.groupBox1.Controls.Add(this.txtMember);
			this.groupBox1.Controls.Add(this.label4);
			this.groupBox1.Controls.Add(this.label9);
			this.groupBox1.Controls.Add(this.label8);
			this.groupBox1.Controls.Add(this.label5);
			this.groupBox1.Controls.Add(this.label7);
			this.groupBox1.Controls.Add(this.label6);
			this.groupBox1.Controls.Add(this.label3);
			this.groupBox1.Controls.Add(this.label2);
			this.groupBox1.Controls.Add(this.label1);
			this.groupBox1.Font = new System.Drawing.Font("메이플스토리", 8F);
			this.groupBox1.Location = new System.Drawing.Point(13, 13);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(434, 330);
			this.groupBox1.TabIndex = 0;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "회원 정보";
			// 
			// lblNumOfOverdue
			// 
			this.lblNumOfOverdue.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.lblNumOfOverdue.Font = new System.Drawing.Font("메이플스토리", 12F);
			this.lblNumOfOverdue.Location = new System.Drawing.Point(147, 212);
			this.lblNumOfOverdue.Name = "lblNumOfOverdue";
			this.lblNumOfOverdue.Size = new System.Drawing.Size(259, 29);
			this.lblNumOfOverdue.TabIndex = 10;
			this.lblNumOfOverdue.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblNumOfCheckOut
			// 
			this.lblNumOfCheckOut.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.lblNumOfCheckOut.Font = new System.Drawing.Font("메이플스토리", 12F);
			this.lblNumOfCheckOut.Location = new System.Drawing.Point(147, 140);
			this.lblNumOfCheckOut.Name = "lblNumOfCheckOut";
			this.lblNumOfCheckOut.Size = new System.Drawing.Size(259, 29);
			this.lblNumOfCheckOut.TabIndex = 10;
			this.lblNumOfCheckOut.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblMemberName
			// 
			this.lblMemberName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.lblMemberName.Font = new System.Drawing.Font("메이플스토리", 12F);
			this.lblMemberName.Location = new System.Drawing.Point(147, 53);
			this.lblMemberName.Name = "lblMemberName";
			this.lblMemberName.Size = new System.Drawing.Size(259, 29);
			this.lblMemberName.TabIndex = 10;
			this.lblMemberName.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblOverdueFee
			// 
			this.lblOverdueFee.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.lblOverdueFee.Font = new System.Drawing.Font("메이플스토리", 12F);
			this.lblOverdueFee.Location = new System.Drawing.Point(147, 283);
			this.lblOverdueFee.Name = "lblOverdueFee";
			this.lblOverdueFee.Size = new System.Drawing.Size(259, 29);
			this.lblOverdueFee.TabIndex = 9;
			this.lblOverdueFee.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblDaysOfOverdue
			// 
			this.lblDaysOfOverdue.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.lblDaysOfOverdue.Font = new System.Drawing.Font("메이플스토리", 12F);
			this.lblDaysOfOverdue.Location = new System.Drawing.Point(147, 248);
			this.lblDaysOfOverdue.Name = "lblDaysOfOverdue";
			this.lblDaysOfOverdue.Size = new System.Drawing.Size(259, 29);
			this.lblDaysOfOverdue.TabIndex = 9;
			this.lblDaysOfOverdue.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblNumOfAvailable
			// 
			this.lblNumOfAvailable.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.lblNumOfAvailable.Font = new System.Drawing.Font("메이플스토리", 12F);
			this.lblNumOfAvailable.Location = new System.Drawing.Point(147, 176);
			this.lblNumOfAvailable.Name = "lblNumOfAvailable";
			this.lblNumOfAvailable.Size = new System.Drawing.Size(259, 29);
			this.lblNumOfAvailable.TabIndex = 9;
			this.lblNumOfAvailable.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblMemberPhone
			// 
			this.lblMemberPhone.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.lblMemberPhone.Font = new System.Drawing.Font("메이플스토리", 12F);
			this.lblMemberPhone.Location = new System.Drawing.Point(147, 89);
			this.lblMemberPhone.Name = "lblMemberPhone";
			this.lblMemberPhone.Size = new System.Drawing.Size(259, 29);
			this.lblMemberPhone.TabIndex = 9;
			this.lblMemberPhone.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// btnSearchMember
			// 
			this.btnSearchMember.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.btnSearchMember.Location = new System.Drawing.Point(307, 22);
			this.btnSearchMember.Name = "btnSearchMember";
			this.btnSearchMember.Size = new System.Drawing.Size(99, 27);
			this.btnSearchMember.TabIndex = 8;
			this.btnSearchMember.Text = "조   회";
			this.btnSearchMember.UseVisualStyleBackColor = true;
			this.btnSearchMember.Click += new System.EventHandler(this.btnSearchMember_Click);
			// 
			// txtMember
			// 
			this.txtMember.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.txtMember.Location = new System.Drawing.Point(147, 23);
			this.txtMember.Name = "txtMember";
			this.txtMember.Size = new System.Drawing.Size(154, 26);
			this.txtMember.TabIndex = 6;
			// 
			// label4
			// 
			this.label4.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
			this.label4.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label4.Location = new System.Drawing.Point(6, 128);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(420, 2);
			this.label4.TabIndex = 2;
			// 
			// label9
			// 
			this.label9.BackColor = System.Drawing.Color.Yellow;
			this.label9.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label9.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label9.Location = new System.Drawing.Point(17, 212);
			this.label9.Name = "label9";
			this.label9.Size = new System.Drawing.Size(124, 28);
			this.label9.TabIndex = 5;
			this.label9.Text = "총 연체권수";
			this.label9.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label8
			// 
			this.label8.BackColor = System.Drawing.Color.Yellow;
			this.label8.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label8.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label8.Location = new System.Drawing.Point(17, 176);
			this.label8.Name = "label8";
			this.label8.Size = new System.Drawing.Size(124, 28);
			this.label8.TabIndex = 4;
			this.label8.Text = "대출 가능";
			this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label5
			// 
			this.label5.BackColor = System.Drawing.Color.Yellow;
			this.label5.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label5.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label5.Location = new System.Drawing.Point(17, 284);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(124, 28);
			this.label5.TabIndex = 4;
			this.label5.Text = "연체료";
			this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label7
			// 
			this.label7.BackColor = System.Drawing.Color.Yellow;
			this.label7.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label7.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label7.Location = new System.Drawing.Point(17, 140);
			this.label7.Name = "label7";
			this.label7.Size = new System.Drawing.Size(124, 28);
			this.label7.TabIndex = 3;
			this.label7.Text = "총 대출";
			this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label6
			// 
			this.label6.BackColor = System.Drawing.Color.Yellow;
			this.label6.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label6.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label6.Location = new System.Drawing.Point(17, 248);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(124, 28);
			this.label6.TabIndex = 3;
			this.label6.Text = "총 연체일";
			this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label3
			// 
			this.label3.BackColor = System.Drawing.Color.Yellow;
			this.label3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label3.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label3.Location = new System.Drawing.Point(17, 91);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(124, 28);
			this.label3.TabIndex = 2;
			this.label3.Text = "전화번호";
			this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label2
			// 
			this.label2.BackColor = System.Drawing.Color.Yellow;
			this.label2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label2.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label2.Location = new System.Drawing.Point(17, 55);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(124, 28);
			this.label2.TabIndex = 1;
			this.label2.Text = "이   름";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label1
			// 
			this.label1.BackColor = System.Drawing.Color.Yellow;
			this.label1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label1.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label1.Location = new System.Drawing.Point(17, 21);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(124, 28);
			this.label1.TabIndex = 0;
			this.label1.Text = "회원 아이디";
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// groupBox2
			// 
			this.groupBox2.Controls.Add(this.btnSearchBookCopy);
			this.groupBox2.Controls.Add(this.label10);
			this.groupBox2.Controls.Add(this.lblTitle);
			this.groupBox2.Controls.Add(this.label12);
			this.groupBox2.Controls.Add(this.label11);
			this.groupBox2.Controls.Add(this.txtBookCopyCode);
			this.groupBox2.Controls.Add(this.lblPublisher);
			this.groupBox2.Font = new System.Drawing.Font("메이플스토리", 8F);
			this.groupBox2.Location = new System.Drawing.Point(454, 13);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(404, 130);
			this.groupBox2.TabIndex = 1;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "도서 정보";
			// 
			// btnSearchBookCopy
			// 
			this.btnSearchBookCopy.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.btnSearchBookCopy.Location = new System.Drawing.Point(278, 20);
			this.btnSearchBookCopy.Name = "btnSearchBookCopy";
			this.btnSearchBookCopy.Size = new System.Drawing.Size(99, 27);
			this.btnSearchBookCopy.TabIndex = 8;
			this.btnSearchBookCopy.Text = "조   회";
			this.btnSearchBookCopy.UseVisualStyleBackColor = true;
			this.btnSearchBookCopy.Click += new System.EventHandler(this.btnSearchBookCopy_Click);
			// 
			// label10
			// 
			this.label10.BackColor = System.Drawing.Color.Yellow;
			this.label10.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label10.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label10.Location = new System.Drawing.Point(6, 90);
			this.label10.Name = "label10";
			this.label10.Size = new System.Drawing.Size(123, 28);
			this.label10.TabIndex = 8;
			this.label10.Text = "출 판 사";
			this.label10.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblTitle
			// 
			this.lblTitle.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.lblTitle.Font = new System.Drawing.Font("메이플스토리", 12F);
			this.lblTitle.Location = new System.Drawing.Point(135, 53);
			this.lblTitle.Name = "lblTitle";
			this.lblTitle.Size = new System.Drawing.Size(242, 29);
			this.lblTitle.TabIndex = 10;
			this.lblTitle.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label12
			// 
			this.label12.BackColor = System.Drawing.Color.Yellow;
			this.label12.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label12.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label12.Location = new System.Drawing.Point(6, 20);
			this.label12.Name = "label12";
			this.label12.Size = new System.Drawing.Size(123, 28);
			this.label12.TabIndex = 6;
			this.label12.Text = "도서등록번호";
			this.label12.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label11
			// 
			this.label11.BackColor = System.Drawing.Color.Yellow;
			this.label11.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label11.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.label11.Location = new System.Drawing.Point(6, 54);
			this.label11.Name = "label11";
			this.label11.Size = new System.Drawing.Size(123, 28);
			this.label11.TabIndex = 7;
			this.label11.Text = "도 서 명";
			this.label11.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// txtBookCopyCode
			// 
			this.txtBookCopyCode.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.txtBookCopyCode.Location = new System.Drawing.Point(135, 20);
			this.txtBookCopyCode.Name = "txtBookCopyCode";
			this.txtBookCopyCode.Size = new System.Drawing.Size(137, 26);
			this.txtBookCopyCode.TabIndex = 6;
			// 
			// lblPublisher
			// 
			this.lblPublisher.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.lblPublisher.Font = new System.Drawing.Font("메이플스토리", 12F);
			this.lblPublisher.Location = new System.Drawing.Point(135, 89);
			this.lblPublisher.Name = "lblPublisher";
			this.lblPublisher.Size = new System.Drawing.Size(242, 29);
			this.lblPublisher.TabIndex = 9;
			this.lblPublisher.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// btnCheckOut
			// 
			this.btnCheckOut.Enabled = false;
			this.btnCheckOut.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.btnCheckOut.Image = ((System.Drawing.Image)(resources.GetObject("btnCheckOut.Image")));
			this.btnCheckOut.Location = new System.Drawing.Point(473, 190);
			this.btnCheckOut.Name = "btnCheckOut";
			this.btnCheckOut.Size = new System.Drawing.Size(170, 99);
			this.btnCheckOut.TabIndex = 9;
			this.btnCheckOut.Text = "대 출";
			this.btnCheckOut.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
			this.btnCheckOut.UseVisualStyleBackColor = true;
			this.btnCheckOut.Click += new System.EventHandler(this.btnCheckOut_Click);
			// 
			// btnReturn
			// 
			this.btnReturn.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.btnReturn.Image = ((System.Drawing.Image)(resources.GetObject("btnReturn.Image")));
			this.btnReturn.Location = new System.Drawing.Point(675, 190);
			this.btnReturn.Name = "btnReturn";
			this.btnReturn.Size = new System.Drawing.Size(167, 99);
			this.btnReturn.TabIndex = 10;
			this.btnReturn.Text = "반 납";
			this.btnReturn.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
			this.btnReturn.UseVisualStyleBackColor = true;
			this.btnReturn.Click += new System.EventHandler(this.btnReturn_Click);
			// 
			// dgvBookList
			// 
			this.dgvBookList.AllowUserToAddRows = false;
			this.dgvBookList.AllowUserToDeleteRows = false;
			this.dgvBookList.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dgvBookList.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column7,
            this.Column1,
            this.Column2,
            this.Column3,
            this.Column4,
            this.Column5,
            this.Column6});
			this.dgvBookList.Location = new System.Drawing.Point(13, 349);
			this.dgvBookList.Name = "dgvBookList";
			this.dgvBookList.ReadOnly = true;
			this.dgvBookList.RowHeadersWidth = 51;
			this.dgvBookList.RowTemplate.Height = 27;
			this.dgvBookList.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
			this.dgvBookList.Size = new System.Drawing.Size(878, 201);
			this.dgvBookList.TabIndex = 11;
			// 
			// Column7
			// 
			this.Column7.DataPropertyName = "CheckOutId";
			this.Column7.HeaderText = "checkoutID";
			this.Column7.MinimumWidth = 6;
			this.Column7.Name = "Column7";
			this.Column7.ReadOnly = true;
			this.Column7.Visible = false;
			this.Column7.Width = 125;
			// 
			// Column1
			// 
			this.Column1.DataPropertyName = "BookCopyCode";
			this.Column1.HeaderText = "도서등록번호";
			this.Column1.MinimumWidth = 6;
			this.Column1.Name = "Column1";
			this.Column1.ReadOnly = true;
			this.Column1.Width = 125;
			// 
			// Column2
			// 
			this.Column2.DataPropertyName = "Title";
			this.Column2.HeaderText = "도서명";
			this.Column2.MinimumWidth = 6;
			this.Column2.Name = "Column2";
			this.Column2.ReadOnly = true;
			this.Column2.Width = 125;
			// 
			// Column3
			// 
			this.Column3.DataPropertyName = "CheckOutDate";
			this.Column3.HeaderText = "대출일자";
			this.Column3.MinimumWidth = 6;
			this.Column3.Name = "Column3";
			this.Column3.ReadOnly = true;
			this.Column3.Width = 125;
			// 
			// Column4
			// 
			this.Column4.DataPropertyName = "DueDate";
			this.Column4.HeaderText = "반납예정";
			this.Column4.MinimumWidth = 6;
			this.Column4.Name = "Column4";
			this.Column4.ReadOnly = true;
			this.Column4.Width = 125;
			// 
			// Column5
			// 
			this.Column5.DataPropertyName = "OverdueDays";
			this.Column5.HeaderText = "연체일";
			this.Column5.MinimumWidth = 6;
			this.Column5.Name = "Column5";
			this.Column5.ReadOnly = true;
			this.Column5.Width = 125;
			// 
			// Column6
			// 
			this.Column6.DataPropertyName = "OverdueCharge";
			this.Column6.HeaderText = "연체료";
			this.Column6.MinimumWidth = 6;
			this.Column6.Name = "Column6";
			this.Column6.ReadOnly = true;
			this.Column6.Width = 125;
			// 
			// btnClose
			// 
			this.btnClose.Font = new System.Drawing.Font("메이플스토리", 10F);
			this.btnClose.Image = ((System.Drawing.Image)(resources.GetObject("btnClose.Image")));
			this.btnClose.Location = new System.Drawing.Point(390, 556);
			this.btnClose.Name = "btnClose";
			this.btnClose.Size = new System.Drawing.Size(123, 42);
			this.btnClose.TabIndex = 12;
			this.btnClose.Text = "닫 기";
			this.btnClose.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
			this.btnClose.UseVisualStyleBackColor = true;
			this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
			// 
			// frmMain
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(903, 610);
			this.Controls.Add(this.btnClose);
			this.Controls.Add(this.dgvBookList);
			this.Controls.Add(this.btnReturn);
			this.Controls.Add(this.btnCheckOut);
			this.Controls.Add(this.groupBox2);
			this.Controls.Add(this.groupBox1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "frmMain";
			this.Text = "도서 대출/반납";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmMain_FormClosing);
			this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.frmMain_FormClosed);
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.groupBox2.ResumeLayout(false);
			this.groupBox2.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.dgvBookList)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.Button btnSearchMember;
		private System.Windows.Forms.TextBox txtMember;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label label9;
		private System.Windows.Forms.Label label8;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.Label label7;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.Button btnSearchBookCopy;
		private System.Windows.Forms.Label label10;
		private System.Windows.Forms.Label label12;
		private System.Windows.Forms.Label label11;
		private System.Windows.Forms.TextBox txtBookCopyCode;
		private System.Windows.Forms.Button btnCheckOut;
		private System.Windows.Forms.Button btnReturn;
		private System.Windows.Forms.DataGridView dgvBookList;
		private System.Windows.Forms.Button btnClose;
		private System.Windows.Forms.Label lblNumOfOverdue;
		private System.Windows.Forms.Label lblNumOfCheckOut;
		private System.Windows.Forms.Label lblMemberName;
		private System.Windows.Forms.Label lblDaysOfOverdue;
		private System.Windows.Forms.Label lblNumOfAvailable;
		private System.Windows.Forms.Label lblMemberPhone;
		private System.Windows.Forms.Label lblOverdueFee;
		private System.Windows.Forms.Label lblTitle;
		private System.Windows.Forms.Label lblPublisher;
		private System.Windows.Forms.DataGridViewTextBoxColumn Column7;
		private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
		private System.Windows.Forms.DataGridViewTextBoxColumn Column2;
		private System.Windows.Forms.DataGridViewTextBoxColumn Column3;
		private System.Windows.Forms.DataGridViewTextBoxColumn Column4;
		private System.Windows.Forms.DataGridViewTextBoxColumn Column5;
		private System.Windows.Forms.DataGridViewTextBoxColumn Column6;
	}
}