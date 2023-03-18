using SemiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace SemiProject.Controllers
{
    public class WorkAPIController : ApiController
    {

		MEGADB db = new MEGADB();

		//get
		public IHttpActionResult Get(Emp emp)
		{
			Work work = db.Works.SingleOrDefault(p => p.UserID == emp.ID);
			if (work == null)
				return NotFound();
			return Ok(work);
		}

		public IHttpActionResult Get(Branch2 branch)
		{
			List<Work> work = db.Works.Where(p => p.BranchID == branch.Id).ToList();
			if (work == null)
				return NotFound();
			return Ok(work);
		}

		public IHttpActionResult Get(int id)
		{
			Work work = db.Works.SingleOrDefault(p => p.UserID == id);
			if (work == null)
				return NotFound();
			return Ok(work);
		}

		//post
		public IHttpActionResult Post(Emp emp, Branch2 branch)
		{
			Work work = new Work
			{
				BranchID = branch.Id,
				UserID = emp.ID,
				StartDate = DateTime.UtcNow.AddHours(9)
			};
			db.Works.Add(work);
			db.SaveChanges();
			return Ok();
		}

		//put
		public IHttpActionResult Put(Emp emp, Branch2 branch)
		{
			var temp = db.Works.SingleOrDefault(p => p.UserID == emp.ID);

			if (temp == null)
				return NotFound();
			temp.BranchID = branch.Id;
			db.SaveChanges();

			return Ok();
		}
		public IHttpActionResult Put(Emp emp, int branch)
		{
			var temp = db.Works.SingleOrDefault(p => p.UserID == emp.ID);

			if (temp == null)
				return NotFound();
			temp.BranchID = branch;
			db.SaveChanges();

			return Ok();
		}


		public IHttpActionResult Put(Branch2 branch, Emp oldEmp, Emp newEmp)
		{
			var temp = db.Works.SingleOrDefault(p => p.BranchID == branch.Id && p.UserID == oldEmp.ID);

			if (temp == null)
				return NotFound();
			temp.UserID = newEmp.ID;
			db.SaveChanges();

			return Ok();
		}
		public IHttpActionResult Put(Branch2 branch, int oldEmp, int newEmp)
		{
			var temp = db.Works.SingleOrDefault(p => p.BranchID == branch.Id && p.UserID == oldEmp);


			if (temp == null)
				return NotFound();
			temp.UserID = newEmp;
			db.SaveChanges();

			return Ok();
		}

		//delete
		public IHttpActionResult Delete(Emp emp, Branch2 branch)
		{
			Work work = db.Works.SingleOrDefault(p => p.UserID == emp.ID && branch.Id == p.BranchID);
			if (work == null)
				return NotFound();

			db.Works.Remove(work);

			db.SaveChanges();

			return Ok();
		}
		public IHttpActionResult Delete(int empID, int branchID)
		{
			Work work = db.Works.SingleOrDefault(p => p.UserID == empID && branchID == p.BranchID);
			if (work == null)
				return NotFound();

			db.Works.Remove(work);

			db.SaveChanges();

			return Ok();
		}
		public IHttpActionResult Delete(int empID, Branch2 branch)
		{
			Work work = db.Works.SingleOrDefault(p => p.UserID == empID && branch.Id == p.BranchID);
			if (work == null)
				return NotFound();

			db.Works.Remove(work);

			db.SaveChanges();

			return Ok();
		}
		public IHttpActionResult Delete(Emp emp, int branchID)
		{
			Work work = db.Works.SingleOrDefault(p => p.UserID == emp.ID && branchID == p.BranchID);
			if (work == null)
				return NotFound();

			db.Works.Remove(work);

			db.SaveChanges();

			return Ok();
		}
		public IHttpActionResult Delete(Emp emp)
		{
			Work work = db.Works.SingleOrDefault(p => p.UserID == emp.ID);
			if (work == null)
				return NotFound();

			db.Works.Remove(work);

			db.SaveChanges();

			return Ok();
		}
		public IHttpActionResult Delete(int userid)
		{
			Work work = db.Works.SingleOrDefault(p => p.UserID == userid);
			if (work == null)
				return NotFound();

			db.Works.Remove(work);

			db.SaveChanges();

			return Ok();
		}



	}
}
