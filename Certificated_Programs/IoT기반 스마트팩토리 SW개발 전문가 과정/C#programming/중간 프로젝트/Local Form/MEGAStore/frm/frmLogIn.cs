using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Security.Cryptography;
using System.Net.Http;

namespace MEGAStore.frm
{
    public partial class frmLogIn : Form
    {
        public frmLogIn()
        {
            InitializeComponent();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            LogIn();
        }

        private static string GetMd5Hash(MD5 md5Hash, string input)
        {
            byte[] data = md5Hash.ComputeHash(Encoding.UTF8.GetBytes(input));
            StringBuilder sBuilder = new StringBuilder();

            for (int i = 0; i < data.Length; i++) { sBuilder.Append(data[i].ToString("x2")); }

            return sBuilder.ToString();
        }

        private async void LogIn()
        {
            string loginId = txtEmpID.Text;
            string loginPw = txtPassword.Text;

            var mdHash = MD5.Create();
            
            if (loginId != null)
            {
                using (var client = new HttpClient())
                {
                    client.BaseAddress = new Uri("https://megastore.azurewebsites.net/api/");

                    var response = await client.GetAsync($"EmpAPI?ID={loginId}&PW={GetMd5Hash(mdHash, loginPw)}");

                    if (response.IsSuccessStatusCode)
                    {
                        this.Hide();

                        var control = response.Content.ReadAsAsync<Emp>().Result;

                        int id = control.ID;
                        string name = control.Name.ToString();
                        int lv = control.UserLevel;

                        MessageBox.Show($"{name} 님이 접속하였습니다.");

                        Form frm = new frm.frmCounter(id, name, lv);
                        frm.ShowDialog();

                        this.Show();

                        txtEmpID.Text = "";
                        txtPassword.Text = "";
                        txtEmpID.Focus();

                        //this.Close();

                        return ;
                    }
                    MessageBox.Show("로그인에 실패하였습니다.");
                }
            }
        }

    }
}
