using SemiProject.Models;
using System;
using System.Linq;
using System.Net.Http;
using System.Security.Cryptography;
using System.Text;
using System.Web.Mvc;
using System.Xml.Linq;

namespace SemiProject.Controllers
{
	public class HomeController : Controller
	{
		MEGADB db = new MEGADB();

		public ActionResult Index()
		{
			ViewBag.Title = "Home Page";
			ViewData["id"] = 0;
			return View();
		}
		string GetMd5Hash( string input)
		{
			MD5 md5Hash = MD5.Create();
			// Convert the input string to a byte array and compute the hash.
			byte[] data = md5Hash.ComputeHash(Encoding.UTF8.GetBytes(input));

			// Create a new Stringbuilder to collect the bytes
			// and create a string.
			StringBuilder sBuilder = new StringBuilder();

			// Loop through each byte of the hashed data 
			// and format each one as a hexadecimal string.
			for (int i = 0; i < data.Length; i++)
			{
				sBuilder.Append(data[i].ToString("x2"));
			}

			// Return the hexadecimal string.
			return sBuilder.ToString();
		}

		public ActionResult Login(string LoginID, string LoginPW)
		{
			if( string.IsNullOrEmpty(LoginID) && string.IsNullOrEmpty(LoginPW))
				return RedirectToAction("index");
			Emp emp = LoginCheck(LoginID.Trim(), GetMd5Hash( LoginPW.Trim()));
		if(emp == null)
			{
				return Content("<script language='javascript' type='text/javascript'> alert('아이디나 비밀번호가 다릅니다.'); " +
					"location.replace(\"index\");</script>");
			}
			else if(emp.UserLevel == 1)
			{
				var branch = db.Works.SingleOrDefault(p => p.UserID == emp.ID);
				if(branch!= null)
				{
					ViewData["id"] =1;
					return RedirectToAction($"../BranchStock/index/{branch.BranchID}");
				}

			}
			else if( emp. UserLevel == 2)
			{
				ViewData["id"] = 2;
				return RedirectToAction($"../OfficeStock/index");

			}
			else
			{
				return Content("<script language='javascript' type='text/javascript'> alert('일반 직원은 접근 할수 없습니다.');location.replace(\"index\"); </script>");

			}


			return RedirectToAction("Index"); ;
		}


		private Emp	LoginCheck(string id, string pw)
		{
			Emp emp = db.Emps.SingleOrDefault(p => p.LoginID == id && p.LoginPW == pw);
			return emp;

		}

	}
}
