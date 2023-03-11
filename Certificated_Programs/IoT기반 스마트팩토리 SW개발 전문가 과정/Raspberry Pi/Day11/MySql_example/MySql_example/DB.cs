using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;
using System.IO;

using MySql.Data.MySqlClient;
using System.Data;

namespace MySql_example
{
    class DB
    {
        private static DB _db = null;

        private DB() { }

        public static DB GetInstace
        {
            get
            {
                if (_db == null)
                    _db = new DB();
                return _db;
            }
        }
       


        string strServerName = "127.0.0.1";
        string strDatabase = "kcci";
        string strUserID = "pRmSwUf6KdgpvbPLD4CvbA==";
        string strUserPW = "ZM27X7J5KWkpTL7c6IgHqVYl4SwhPLSw";

        MySqlConnection DBconnection;

        bool DbconnectResult = false;

        public void Connection()
        {
            string strCon = $"Server={this.strServerName};Database={this.strDatabase};Uid={Decrypt(this.strUserID)};Pwd={Decrypt(this.strUserPW) };";
            DBconnection = new MySqlConnection(strCon);
        }

        public bool Open()
        {
            try
            {
                DBconnection.Open();
                DbconnectResult = true;
                return true;
            }
            catch(MySqlException ex)
            {
                DbconnectResult = false;
                switch (ex.Number)
                {
                    case 0:
                        break;
                    case 1045:
                        break;
                }
            }
            return false;
        }

     

        public bool Close()
        {
            try
            {
                DBconnection.Close();
                DbconnectResult = false;
                return true;
            }
            catch (MySqlException ex)
            {
                DbconnectResult = false;
                return false;
            }
        }


        public bool Sql( string strSql)
        {
            try
            {
                Open();
                MySqlCommand cmd = new MySqlCommand(strSql, DBconnection);
                cmd.ExecuteNonQuery();
                Close();
                return true;
            }
            catch(Exception ex)
            {
                Close();
                return false;
            }

        }

        public DataTable SqlSelectInventory(string strSQLQuery)
        {
            if( Open() == true)
            {
                MySqlCommand cmd = new MySqlCommand(strSQLQuery, DBconnection);
                MySqlDataAdapter da = new MySqlDataAdapter(cmd);

                DataTable dt = new DataTable();
                da.Fill(dt);
                Close();
                return dt;
            }
            return null;
        }
        public DataTable SqlInputUpdate(string strSQLQuery, int plusEaValue)
        {
            if (Open() == true)
            {
                MySqlCommand cmd = new MySqlCommand(strSQLQuery, DBconnection);
                MySqlDataReader datareader = cmd.ExecuteReader();

                int cEasum = 0;
                int saveEa = 0;
                string strProductName="";
                while (datareader.Read())
                {
                    strProductName = datareader.GetString(0);
                    saveEa = datareader.GetInt32(1);
                    cEasum = saveEa + plusEaValue;
                }
                datareader.Close();
                Close();

                string strQury = $"Update inventoryTb set ea = {cEasum} where Productname = '{strProductName}'";

                Sql(strQury);

            }
            return SqlSelectInventory("select * from inventoryTB;");
        }


        public static string Decrypt(string text)
        {
            byte[] textBytes = Convert.FromBase64String(text);

            byte[] salt = new byte[8];
            byte[] encryptedBytes = new byte[textBytes.Length - salt.Length];
            Array.Copy(textBytes, salt, salt.Length);
            Array.Copy(textBytes, salt.Length, encryptedBytes, 0, encryptedBytes.Length);

            FindKeyAndIV(salt, "kccistc", out byte[] key, out byte[] iv);

            DESCryptoServiceProvider des = new DESCryptoServiceProvider();
            byte[] decryptedBytes = des.CreateDecryptor(key, iv).TransformFinalBlock(encryptedBytes, 0, encryptedBytes.Length);

            return Encoding.UTF8.GetString(decryptedBytes);
        }
        private static void FindKeyAndIV(byte[] salt, String password, out byte[] key, out byte[] iv)
        {
            byte[] passwordBytes = Encoding.UTF8.GetBytes(password);
            byte[] hash = new byte[passwordBytes.Length + salt.Length];
            Array.Copy(passwordBytes, hash, passwordBytes.Length);
            Array.Copy(salt, 0, hash, passwordBytes.Length, salt.Length);

            MD5 md5 = new MD5CryptoServiceProvider();

            //md5 iterations: 1000
            for (int i = 0; i < 1000; i++)
            {
                hash = md5.ComputeHash(hash);
            }

            key = new byte[8];
            iv = new byte[8];
            Array.Copy(hash, 0, key, 0, 8);
            Array.Copy(hash, 8, iv, 0, 8);
        }

    }
}
