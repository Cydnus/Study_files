using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MEGAStore
{
    class SellOrRefund
    {
        public int No { get; set; }
        public int LocalID { get; set; }
        public int ProductId { get; set; }
        public int Count { get; set; }
        public System.DateTime SRDate { get; set; }
        public int TradeNo { get; set; }
        public string Payment { get; set; }
        public Nullable<int> AgeOfCustomer { get; set; }
    }
}
