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
using System.Runtime.InteropServices;

namespace SemiProject.Controllers.Views
{
     public class BranchStock:Stock
	{
           public string ProductName { get; set; }
           public int price { get; set; }
		public string ImporterName { get; set; }
	}



    public class BranchStockController : Controller
    {
        private MEGADB db = new MEGADB();

        // GET: BranchStock
        public async Task<ActionResult> Index(int id)
        {
               Branch2 b = db.Branch2.Find(id);

               ViewData["id"] = 1;
               List<Stock> dblist = await db.Stocks.Where(p => p.LocalId == id).ToListAsync();

               if ( dblist == null || b == null)
                    return View();


               List<BranchStock> list = new List<BranchStock>();

               ViewData["Name"] = b.Name;
               ViewData["next"] = $"../../branchSor/index/{id}";


               foreach (var item in dblist)
               {
                    var product = db.Products.Find(item.ProductID);
                    var importer = db.Emps.Find(item.ImportId);


                    BranchStock bs = new BranchStock
                    {
                         LocalId = item.LocalId,
                         No = item.No,
                         Count = item.Count,
                         ProductID = item.ProductID,
                         ExpirationDate = item.ExpirationDate,
                         ImportDate = item.ImportDate,
                         ImportId = item.ImportId,
                         ProductName = product.Name,
                         price = product.Price,
                         ImporterName = importer.Name
                    };
                    list.Add(bs);

			}




               return View(list);
        }

        // GET: BranchStock/Details/5
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

        // GET: BranchStock/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: BranchStock/Create
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

        // GET: BranchStock/Edit/5
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

        // POST: BranchStock/Edit/5
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

        // GET: BranchStock/Delete/5
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

        // POST: BranchStock/Delete/5
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
