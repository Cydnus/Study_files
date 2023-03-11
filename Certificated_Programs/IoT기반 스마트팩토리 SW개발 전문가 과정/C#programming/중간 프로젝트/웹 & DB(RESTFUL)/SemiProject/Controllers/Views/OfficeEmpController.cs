using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Threading.Tasks;
using System.Net;
using System.Web;
using System.Web.Mvc;
using SemiProject.Models;

namespace SemiProject.Controllers.Views
{
     public class EmPerson:Emp
	{
          public   string title { get; set; }
          public string branchName { get; set; }
	}

    public class OfficeEmpController : Controller
    {
        private MEGADB db = new MEGADB();

        // GET: OfficeEmp
        public async Task<ActionResult> Index()
          {
               ViewData["id"] = 2;
               List<Emp> temp = await db.Emps.ToListAsync();
               if (temp == null)
                    return View();

               List<EmPerson> list = new List<EmPerson>();

               ViewData["next1"] = "../../OfficeStock";
               ViewData["next2"] = "../../OfficeSOR";
               ViewData["next3"] = "../../OfficeEmp";


               foreach (var item in temp)
               {
                    EmPerson em = new EmPerson
                    {
                         ID = item.ID,
                         LoginID = item.LoginID,
                         LoginPW = item.LoginPW,
                         Name = item.Name,
                         Phone = item.Phone,
                         UserLevel = item.UserLevel,
                    };
                    var work = db.Works.SingleOrDefault(p => p.UserID == item.ID);
                    if ( work == null)
                    {
                         em.branchName = "";
                    }
				else
				{
                    var branch = db.Branch2.Find(work.BranchID);
                         em.branchName = branch.Name;

                    }
                    var titles = db.Titles.Find(item.UserLevel);
                    if (titles == null)
                         em.title = "";
                    else
                         em.title = titles.TitleName; 



                         list.Add(em);
			}




            return View(list);
        }

        // GET: OfficeEmp/Details/5
        public async Task<ActionResult> Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Emp emp = await db.Emps.FindAsync(id);
            if (emp == null)
            {
                return HttpNotFound();
            }
            return View(emp);
        }

        // GET: OfficeEmp/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: OfficeEmp/Create
        // 초과 게시 공격으로부터 보호하려면 바인딩하려는 특정 속성을 사용하도록 설정하세요. 
        // 자세한 내용은 https://go.microsoft.com/fwlink/?LinkId=317598을(를) 참조하세요.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<ActionResult> Create([Bind(Include = "ID,LoginID,LoginPW,Name,Phone,UserLevel")] Emp emp)
        {
            if (ModelState.IsValid)
            {
                db.Emps.Add(emp);
                await db.SaveChangesAsync();
                return RedirectToAction("Index");
            }

            return View(emp);
        }

        // GET: OfficeEmp/Edit/5
        public async Task<ActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Emp emp = await db.Emps.FindAsync(id);
            if (emp == null)
            {
                return HttpNotFound();
            }
            return View(emp);
        }

        // POST: OfficeEmp/Edit/5
        // 초과 게시 공격으로부터 보호하려면 바인딩하려는 특정 속성을 사용하도록 설정하세요. 
        // 자세한 내용은 https://go.microsoft.com/fwlink/?LinkId=317598을(를) 참조하세요.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<ActionResult> Edit([Bind(Include = "ID,LoginID,LoginPW,Name,Phone,UserLevel")] Emp emp)
        {
            if (ModelState.IsValid)
            {
                db.Entry(emp).State = EntityState.Modified;
                await db.SaveChangesAsync();
                return RedirectToAction("Index");
            }
            return View(emp);
        }

        // GET: OfficeEmp/Delete/5
        public async Task<ActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Emp emp = await db.Emps.FindAsync(id);
            if (emp == null)
            {
                return HttpNotFound();
            }
            return View(emp);
        }

        // POST: OfficeEmp/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<ActionResult> DeleteConfirmed(int id)
        {
            Emp emp = await db.Emps.FindAsync(id);
            db.Emps.Remove(emp);
            await db.SaveChangesAsync();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
