
namespace MEGAStore.frm
{
    partial class frmEmpAdd
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmEmpAdd));
            this.pctUser = new System.Windows.Forms.PictureBox();
            this.lblLogInID = new System.Windows.Forms.Label();
            this.lblPW = new System.Windows.Forms.Label();
            this.lblName = new System.Windows.Forms.Label();
            this.grbUser = new System.Windows.Forms.GroupBox();
            this.cmbBranch = new System.Windows.Forms.ComboBox();
            this.lblTitle = new System.Windows.Forms.Label();
            this.lblBranch = new System.Windows.Forms.Label();
            this.txtPhone = new System.Windows.Forms.TextBox();
            this.txtName = new System.Windows.Forms.TextBox();
            this.txtPW = new System.Windows.Forms.TextBox();
            this.txtLogInID = new System.Windows.Forms.TextBox();
            this.lblPhone = new System.Windows.Forms.Label();
            this.cmbTitle = new System.Windows.Forms.ComboBox();
            this.lblAddress = new System.Windows.Forms.Label();
            this.lblNote = new System.Windows.Forms.Label();
            this.txtAddress = new System.Windows.Forms.TextBox();
            this.txtNote = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnAddEmp = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pctUser)).BeginInit();
            this.grbUser.SuspendLayout();
            this.SuspendLayout();
            // 
            // pctUser
            // 
            this.pctUser.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pctUser.InitialImage = ((System.Drawing.Image)(resources.GetObject("pctUser.InitialImage")));
            this.pctUser.Location = new System.Drawing.Point(11, 12);
            this.pctUser.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pctUser.Name = "pctUser";
            this.pctUser.Size = new System.Drawing.Size(188, 248);
            this.pctUser.TabIndex = 0;
            this.pctUser.TabStop = false;
            // 
            // lblLogInID
            // 
            this.lblLogInID.AutoSize = true;
            this.lblLogInID.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblLogInID.Location = new System.Drawing.Point(13, 36);
            this.lblLogInID.Name = "lblLogInID";
            this.lblLogInID.Size = new System.Drawing.Size(69, 20);
            this.lblLogInID.TabIndex = 1;
            this.lblLogInID.Text = "아이디";
            // 
            // lblPW
            // 
            this.lblPW.AutoSize = true;
            this.lblPW.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblPW.Location = new System.Drawing.Point(13, 71);
            this.lblPW.Name = "lblPW";
            this.lblPW.Size = new System.Drawing.Size(89, 20);
            this.lblPW.TabIndex = 2;
            this.lblPW.Text = "비밀번호";
            // 
            // lblName
            // 
            this.lblName.AutoSize = true;
            this.lblName.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblName.Location = new System.Drawing.Point(13, 106);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(49, 20);
            this.lblName.TabIndex = 3;
            this.lblName.Text = "이름";
            // 
            // grbUser
            // 
            this.grbUser.AutoSize = true;
            this.grbUser.Controls.Add(this.cmbBranch);
            this.grbUser.Controls.Add(this.lblTitle);
            this.grbUser.Controls.Add(this.lblBranch);
            this.grbUser.Controls.Add(this.txtPhone);
            this.grbUser.Controls.Add(this.txtName);
            this.grbUser.Controls.Add(this.txtPW);
            this.grbUser.Controls.Add(this.txtLogInID);
            this.grbUser.Controls.Add(this.lblPhone);
            this.grbUser.Controls.Add(this.cmbTitle);
            this.grbUser.Controls.Add(this.lblLogInID);
            this.grbUser.Controls.Add(this.lblName);
            this.grbUser.Controls.Add(this.lblPW);
            this.grbUser.Location = new System.Drawing.Point(216, 2);
            this.grbUser.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.grbUser.Name = "grbUser";
            this.grbUser.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.grbUser.Size = new System.Drawing.Size(243, 258);
            this.grbUser.TabIndex = 0;
            this.grbUser.TabStop = false;
            // 
            // cmbBranch
            // 
            this.cmbBranch.FormattingEnabled = true;
            this.cmbBranch.Location = new System.Drawing.Point(105, 175);
            this.cmbBranch.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cmbBranch.Name = "cmbBranch";
            this.cmbBranch.Size = new System.Drawing.Size(121, 23);
            this.cmbBranch.TabIndex = 4;
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblTitle.Location = new System.Drawing.Point(13, 211);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(49, 20);
            this.lblTitle.TabIndex = 11;
            this.lblTitle.Text = "직책";
            // 
            // lblBranch
            // 
            this.lblBranch.AutoSize = true;
            this.lblBranch.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblBranch.Location = new System.Drawing.Point(13, 176);
            this.lblBranch.Name = "lblBranch";
            this.lblBranch.Size = new System.Drawing.Size(49, 20);
            this.lblBranch.TabIndex = 9;
            this.lblBranch.Text = "소속";
            // 
            // txtPhone
            // 
            this.txtPhone.Location = new System.Drawing.Point(105, 139);
            this.txtPhone.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.txtPhone.Name = "txtPhone";
            this.txtPhone.Size = new System.Drawing.Size(121, 25);
            this.txtPhone.TabIndex = 3;
            // 
            // txtName
            // 
            this.txtName.Location = new System.Drawing.Point(105, 104);
            this.txtName.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(121, 25);
            this.txtName.TabIndex = 2;
            // 
            // txtPW
            // 
            this.txtPW.Location = new System.Drawing.Point(105, 69);
            this.txtPW.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.txtPW.Name = "txtPW";
            this.txtPW.Size = new System.Drawing.Size(121, 25);
            this.txtPW.TabIndex = 1;
            this.txtPW.UseSystemPasswordChar = true;
            // 
            // txtLogInID
            // 
            this.txtLogInID.Location = new System.Drawing.Point(105, 34);
            this.txtLogInID.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.txtLogInID.Name = "txtLogInID";
            this.txtLogInID.Size = new System.Drawing.Size(121, 25);
            this.txtLogInID.TabIndex = 0;
            // 
            // lblPhone
            // 
            this.lblPhone.AutoSize = true;
            this.lblPhone.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblPhone.Location = new System.Drawing.Point(13, 141);
            this.lblPhone.Name = "lblPhone";
            this.lblPhone.Size = new System.Drawing.Size(69, 20);
            this.lblPhone.TabIndex = 4;
            this.lblPhone.Text = "연락처";
            // 
            // cmbTitle
            // 
            this.cmbTitle.FormattingEnabled = true;
            this.cmbTitle.Location = new System.Drawing.Point(105, 210);
            this.cmbTitle.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cmbTitle.Name = "cmbTitle";
            this.cmbTitle.Size = new System.Drawing.Size(121, 23);
            this.cmbTitle.TabIndex = 5;
            // 
            // lblAddress
            // 
            this.lblAddress.AutoSize = true;
            this.lblAddress.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblAddress.Location = new System.Drawing.Point(8, 269);
            this.lblAddress.Name = "lblAddress";
            this.lblAddress.Size = new System.Drawing.Size(49, 20);
            this.lblAddress.TabIndex = 5;
            this.lblAddress.Text = "주소";
            // 
            // lblNote
            // 
            this.lblNote.AutoSize = true;
            this.lblNote.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblNote.Location = new System.Drawing.Point(11, 328);
            this.lblNote.Name = "lblNote";
            this.lblNote.Size = new System.Drawing.Size(49, 20);
            this.lblNote.TabIndex = 6;
            this.lblNote.Text = "메모";
            // 
            // txtAddress
            // 
            this.txtAddress.Location = new System.Drawing.Point(11, 296);
            this.txtAddress.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.txtAddress.Name = "txtAddress";
            this.txtAddress.Size = new System.Drawing.Size(447, 25);
            this.txtAddress.TabIndex = 1;
            // 
            // txtNote
            // 
            this.txtNote.Location = new System.Drawing.Point(11, 355);
            this.txtNote.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.txtNote.Multiline = true;
            this.txtNote.Name = "txtNote";
            this.txtNote.Size = new System.Drawing.Size(447, 83);
            this.txtNote.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Enabled = false;
            this.label1.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.Location = new System.Drawing.Point(82, 126);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 20);
            this.label1.TabIndex = 15;
            this.label1.Text = "사진";
            // 
            // btnCancel
            // 
            this.btnCancel.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnCancel.Location = new System.Drawing.Point(362, 448);
            this.btnCancel.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(97, 41);
            this.btnCancel.TabIndex = 4;
            this.btnCancel.Text = "취소";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnAddEmp
            // 
            this.btnAddEmp.Font = new System.Drawing.Font("굴림", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btnAddEmp.Location = new System.Drawing.Point(11, 448);
            this.btnAddEmp.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnAddEmp.Name = "btnAddEmp";
            this.btnAddEmp.Size = new System.Drawing.Size(344, 41);
            this.btnAddEmp.TabIndex = 3;
            this.btnAddEmp.Text = "새 직원 추가";
            this.btnAddEmp.UseVisualStyleBackColor = true;
            this.btnAddEmp.Click += new System.EventHandler(this.btnAddEmp_Click);
            // 
            // frmEmpAdd
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(471, 498);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnAddEmp);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtNote);
            this.Controls.Add(this.txtAddress);
            this.Controls.Add(this.lblNote);
            this.Controls.Add(this.lblAddress);
            this.Controls.Add(this.pctUser);
            this.Controls.Add(this.grbUser);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmEmpAdd";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "직원 추가";
            ((System.ComponentModel.ISupportInitialize)(this.pctUser)).EndInit();
            this.grbUser.ResumeLayout(false);
            this.grbUser.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pctUser;
        private System.Windows.Forms.Label lblLogInID;
        private System.Windows.Forms.Label lblPW;
        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.GroupBox grbUser;
        private System.Windows.Forms.TextBox txtLogInID;
        private System.Windows.Forms.Label lblPhone;
        private System.Windows.Forms.Label lblAddress;
        private System.Windows.Forms.Label lblNote;
        private System.Windows.Forms.Label lblBranch;
        private System.Windows.Forms.TextBox txtPhone;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.TextBox txtPW;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.TextBox txtAddress;
        private System.Windows.Forms.TextBox txtNote;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cmbTitle;
        private System.Windows.Forms.ComboBox cmbBranch;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnAddEmp;
    }
}