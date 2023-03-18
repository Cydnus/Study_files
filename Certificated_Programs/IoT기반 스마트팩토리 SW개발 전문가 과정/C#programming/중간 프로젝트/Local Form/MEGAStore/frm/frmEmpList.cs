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
    public partial class frmEmpList : Form
    {
        public frmEmpList()
        {
            InitializeComponent();
            dgvEmpList.AutoGenerateColumns = false;
        }

        private void txtName_TextChanged(object sender, EventArgs e)
        {
            if (txtName.Text.Trim() == "")
            {
                dgvEmpListLoad();
            }
            else
            {
                string name = txtName.Text;
                dgvEmpSearch(name); 
            }

        }

        private int id = 2;
        private string logInId = "m002";
        private string logInPW = "81DC9BDB52D04DC20036DBD8313ED055";
        private string name = "성시정";
        private string phone = "010-1202-3741";
        private int userLevel= 2;

        private async void UpdateDeviceInfoToServer()
        {
            var emp = new Emp
            {
                ID = id,
                LoginID = logInId,
                LoginPW = logInPW,
                Name = name,
                Phone = phone,
                UserLevel = userLevel
            };

            try
            {
                using (var client = new HttpClient())
                {
                    client.BaseAddress = new Uri("https://megastore.azurewebsites.net/api/");

                    var responce = await client.PutAsJsonAsync("EmpApi", emp);

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

        private async void dgvEmpListLoad()
        {
            using (var client = new HttpClient())
            {
                client.BaseAddress = new Uri("https://megastore.azurewebsites.net/api");

                var response = await client.GetAsync(client.BaseAddress + "/EmpAPI/");

                if (response.IsSuccessStatusCode)
                {
                    //var data = await response.Content.ReadAsStringAsync();
                    //var emps = new List<Emp>();
                    //Newtonsoft.Json.JsonConvert.PopulateObject(data.ToString(), emps);
                    
                    var emps = await response.Content.ReadAsAsync<List<Emp>>();

                    var oldEmps = new List<Emp>();

                    dgvEmpList.DataSource = oldEmps;
                    
                    dgvEmpList.DataSource = emps;
                }
            }
        }

        private void frmEmpList_Load(object sender, EventArgs e)
        {
            dgvEmpListLoad();
        }


        private async void dgvEmpSearch(string name)
        {
            using (var client = new HttpClient())
            {
                client.BaseAddress = new Uri("https://megastore.azurewebsites.net/api");

                var response = await client.GetAsync(client.BaseAddress + $"/EmpAPI?Name={name}");

                if (response.IsSuccessStatusCode)
                {
                    var emps = await response.Content.ReadAsAsync<List<Emp>>();

                    dgvEmpList.DataSource = emps;
                    //var control = await response.Content.ReadAsAsync<Emp>();
                    //var emps = new List<Emp>();
                    //emps.Add(control);

                    //dgvEmpList.DataSource = emps;
                }

            }
        }

        private void btnSearchName_Click(object sender, EventArgs e)
        {
            string name = txtName.Text;
            dgvEmpSearch(name);
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            Form frm = new frm.frmEmpAdd();
            frm.ShowDialog();
            dgvEmpListLoad();
        }
    }
    
}
