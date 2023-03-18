
namespace MEGAStore.frm
{
    partial class frmMaintenance
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
            this.btnEmp = new System.Windows.Forms.Button();
            this.btnStock = new System.Windows.Forms.Button();
            this.btnSellOrRefund = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnEmp
            // 
            this.btnEmp.Location = new System.Drawing.Point(12, 12);
            this.btnEmp.Name = "btnEmp";
            this.btnEmp.Size = new System.Drawing.Size(121, 122);
            this.btnEmp.TabIndex = 0;
            this.btnEmp.Text = "직원 관리";
            this.btnEmp.UseVisualStyleBackColor = true;
            this.btnEmp.Click += new System.EventHandler(this.btnEmp_Click);
            // 
            // btnStock
            // 
            this.btnStock.Location = new System.Drawing.Point(139, 12);
            this.btnStock.Name = "btnStock";
            this.btnStock.Size = new System.Drawing.Size(121, 122);
            this.btnStock.TabIndex = 1;
            this.btnStock.Text = "재고 관리";
            this.btnStock.UseVisualStyleBackColor = true;
            this.btnStock.Click += new System.EventHandler(this.btnStock_Click);
            // 
            // btnSellOrRefund
            // 
            this.btnSellOrRefund.Location = new System.Drawing.Point(266, 12);
            this.btnSellOrRefund.Name = "btnSellOrRefund";
            this.btnSellOrRefund.Size = new System.Drawing.Size(121, 122);
            this.btnSellOrRefund.TabIndex = 2;
            this.btnSellOrRefund.Text = "판매 관리";
            this.btnSellOrRefund.UseVisualStyleBackColor = true;
            // 
            // frmMaintenance
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(401, 150);
            this.Controls.Add(this.btnSellOrRefund);
            this.Controls.Add(this.btnStock);
            this.Controls.Add(this.btnEmp);
            this.Name = "frmMaintenance";
            this.Text = "관리자 메뉴";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnEmp;
        private System.Windows.Forms.Button btnStock;
        private System.Windows.Forms.Button btnSellOrRefund;
    }
}