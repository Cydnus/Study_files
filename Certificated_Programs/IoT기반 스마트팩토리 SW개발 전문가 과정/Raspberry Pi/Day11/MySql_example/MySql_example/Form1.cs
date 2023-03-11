using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MySql_example
{
    public partial class Form1 : Form
    {
        private DB db;

        //bool DbconnectResult = false;

        public Form1()
        {
            InitializeComponent();
            db = DB.GetInstace;
            db.Connection();

            /*
            DbconnectResult = db.Open();

            if(DbconnectResult)
            {
                MessageBox.Show("DB Open Success");
            }
            else
            {
                MessageBox.Show("DB Open Failure");
            }
            */
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            btnAllSelect_Click(sender, e);
        }
        private void btnProducntInsert_Click(object sender, EventArgs e)
        {

            string strSql = $"insert into InventoryTB values ( '{txtProductNo.Text}'" +
                $" ,'{txtProductName.Text}' " +
                $" ,{txtEa.Text}" +
                $" ,{txtCost.Text}" +
                $" ,'{txtCompany.Text}'" +
                $" ,'{txtEtc.Text}');" ;

            if(db.Sql(strSql))
            {
                strSql = "commit;";
                db.Sql(strSql);
                MessageBox.Show("정상적으로 입력이 되었습니다.");
            }
            else
            {
                MessageBox.Show("일부 입력이 되었거나 입력이 되지 않았습니다.");
            }

            btnAllSelect_Click(sender, e);
        }


        private void btnProductNoSelect_Click(object sender, EventArgs e)
        {
            string strSql = $"select * from inventoryTb where ProductNo like {txtSearch.Text}";
            DataTable dt = db.SqlSelectInventory(strSql);
            if (dt != null)
            {
                dgvProduct.DataSource = dt;
            }
        }

        private void btnProductNameSelect_Click(object sender, EventArgs e)
        {
            string strSql = $"select * from inventoryTb where ProductName like {txtSearch.Text}";
            DataTable dt = db.SqlSelectInventory(strSql);
            if (dt != null)
            {
                dgvProduct.DataSource = dt;
            }
        }

        private void btnCompanySelect_Click(object sender, EventArgs e)
        {
            string strSql = $"select * from inventoryTb where Company like {txtSearch.Text}";
            DataTable dt = db.SqlSelectInventory(strSql);
            if (dt != null)
            {
                dgvProduct.DataSource = dt;
            }
        }

        private void btnAllSelect_Click(object sender, EventArgs e)
        {
            string strSql = "select * from inventoryTb";
            DataTable dt = db.SqlSelectInventory(strSql);
            if (dt != null)
            {
                dgvProduct.DataSource = dt;
            }
        }

        private void btnSearchNo_Click(object sender, EventArgs e)
        {
            string strSql = $"select * from inventoryTb where ProductNo = {txtSearchProductNo.Text}";
            DataTable dt = db.SqlSelectInventory(strSql);
            if (dt != null)
            {
                dgvInventory.DataSource = dt;
            }
        }

        private void dgvInventory_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            txtInputProductNo.Text = dgvInventory.Rows[e.RowIndex].Cells[0].Value.ToString();
            txtInputEa.Text = dgvInventory.Rows[e.RowIndex].Cells[2].Value.ToString();
        }

        private void MainTab_Selected(object sender, TabControlEventArgs e)
        {
            if(e.TabPageIndex == 1)
            {
                string strSql = "select * from inventoryTb";
                DataTable dt = db.SqlSelectInventory(strSql);
                if (dt != null)
                {
                    dgvInventory.DataSource = dt;
                }
            }
        }

        private void btnInsert_Click(object sender, EventArgs e)
        {
            if(txtInputProductNo.Text.Trim() != "" && txtInputEa.Text.Trim() != "")
            {
                string strSql = $"select ProductName, Ea from inventoryTb where ProductNo = {txtInputProductNo.Text}";
                DataTable dt = db.SqlInputUpdate(strSql, int.Parse(txtInputEa.Text));
                if (dt != null)
                {
                    dgvInventory.DataSource = dt;
                }
            }

        }
    }
}
