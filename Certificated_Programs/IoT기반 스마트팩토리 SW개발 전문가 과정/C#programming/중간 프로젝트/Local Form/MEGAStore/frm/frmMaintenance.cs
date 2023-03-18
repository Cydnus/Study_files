using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MEGAStore.frm
{
    public partial class frmMaintenance : Form
    {
        public frmMaintenance()
        {
            InitializeComponent();
        }

        private void btnEmp_Click(object sender, EventArgs e)
        {
            Form frm = new frm.frmEmpList();
            frm.Show();

        }

        private void btnStock_Click(object sender, EventArgs e)
        {
            Form frm = new frm.frmStock();
            frm.Show();

        }
    }
}
