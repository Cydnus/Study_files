using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mission5Lib.Model
{
    public class MemberCheckOut
    {
        public int MemberId { get; set; }
        public int NumOfBookCheckOut { get; set; }
        public int NumOfBookAvailable { get; set; }
        public int NumOfBookOverdue { get; set; }
        public int DaysOfOverdue { get; set; }
        public int OverdueFee { get; set; }
    }
}
