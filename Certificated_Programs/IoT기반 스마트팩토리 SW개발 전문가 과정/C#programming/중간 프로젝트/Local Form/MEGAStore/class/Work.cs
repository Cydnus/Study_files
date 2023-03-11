using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MEGAStore
{
    class Work
    {
        public int id { get; set; }
        public int UserID { get; set; }
        public int BranchID { get; set; }
        public Nullable<System.DateTime> StartDate { get; set; }
    }
}
