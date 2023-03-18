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
    public partial class frmStock : Form
    {

        private int localid;
        private int productid;
        private int count;
        private DateTime expirationdate;
        private DateTime importdate;
        private int importid;
        public frmStock()
        {
            InitializeComponent();
            dgvStockList.AutoGenerateColumns = false;
        }
        private async void UpdateDeviceInfoToServer()
        {
            var stock = new Stock
            {
                LocalId = localid,
                ProductID = productid,
                Count = count,
                ExpirationDate = expirationdate,
                ImportDate = importdate,
                ImportId = importid
            };

            try
            {
                using (var client = new HttpClient())
                {
                    client.BaseAddress = new Uri("https://megastore.azurewebsites.net/api");
                    var responce = await client.PutAsJsonAsync("StockApi", stock);

                    if (!responce.IsSuccessStatusCode)
                    {
                        MessageBox.Show(responce.StatusCode.ToString());
                    }
                }
            }
            catch (Exception ex)
            {

                MessageBox.Show(ex.Message);
            }
        }

      
        private async void dgvStockListLoad()
        {
            using (var client = new HttpClient())
            {
                client.BaseAddress = new Uri("https://megastore.azurewebsites.net/api");

                var response = await client.GetAsync(client.BaseAddress + "/StockAPI?ID=0");

                if (response.IsSuccessStatusCode)
                {
                    var stocks = await response.Content.ReadAsAsync<List<Stock>>();

                    var oldStocks = new List<Stock>();

                    dgvStockList.DataSource = oldStocks ;

                    dgvStockList.DataSource = stocks ;
                }
            }
        }
               
        private void frmStock_Load(object sender, EventArgs e)
        {
            dgvStockListLoad();
        }
    }

    
}
