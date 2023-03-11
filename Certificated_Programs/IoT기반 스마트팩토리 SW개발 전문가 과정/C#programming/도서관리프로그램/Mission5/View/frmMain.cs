using Mission5Lib.Model;
using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace Mission5.View
{
	public partial class frmMain : Form
	{
		private static frmMain main;

		public static frmMain GetInstance()
		{
			if (main == null)
				main = new frmMain();
			return main;
		}

		private frmMain()
		{
			InitializeComponent();
		}

		private void btnSearchMember_Click(object sender, EventArgs e)
		{
			RefreshMember();
		}
		private void RefreshMember()
		{

			string id = txtMember.Text.Trim();
			if (string.IsNullOrEmpty(id))
			{
				MessageBox.Show("회원 아이디를 입력하세요.", "회원 조회 오류", MessageBoxButtons.OK, MessageBoxIcon.Warning);
				return;
			}

			var info = Service.getInstance().MemberOn(id);

			if (info != null)
			{
				lblMemberName.Text = info["Name"];
				lblMemberPhone.Text = info["PhoNo"];
				lblNumOfCheckOut.Text = info["NOCO"];
				lblNumOfAvailable.Text = info["NOA"];
				lblNumOfOverdue.Text = info["NOO"];
				lblDaysOfOverdue.Text = info["DOO"];
				lblOverdueFee.Text = info["OF"];

				RefreshGrid();
			}
			else
			{
				MessageBox.Show("입력한 아이디에 해당하는 회원이 존재하지 않습니다.", "회원 조회 오류", MessageBoxButtons.OK, MessageBoxIcon.Warning);
			}
		}

		private bool RefreshGrid()
		{

			string id = txtMember.Text.Trim();

			if (string.IsNullOrEmpty(id))
			{
				return false;
			}

			dgvBookList.AutoGenerateColumns = false;
			dgvBookList.DataSource = Service.getInstance().CheckOutInfo(id);

			if (((List<BookCopyCheckOut>)dgvBookList.DataSource).Count == 0)
			{
				btnReturn.Enabled = false;
			}
			else
			{
				btnReturn.Enabled = true;
			}
			return true;

		}

		private void btnSearchBookCopy_Click(object sender, EventArgs e)
		{
			string bookCode = txtBookCopyCode.Text.Trim();
			var info = Service.getInstance().GetBookCopyCode(bookCode);

			if (info != null)
			{
				if (Convert.ToInt32(info["Available"]) == 1)
				{
					btnCheckOut.Enabled = false;
					MessageBox.Show("이미 대출중인 도서 이므로 대출할 수 없습니다", "도서 대출 오류", MessageBoxButtons.OK, MessageBoxIcon.Warning);

					lblTitle.Text = "";
					lblPublisher.Text = "";
					return;
				}

				lblTitle.Text = info["Title"];
				lblPublisher.Text = info["Publisher"];

				btnCheckOut.Enabled = IsCheckOutBtnEnable();


			}
			else
			{
				MessageBox.Show("입력한 도서등록번호에 해당하는 도서가 존재하지 않습니다.", "도서 조회오류",
					MessageBoxButtons.OK, MessageBoxIcon.Warning);
			}
		}

		private bool IsCheckOutBtnEnable()
		{
			int totalCheckOut = Convert.ToInt32(lblNumOfCheckOut.Text);
			int numOfOverdue = Convert.ToInt32(lblNumOfOverdue.Text);

			return Service.getInstance().CheckOutBtnState(totalCheckOut, numOfOverdue);

		}


		private void btnCheckOut_Click(object sender, EventArgs e)
		{
			if (Service.getInstance().CheckOutBook(txtMember.Text, txtBookCopyCode.Text))
			{
				MessageBox.Show("성공적으로 대출이 되었습니다!", "대출 성공");
			}
			else
			{
				MessageBox.Show("대출에 실패하였습니다!", "대출 실패");
			}
			RefreshMember();

			btnCheckOut.Enabled = IsCheckOutBtnEnable();

		}

		private void btnReturn_Click(object sender, EventArgs e)
		{
			var bcco = new BookCopyCheckOut
			{
				CheckOutId = Convert.ToInt32(dgvBookList.CurrentRow.Cells[0].Value),
				BookCopyCode = dgvBookList.CurrentRow.Cells[1].Value.ToString(),
				Title = dgvBookList.CurrentRow.Cells[2].Value.ToString(),
				CheckOutDate = Convert.ToDateTime(dgvBookList.CurrentRow.Cells[3].Value),
				DueDate = Convert.ToDateTime(dgvBookList.CurrentRow.Cells[4].Value),
				OverdueDays = Convert.ToInt32(dgvBookList.CurrentRow.Cells[5].Value),
				OverdueCharge = Convert.ToInt32(dgvBookList.CurrentRow.Cells[6].Value)
			};

			if (Service.getInstance().ReturnBook(bcco))
			{
				MessageBox.Show("성공적으로 반납이 되었습니다!", "반납 성공");
			}
			else
			{
				MessageBox.Show("반납에 실패하였습니다!", "반납 실패");
			}

			RefreshGrid();
			RefreshMember();
		}

		private void btnClose_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void frmMain_FormClosed(object sender, FormClosedEventArgs e)
		{
			main = null;
			Application.Exit();
		}

		private void frmMain_FormClosing(object sender, FormClosingEventArgs e)
		{
			if (MessageBox.Show("프로그램을 종료 하시겠습니까?", "종료 확인", MessageBoxButtons.YesNo, MessageBoxIcon.Information) != DialogResult.Yes)
			{
				e.Cancel = true;
			}
		}

	}
}
