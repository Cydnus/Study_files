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

     public class BSOR:SellOrRefund
	{
	//	public string LocalName { get; set; }
          public string ProductName { get; set; }
          public int Price { get; set; }
          public int Total { get; set; }

     }

    public class BranchSORController : Controller
    {
        private MEGADB db = new MEGADB();


        // GET: BranchSOR
        public async Task<ActionResult> Index(int id)
        {

               ViewData["id"] = 1;

               List<SellOrRefund> sorList = await db.SellOrRefunds.Where(p => p.LocalID == id).ToListAsync();

               var branch = await db.Branch2.FindAsync(id);

               if(sorList == null || branch == null)
                    return View();


               ViewData["Name"] = branch.Name;
               ViewData["next"] = $"../../branchStock/index/{id}";

               List<BSOR> list = new List<BSOR>();

			foreach (var item in sorList)
			{
                    Product product = db.Products.Find(item.ProductId);


                    BSOR bSOR = new BSOR
                    {
                         No = item.No,
                         LocalID = item.LocalID,
                         Count = item.Count,
                         Payment = item.Payment,
                         SRDate = item.SRDate,
                         TradeNo = item.TradeNo,
                         ProductId = item.ProductId,
                         ProductName = product.Name,
                         Price = product.Price,
                         Total = product.Price * item.Count
                    };

                    list.Add(bSOR);
               }

               list.Sort((x, y) => { return x.No - y.No; });



               return View(list);
        }

        // GET: BranchSOR/Details/5
        public async Task<ActionResult> Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            SellOrRefund sellOrRefund = await db.SellOrRefunds.FindAsync(id);
            if (sellOrRefund == null)
            {
                return HttpNotFound();
            }
            return View(sellOrRefund);
        }

        // GET: BranchSOR/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: BranchSOR/Create
        // 초과 게시 공격으로부터 보호하려면 바인딩하려는 특정 속성을 사용하도록 설정하세요. 
        // 자세한 내용은 https://go.microsoft.com/fwlink/?LinkId=317598을(를) 참조하세요.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<ActionResult> Create([Bind(Include = "No,LocalID,ProductId,Count,SRDate,TradeNo,Payment,AgeOfCustomer")] SellOrRefund sellOrRefund)
        {
            if (ModelState.IsValid)
            {
                db.SellOrRefunds.Add(sellOrRefund);
                await db.SaveChangesAsync();
                return RedirectToAction("Index");
            }

            return View(sellOrRefund);
        }

        // GET: BranchSOR/Edit/5
        public async Task<ActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            SellOrRefund sellOrRefund = await db.SellOrRefunds.FindAsync(id);
            if (sellOrRefund == null)
            {
                return HttpNotFound();
            }
            return View(sellOrRefund);
        }

        // POST: BranchSOR/Edit/5
        // 초과 게시 공격으로부터 보호하려면 바인딩하려는 특정 속성을 사용하도록 설정하세요. 
        // 자세한 내용은 https://go.microsoft.com/fwlink/?LinkId=317598을(를) 참조하세요.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<ActionResult> Edit([Bind(Include = "No,LocalID,ProductId,Count,SRDate,TradeNo,Payment,AgeOfCustomer")] SellOrRefund sellOrRefund)
        {
            if (ModelState.IsValid)
            {
                db.Entry(sellOrRefund).State = EntityState.Modified;
                await db.SaveChangesAsync();
                return RedirectToAction("Index");
            }
            return View(sellOrRefund);
        }

        // GET: BranchSOR/Delete/5
        public async Task<ActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            SellOrRefund sellOrRefund = await db.SellOrRefunds.FindAsync(id);
            if (sellOrRefund == null)
            {
                return HttpNotFound();
            }
            return View(sellOrRefund);
        }

        // POST: BranchSOR/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<ActionResult> DeleteConfirmed(int id)
        {
            SellOrRefund sellOrRefund = await db.SellOrRefunds.FindAsync(id);
            db.SellOrRefunds.Remove(sellOrRefund);
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
