using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mission5Lib.Model
{
    public class BookCopyCheckOut
    {
        public int CheckOutId { get; set; }
        public string BookCopyCode { get; set; }
        public string Title { get; set; }
        public DateTime CheckOutDate { get; set; }
        public DateTime DueDate { get; set; }
        public int OverdueDays { get; set; }
        public int OverdueCharge { get; set; }
    }
}
