using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MEGAStore
{
    class Stock
{
        public int No { get; set; }
        public int LocalId { get; set; }
        public int ProductID { get; set; }
        public int Count { get; set; }
        public System.DateTime ExpirationDate { get; set; }
        public System.DateTime ImportDate { get; set; }
        public int ImportId { get; set; }
}
}
