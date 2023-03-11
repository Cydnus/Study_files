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

            string strSql = $"insert into InventoryTB values ( '{txtTab1ProductNo.Text}'" +
                $" ,'{txtTab1ProductName.Text}' " +
                $" ,{txtTab1Ea.Text}" +
                $" ,{txtTab1Cost.Text}" +
                $" ,'{txtTab1Company.Text}'" +
                $" ,'{txtTab1Etc.Text}');" ;

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
            string strSql = $"select * from inventoryTb where ProductNo like {txtTab1Search.Text}";
            DataTable dt = db.SqlSelectAll(strSql);
            if (dt != null)
            {
                dgvTab1Product.DataSource = dt;
            }
        }

        private void btnProductNameSelect_Click(object sender, EventArgs e)
        {
            string strSql = $"select * from inventoryTb where ProductName like {txtTab1Search.Text}";
            DataTable dt = db.SqlSelectAll(strSql);
            if (dt != null)
            {
                dgvTab1Product.DataSource = dt;
            }
        }

        private void btnCompanySelect_Click(object sender, EventArgs e)
        {
            string strSql = $"select * from inventoryTb where Company like {txtTab1Search.Text}";
            DataTable dt = db.SqlSelectAll(strSql);
            if (dt != null)
            {
                dgvTab1Product.DataSource = dt;
            }
        }

        private void btnAllSelect_Click(object sender, EventArgs e)
        {
            string strSql = "select * from inventoryTb";
            DataTable dt = db.SqlSelectAll(strSql);
            if (dt != null)
            {
                dgvTab1Product.DataSource = dt;
            }
        }

        private void btnSearchNo_Click(object sender, EventArgs e)
        {
            string strSql = $"select * from inventoryTb where ProductNo = {txtTab2SearchProductNo.Text}";
            DataTable dt = db.SqlSelectAll(strSql);
            if (dt != null)
            {
                dgvTab2Inventory.DataSource = dt;
            }
        }

        private void dgvInventory_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            txtTab2InputProductNo.Text = dgvTab2Inventory.Rows[e.RowIndex].Cells[0].Value.ToString();
        }

        private void MainTab_Selected(object sender, TabControlEventArgs e)
        {
            if(e.TabPageIndex == 1)
            {
                string strSql = "select * from inventoryTb";
                DataTable dt = db.SqlSelectAll(strSql);
                if (dt != null)
                {
                    dgvTab2Inventory.DataSource = dt;
                }

                string strSql2 = "select * from inputTb";
                DataTable dt2 = db.SqlSelectAll(strSql2);
                if (dt2 != null)
                {
                    dgvTab2Input.DataSource = dt2;
                }
            }
            if (e.TabPageIndex == 2)
            {
                string strSql = "select * from inventoryTb";
                DataTable dt = db.SqlSelectAll(strSql);
                if (dt != null)
                {
                    dgvTab3Inventory.DataSource = dt;
                }

                string strSql2 = "select * from OutputTb";
                DataTable dt2 = db.SqlSelectAll(strSql2);
                if (dt2 != null)
                {
                    dgvTab3Output.DataSource = dt2;
                }
            }
        }

        private void btnInsert_Click(object sender, EventArgs e)
        {
            try
            {
                if(txtTab2InputProductNo.Text.Trim() != "" && txtTab2InputEa.Text.Trim() != "")
                {
                    int iIndexOfProduct = -1;
                    for(int i = 0; i < dgvTab2Inventory.Rows.Count; i++ )
                    {
                        if (dgvTab2Inventory.Rows[i].Cells[0].Value.ToString() == txtTab2InputProductNo.Text)
                        {
                            iIndexOfProduct = i;
                            break;
                        }
                    }

                    string strSql = $"select ProductName, Ea from inventoryTb where ProductNo = {txtTab2InputProductNo.Text}";
                    db.SqlInputUpdate(strSql, int.Parse(txtTab2InputEa.Text));

                    strSql = $"insert into InputTb(ProductNo,ProductName,EA,InputDate) values(" +
                        $"'{txtTab2InputProductNo.Text}'," +
                        $"'{dgvTab2Inventory.Rows[iIndexOfProduct].Cells[1].Value.ToString()}'," +
                        $"{int.Parse(txtTab2InputEa.Text)}," +
                        $"'{DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss")}');";

                    db.Sql(strSql);


                    strSql = "select * from inventoryTb";
                    DataTable dt = db.SqlSelectAll(strSql);
                    if (dt != null)
                    {
                        dgvTab2Inventory.DataSource = dt;
                    }

                    strSql = "select * from inputTb";
                    DataTable dt2 = db.SqlSelectAll(strSql);
                    if (dt2 != null)
                    {
                        dgvTab2Input.DataSource = dt2;
                    }

                }
            }
            catch(Exception)
            {
                string strSql = $"undo;";
                db.Sql(strSql);

            }
            txtTab2InputProductNo.Text = "";
            txtTab2InputEa.Text = "";
        }

        private void btnTab3SearchProductNo_Click(object sender, EventArgs e)
        {
            string strSql = $"select * from inventoryTb where ProductNo = {txtTab3SearchProductNo.Text}";
            DataTable dt = db.SqlSelectAll(strSql);
            if (dt != null)
            {
                dgvTab3Inventory.DataSource = dt;
            }

        }

        private void btnTab3Output_Click(object sender, EventArgs e)
        {
            try
            {
                if (txtTab3OutputProductNo.Text.Trim() != "" && txtTab3OutputEa.Text.Trim() != "")
                {
                    int iIndexOfProduct = -1;
                    for (int i = 0; i < dgvTab3Inventory.Rows.Count; i++)
                    {
                        if (dgvTab3Inventory.Rows[i].Cells[0].Value.ToString() == txtTab3OutputProductNo.Text)
                        {
                            iIndexOfProduct = i;
                            break;
                        }
                    }

                    string strSql = $"select ProductName, Ea from inventoryTb where ProductNo = {txtTab3OutputProductNo.Text}";
                    if (db.SqlOutputUpdate(strSql, int.Parse(txtTab3OutputEa.Text)) == false)
                    {
                        MessageBox.Show("재고가 부족합니다", "",MessageBoxButtons.OK,MessageBoxIcon.Error);
                        return;
                    }

                    strSql = $"insert into OutputTb(ProductNo,ProductName,EA,outputDate) values(" +
                        $"'{txtTab3OutputProductNo.Text}'," +
                        $"'{dgvTab3Inventory.Rows[iIndexOfProduct].Cells[1].Value.ToString()}'," +
                        $"{int.Parse(txtTab3OutputEa.Text)}," +
                        $"'{DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss")}');";

                    db.Sql(strSql);


                    strSql = "select * from inventoryTb";
                    DataTable dt = db.SqlSelectAll(strSql);
                    if (dt != null)
                    {
                        dgvTab3Inventory.DataSource = dt;
                    }

                    strSql = "select * from outputTb";
                    DataTable dt2 = db.SqlSelectAll(strSql);
                    if (dt2 != null)
                    {
                        dgvTab3Output.DataSource = dt2;
                    }

                }
            }
            catch (Exception)
            {
                string strSql = $"undo;";
                db.Sql(strSql);

            }
            txtTab2InputProductNo.Text = "";
            txtTab2InputEa.Text = "";
        }

        private void dgvTab3Inventory_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            txtTab3OutputProductNo.Text = dgvTab3Inventory.Rows[e.RowIndex].Cells[0].Value.ToString();
            txtTab3OutputEa.Text = dgvTab3Inventory.Rows[e.RowIndex].Cells[2].Value.ToString();

        }

        private void btnTab4Search_Click(object sender, EventArgs e)
        {
   
            string[] strarrayTabel = {"InputTb", "OutputTb" };
            string[] strarrayDate = {"InputDate", "OutputDate" };
            int iIndex = 0;
            if (cbTab4Table.SelectedItem == null || txtTab4PostDate.Text == "" || txtTab4PreDate.Text == "")
            {
                MessageBox.Show("빈칸이 존재합니다.");
                return;
            }
            string strSql = "select * from ";

            if (cbTab4Table.SelectedItem.ToString() != "")
            {
                strSql += strarrayTabel[cbTab4Table.SelectedIndex];
                iIndex = cbTab4Table.SelectedIndex;
            }

            string strPreDate = DateTime.Parse(txtTab4PreDate.Text).ToString("yyyy-MM-dd");
            string strPostDate = DateTime.Parse(txtTab4PostDate.Text).ToString("yyyy-MM-dd");


            strSql += $" where  {strarrayDate[iIndex]} between " +
                $"'{strPreDate}' and '{strPostDate}' ";


            if ( rbTab4GroupProductName.Checked )
                strSql += " Group by ProductName";

            if(rbTab4SortAsc.Checked)
                strSql += $" order by ea asc";
            else if (rbTab4SortDesc.Checked)
                strSql += $" order by ea desc";

            strSql += ";";
            DataTable dt = db.SqlSelectAll(strSql);
            if (dt != null)
            {
                dgvTab4Result.DataSource = dt;
            }

        }
    }
}
