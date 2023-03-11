using System;
using System.Windows.Forms;

/*
 * 외부 DB사용(192.168.6.35) 하였으며,
 * sa 계정 비밀번호 "kcci098#" 을 사용하였습니다
 */

namespace Mission5.View
{
	public partial class frmLogin : Form
	{
		public frmLogin()
		{
			InitializeComponent();
		}

		private void btnLogin_Click(object sender, EventArgs e)
		{
			string id = txtLoginId.Text.Trim();
			string pw = txtPassword.Text.Trim();

			if (id != "" && pw != "" && Service.getInstance().LoginCheck(id, pw))
			{
				frmMain.GetInstance().Show();
				this.Hide();
			}
			else
			{
				MessageBox.Show("아이디나 비밀번호가 다릅니다.", "로그인 실패", MessageBoxButtons.OK, MessageBoxIcon.Warning);
			}
		}

		private void btnClose_Click(object sender, EventArgs e)
		{
			this.Close();
		}

	}
}
