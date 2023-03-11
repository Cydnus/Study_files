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
     public class OfficeViewStock : Stock
     {
          public string ProductName { get; set; }
          public string LocalName { get; set; }

     }
     public class OfficeStockController : Controller
    {
        private MEGADB db = new MEGADB();

    
        // GET: OfficeStock
        public async Task<ActionResult> Index()
          {
               ViewData["id"] = 2;
               var temp = await db.Stocks.ToListAsync();
               if(temp== null)
			{
                    return View();
			}
               List<OfficeViewStock> list= new List<OfficeViewStock>();
               ViewData["next2"] = "../../OfficeSOR";
               ViewData["next3"] = "../../OfficeEmp";

               foreach (var item in temp)
			{
                    var product = db.Products.Find(item.ProductID);
                    var local = db.Branch2.Find(item.LocalId);

                    OfficeViewStock vs = new OfficeViewStock
                    {
                         LocalId = item.LocalId,
                         No = item.No,
                         Count = item.Count,
                         ProductID = item.ProductID,
                         ExpirationDate = item.ExpirationDate,
                         ImportDate = item.ImportDate,
                         ImportId = item.ImportId,
                         ProductName = product.Name,
                         LocalName = local.Name
                    };
                    list.Add(vs);
                   

			}
               list.Sort(
                    (x, y) =>
				{
                         return x.LocalId - y.LocalId;
				}
                    )  ;


            return View(list);
        }

        // GET: OfficeStock/Details/5
        public async Task<ActionResult> Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Stock stock = await db.Stocks.FindAsync(id);
            if (stock == null)
            {
                return HttpNotFound();
            }
            return View(stock);
        }

        // GET: OfficeStock/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: OfficeStock/Create
        // 초과 게시 공격으로부터 보호하려면 바인딩하려는 특정 속성을 사용하도록 설정하세요. 
        // 자세한 내용은 https://go.microsoft.com/fwlink/?LinkId=317598을(를) 참조하세요.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<ActionResult> Create([Bind(Include = "No,LocalId,ProductID,Count,ExpirationDate,ImportDate,ImportId")] Stock stock)
        {
            if (ModelState.IsValid)
            {
                db.Stocks.Add(stock);
                await db.SaveChangesAsync();
                return RedirectToAction("Index");
            }

            return View(stock);
        }

        // GET: OfficeStock/Edit/5
        public async Task<ActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Stock stock = await db.Stocks.FindAsync(id);
            if (stock == null)
            {
                return HttpNotFound();
            }
            return View(stock);
        }

        // POST: OfficeStock/Edit/5
        // 초과 게시 공격으로부터 보호하려면 바인딩하려는 특정 속성을 사용하도록 설정하세요. 
        // 자세한 내용은 https://go.microsoft.com/fwlink/?LinkId=317598을(를) 참조하세요.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<ActionResult> Edit([Bind(Include = "No,LocalId,ProductID,Count,ExpirationDate,ImportDate,ImportId")] Stock stock)
        {
            if (ModelState.IsValid)
            {
                db.Entry(stock).State = EntityState.Modified;
                await db.SaveChangesAsync();
                return RedirectToAction("Index");
            }
            return View(stock);
        }

        // GET: OfficeStock/Delete/5
        public async Task<ActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Stock stock = await db.Stocks.FindAsync(id);
            if (stock == null)
            {
                return HttpNotFound();
            }
            return View(stock);
        }

        // POST: OfficeStock/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<ActionResult> DeleteConfirmed(int id)
        {
            Stock stock = await db.Stocks.FindAsync(id);
            db.Stocks.Remove(stock);
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
