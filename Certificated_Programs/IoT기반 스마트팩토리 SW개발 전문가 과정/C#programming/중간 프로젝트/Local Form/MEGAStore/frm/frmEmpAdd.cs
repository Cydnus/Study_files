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
using System.Security.Cryptography;


namespace MEGAStore.frm
{
    public partial class frmEmpAdd : Form
    {
        public frmEmpAdd()
        {
            InitializeComponent();
        }

        private async void AddEmployee()
        {
            var mdHash = MD5.Create();

            using (var client = new HttpClient())
            {
                client.BaseAddress = new Uri("https://megastore.azurewebsites.net/api");

                var emps = new Emp()
                {
                    LoginID = $"{txtLogInID.Text}",
                    LoginPW = $"{GetMd5Hash(mdHash, txtPW.Text)}",
                    Name = $"{txtName.Text}",
                    Phone = $"{txtPhone.Text}",
                    UserLevel = 0
                };

                var response = await client.PostAsJsonAsync(client.BaseAddress + "/EmpAPI", emps);

                if (response.IsSuccessStatusCode)
                {
                    var data = await response.Content.ReadAsStringAsync();
                    MessageBox.Show("추가되었습니다.");
                }
            }
        }

        private object GetMd5Hash(MD5 mdHash, string input)
        {
            byte[] data = mdHash.ComputeHash(Encoding.UTF8.GetBytes(input));
            StringBuilder sBuilder = new StringBuilder();

            for (int i = 0; i < data.Length; i++) { sBuilder.Append(data[i].ToString("x2")); }

            return sBuilder.ToString();
        }

        private void btnAddEmp_Click(object sender, EventArgs e)
        {
            AddEmployee();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
