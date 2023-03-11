using SemiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace SemiProject.Controllers
{
    public class ItemAPIController : ApiController
	{
		MEGADB db = new MEGADB();

		//get
		public IHttpActionResult Get(int id)
		{
			Item item = db.Items.Find(id);
			if (item == null)
				return NotFound();

			return Ok(item);
		}
		public IHttpActionResult Get(Product product)
		{
			Item item = db.Items.Find(product.ItemID);
			if (item == null)
				return NotFound();

			return Ok(item);
		}

		//post
		public IHttpActionResult Post(string name)
		{
			Item item = new Item
			{
				Name = name
			};
			db.Items.Add(item);

			db.SaveChanges();

			return Ok();
		}

		//put
		public IHttpActionResult Put(int id, string name)
		{
			Item item = db.Items.Find(id);

			if (item == null)
				return NotFound();

			item.Name = name;

			db.SaveChanges();

			return Ok();
		}


	}
}
