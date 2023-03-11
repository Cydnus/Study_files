using Mission5Lib.Model;
using System;
using System.Collections.Generic;

namespace Mission5
{
	public class Service
	{
		private static Service service;
		public static Service getInstance()
		{
			if (service == null)
			{
				service = new Service();
			}
			return service;
		}

		private Service() { }
		public bool LoginCheck(string id, string pw)
		{
			var login = LibrarianDAO.GetInstance().Get(id);
			try
			{
				if (login.Password == pw)
				{
					return true;
				}
			}
			catch (Exception) { }
			return false;
		}

		public Dictionary<string, string> MemberOn(string id)
		{
			var memberInfo = MemberDAO.GetInstance().Get(id);
			try
			{
				var mcoInfo = MemberCheckOutDAO.GetInstance().GetCheckOutSummary(memberInfo.Id);

				Dictionary<string, string> ret = new Dictionary<string, string>();

				ret.Add("Name", memberInfo.Name);
				ret.Add("PhoNo", memberInfo.PhoneNo);
				ret.Add("NOCO", mcoInfo.NumOfBookCheckOut.ToString());
				ret.Add("NOA", mcoInfo.NumOfBookAvailable.ToString());
				ret.Add("NOO", mcoInfo.NumOfBookOverdue.ToString());
				ret.Add("DOO", mcoInfo.DaysOfOverdue.ToString());
				ret.Add("OF", mcoInfo.OverdueFee.ToString());

				return ret;
			}
			catch (Exception)
			{
				return null;
			}
		}
		public List<BookCopyCheckOut> CheckOutInfo(string id)
		{
			var memberInfo = MemberDAO.GetInstance().Get(id);
			try
			{
				var mcoInfo = MemberCheckOutDAO.GetInstance().GetCheckOutBookInfoList(memberInfo.Id);

				return mcoInfo;
			}
			catch (Exception)
			{
				return null;
			}
		}


		public Dictionary<string, string> GetBookCopyCode(string bookCode)
		{
			var bookCopyInfo = BookCopyDAO.GetInstance().Get(bookCode);
			try
			{
				Dictionary<string, string> ret = new Dictionary<string, string>();

				var bookInfo = BookDAO.GetInstance().Get(bookCopyInfo.BookId);

				ret.Add("Title", bookInfo.Title);
				ret.Add("Publisher", bookInfo.Publisher);
				ret.Add("Available", bookCopyInfo.BookStatus.ToString());
				return ret;
			}
			catch (Exception)
			{
				return null;
			}
		}

		public bool CheckOutBtnState(int to, int nof)
		{
			if (to >= 3 || nof > 0)
			{
				return false;
			}
			return true;
		}

		public bool CheckOutBook(string memberId, string bookCode)
		{
			var bc = BookCopyDAO.GetInstance().Get(bookCode);
			var mem = MemberDAO.GetInstance().Get(memberId);
			try
			{
				CheckOut co = new CheckOut
				{
					BookCopyId = bc.Id,
					CheckOutDate = DateTime.Now,
					DueDate = DateTime.Now.AddDays(7),
					MemberId = mem.Id,
					ReturnDate = null,
					OverdueCharge = null,
					OverdueDays = null,
					LibrarianId = 1
				};
				bc.BookStatus = 1;
				if (CheckOutDAO.GetInstance().Add(co) != DAOResult.Success)
					return false;
				if (BookCopyDAO.GetInstance().Update(bc) != DAOResult.Success)
					return false;

			}
			catch (Exception) { }

			return true;
		}

		public bool ReturnBook(BookCopyCheckOut bcco)
		{
			var ch = CheckOutDAO.GetInstance().Get(bcco.CheckOutId);
			var bc = BookCopyDAO.GetInstance().Get(bcco.BookCopyCode);
			try
			{
				ch.ReturnDate = DateTime.Now;
				ch.OverdueDays = Convert.ToInt32(DateTime.Now.Subtract(ch.CheckOutDate).TotalDays);
				ch.OverdueCharge = ch.OverdueDays * 200;

				bc.BookStatus = 0;

				if (BookCopyDAO.GetInstance().Update(bc) != DAOResult.Success)
					return false;
				if (CheckOutDAO.GetInstance().Update(ch) != DAOResult.Success)
					return false;

				return true;
			}
			catch (Exception)
			{
				return false;
			}

		}

	}
}