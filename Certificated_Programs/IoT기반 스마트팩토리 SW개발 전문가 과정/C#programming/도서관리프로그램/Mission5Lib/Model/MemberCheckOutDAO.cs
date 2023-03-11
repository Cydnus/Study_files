using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Data.Entity.Core.Objects;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mission5Lib.Model
{
    public class MemberCheckOutDAO
    {
        private static MemberCheckOutDAO memberCheckOutDAO;
        private MemberCheckOutDAO() { }

        public static MemberCheckOutDAO GetInstance()
        {
            if (memberCheckOutDAO == null)
                memberCheckOutDAO = new MemberCheckOutDAO();

            return memberCheckOutDAO;
        }

        public MemberCheckOut GetCheckOutSummary(int memberId)
        {
            MemberCheckOut info = new MemberCheckOut();

            using (var db = new DataContext())
            {
                var rule = RuleDAO.GetInstance().Get();
                info.NumOfBookCheckOut = db.CheckOuts.Where
                         (p => p.MemberId == memberId && p.ReturnDate == null).Count();
                info.NumOfBookAvailable = rule.NumOfBooksCanCheckOut - info.NumOfBookCheckOut;
                info.NumOfBookOverdue = db.CheckOuts.Where
                         (p => p.MemberId == memberId && p.ReturnDate == null && p.DueDate < DateTime.Today).Count();
                info.DaysOfOverdue = db.CheckOuts.Where
                         (p => p.MemberId == memberId && p.ReturnDate == null && p.DueDate < DateTime.Today).Sum(p => DbFunctions.DiffDays(p.DueDate, DateTime.Today)).GetValueOrDefault(0);
                info.OverdueFee = rule.LateFeePerDay * info.DaysOfOverdue;
            }

            return info;
        }

        public List<BookCopyCheckOut> GetCheckOutBookInfoList(int memberId)
        {
            List<BookCopyCheckOut> list = new List<BookCopyCheckOut>();

            using (var db = new DataContext())
            {
                var checkouts = from p in db.CheckOuts
                                join c in db.BookCopies on p.BookCopyId equals c.Id
                                join b in db.Books on c.BookId equals b.Id
                                where p.MemberId == memberId && p.ReturnDate == null
                                select new { c.BookCopyCode, CheckOutId = p.Id, b.Title, p.CheckOutDate, p.DueDate };

                foreach (var checkout in checkouts.ToList())
                {
                    var info = new BookCopyCheckOut();
                    info.CheckOutId = checkout.CheckOutId;
                    info.BookCopyCode = checkout.BookCopyCode;
                    info.Title = checkout.Title;
                    info.CheckOutDate = checkout.CheckOutDate;
                    info.DueDate = checkout.DueDate;
                    int overdueDays = (int)DateTime.Today.Subtract(checkout.DueDate).TotalDays;
                    info.OverdueDays = overdueDays > 0 ? overdueDays : 0;
                    info.OverdueCharge = info.OverdueDays * RuleDAO.GetInstance().Get().LateFeePerDay;

                    list.Add(info);
                };
            }

            return list;
        }
    }
}
