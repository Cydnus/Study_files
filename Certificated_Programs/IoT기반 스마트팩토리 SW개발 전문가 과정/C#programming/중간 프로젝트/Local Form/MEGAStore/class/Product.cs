using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MEGAStore
{
    class Product
    {
        public int Id { get; set; }
        public int ItemID { get; set; }
        public string Maker { get; set; }
        public Nullable<System.DateTime> ProductionDate { get; set; }
        public int Price { get; set; }
        public string Name { get; set; }
    }
}
