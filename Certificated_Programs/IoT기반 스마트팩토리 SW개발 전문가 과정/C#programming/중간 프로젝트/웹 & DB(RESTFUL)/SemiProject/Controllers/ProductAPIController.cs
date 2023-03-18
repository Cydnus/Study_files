using SemiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using System.Xml.Linq;

namespace SemiProject.Controllers
{
    public class ProductAPIController : ApiController
	{
		private MEGADB db = new MEGADB();

		//get
		public IHttpActionResult Get(int id)
		{
			if( id == 0)
			{
				var temp = db.Products.ToList();
				if (temp == null)
					return NotFound();
				return Ok(temp);
			}

			Product product = db.Products.Find(id);
			if (product == null)
				return NotFound();
			return Ok(product);
		}

		public IHttpActionResult Get(Item item)
		{
			List<Product> product = db.Products.Where(p => p.ItemID == item.ID).ToList();
			if (product == null)
				return NotFound();
			return Ok(product);
		}

		public IHttpActionResult Get(string name)
		{
			Product product = db.Products.SingleOrDefault(p => p.Name == name);
			if (product == null)
				return NotFound();
			return Ok(product);
		}


		//post
		public IHttpActionResult Post(string name, int itemNo, int price)
		{
			Product product = new Product
			{
				Name = name,
				ItemID = itemNo,
				Price = price
			};

			db.Products.Add( product );
			db.SaveChanges( );

			return Ok( );
		}

		public IHttpActionResult Post(string name, int itemNo, int price, string maker)
		{
			Product product = new Product
			{
				Name = name,
				ItemID = itemNo,
				Price = price,
				Maker = maker
			};

			db.Products.Add( product );
			db.SaveChanges( );

			return Ok( );
		}

		public IHttpActionResult Post(string name, Item itemNo, int price)
		{
			Product product = new Product
			{
				Name = name,
				ItemID = itemNo.ID,
				Price = price
			};

			db.Products.Add( product );
			db.SaveChanges( );

			return Ok( );
		}

		public IHttpActionResult Post(string name, Item itemNo, int price, string maker)
		{
			Product product = new Product
			{
				Name = name,
				ItemID = itemNo.ID,
				Price = price,
				Maker = maker
			};

			db.Products.Add( product );
			db.SaveChanges( );

			return Ok( );
		}

		//put
		public IHttpActionResult Put(int id , int price)
{

			Product product = db.Products.Find( id ); 
			if ( product == null )
				return NotFound( );

			product.Price = price;
			db.SaveChanges( );

			return Ok();
		}
		public IHttpActionResult Put(string name, int price)
		{

			Product product = db.Products.SingleOrDefault( p => p.Name == name );
			if ( product == null )
				return NotFound( );

			product.Price = price;
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Put(Product products, int price)
		{

			Product product = db.Products.Find( products .Id );
			if ( product == null )
				return NotFound( );

			product.Price = price;
			db.SaveChanges( );

			return Ok( );
		}




	}
}
