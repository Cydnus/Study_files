using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MEGAStore.frm
{
    public partial class frmCounter : Form
    {
        List<Counter> counters = new List<Counter>();

        private string item ;
        private int count ;
        private int total = 0 ;

        public frmCounter(int id, string name, int lv)
        {
            InitializeComponent();
            this.Text = $"카운터 - {name}" ;
            lblID.Text = id.ToString();
            lblLV.Text = lv.ToString();

            dgvItemList.AutoGenerateColumns = false;

            if (lv >= 1)
                btnMaintenance.Enabled = true;

            lblTotal.Text = $"{0.ToString("#,0")}";
            lblDiscount.Text = $"{0.ToString("#,0")}";
            lblReceive.Text = $"{0.ToString("#,0")}";
            lblChange.Text = $"{0.ToString("#,0")}";
        }


        private async void dgvAddItem()
        {
            item = txtItem.Text;
            

            using (var client = new HttpClient())
            {
                client.BaseAddress = new Uri("https://megastore.azurewebsites.net/api");

                var response = await client.GetAsync(client.BaseAddress + $"/ProductAPI/{item}");

                if (response.IsSuccessStatusCode)
                {
                    var oldProduct = new List<Counter>(); 

                    var control = await response.Content.ReadAsAsync<Counter>();

                    control.count = 1;
                    control.sum = control.count * control.Price ;
                    counters.Add(control);
                    
                    total += control.sum ;
                    
                    dgvItemList.DataSource = oldProduct;
                }
            }  ;

            dgvItemList.DataSource = counters;
            
            count = dgvItemList.Rows.Count;
            
            dgvItemList.FirstDisplayedScrollingRowIndex = count-1;
            lblTotal.Text = total.ToString("#,0");
        }

        private void btnEnter_Click(object sender, EventArgs e)
        {
            if (txtItem.Text.Trim() != "")
            {
                dgvAddItem();
            }
        }

        private void btnMaintenance_Click(object sender, EventArgs e)
        {
            Form frm = new frm.frmMaintenance();
            frm.ShowDialog();

            this.Show();
        }

        private void btnCount_Click(object sender, EventArgs e)
        {
            
        }
    }
}
