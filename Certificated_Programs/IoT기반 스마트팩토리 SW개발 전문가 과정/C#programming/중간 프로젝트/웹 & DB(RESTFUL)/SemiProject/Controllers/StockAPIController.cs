using SemiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace SemiProject.Controllers
{
    public class StockAPIController : ApiController
	{
		MEGADB db = new MEGADB();

		//get
		public IHttpActionResult Get(int id)
		{
			if(id == 0)
			{
				var stockList = db.Stocks.ToList();
				if (stockList == null)
					return NotFound();

				return Ok(stockList);
			}
			var stock = db.Stocks.Find( id );
			if ( stock == null )
				return NotFound( );

			return Ok( stock );
		}
		public IHttpActionResult Get(Branch2 branch)
		{
			var stock = db.Stocks.Where( p => p.LocalId == branch.Id ).ToList();
			if ( stock == null )
				return NotFound( );

			return Ok( stock );
		}
		public IHttpActionResult Get(Product product)
		{
			var stock = db.Stocks.Where( p => p.ProductID == product.Id ).ToList( );
			if ( stock == null )
				return NotFound( );

			return Ok( stock );
		}
		public IHttpActionResult Get(Emp emp)
		{
			var stock = db.Stocks.Where( p => p.ImportId == emp.ID ).ToList();
			if ( stock == null )
				return NotFound( );

			return Ok( stock );
		}
		public IHttpActionResult Get(int localid, int productId)
		{
			var stock = db.Stocks.Where(p => p.LocalId == localid && p.ProductID == productId ).ToList();
			if ( stock == null )
				return NotFound( );

			return Ok( stock );
		}

		//post

		public IHttpActionResult Post(int localId, int productId, int count, int importID, DateTime eDate)
		{
			Stock stock = new Stock
			{
				LocalId = localId,
				ProductID = productId,
				Count = count,
				ImportId = importID,
				ExpirationDate = eDate,
				ImportDate = DateTime.UtcNow.AddHours( 9 )
			};

			db.Stocks.Add( stock );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(int localId, int productId, int count, Emp emp, DateTime eDate)
		{
			Stock stock = new Stock
			{
				LocalId = localId,
				ProductID = productId,
				Count = count,
				ImportId = emp.ID,
				ExpirationDate = eDate,
				ImportDate = DateTime.UtcNow.AddHours( 9 )
			};

			db.Stocks.Add( stock );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(int localId, Product product, int count, int importID, DateTime eDate)
		{
			Stock stock = new Stock
			{
				LocalId = localId,
				ProductID = product.Id,
				Count = count,
				ImportId = importID,
				ExpirationDate = eDate,
				ImportDate = DateTime.UtcNow.AddHours( 9 )
			};

			db.Stocks.Add( stock );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(int localId, Product product, int count, Emp emp, DateTime eDate)
		{
			Stock stock = new Stock
			{
				LocalId = localId,
				ProductID = product.Id,
				Count = count,
				ImportId = emp.ID,
				ExpirationDate = eDate,
				ImportDate = DateTime.UtcNow.AddHours( 9 )
			};

			db.Stocks.Add( stock );
			db.SaveChanges( );

			return Ok( );
		}

		public IHttpActionResult Post(Branch2 local, int productId, int count, int importID, DateTime eDate )
		{
			Stock stock = new Stock
			{
				LocalId = local.Id,
				ProductID = productId,
				Count = count,
				ImportId = importID,
				ExpirationDate = eDate,
				ImportDate = DateTime.UtcNow.AddHours( 9 )
			};

			db.Stocks.Add( stock );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(Branch2 local, int productId, int count, Emp emp, DateTime eDate)
		{
			Stock stock = new Stock
			{
				LocalId = local.Id,
				ProductID = productId,
				Count = count,
				ImportId = emp.ID,
				ExpirationDate = eDate,
				ImportDate = DateTime.UtcNow.AddHours( 9 )
			};

			db.Stocks.Add( stock );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(Branch2 local, Product product, int count, int importID, DateTime eDate)
		{
			Stock stock = new Stock
			{
				LocalId = local.Id,
				ProductID = product.Id,
				Count = count,
				ImportId = importID,
				ExpirationDate = eDate,
				ImportDate = DateTime.UtcNow.AddHours( 9 )
			};

			db.Stocks.Add( stock );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(Branch2 local, Product product, int count, Emp emp, DateTime eDate)
		{
			Stock stock = new Stock
			{
				LocalId = local.Id,
				ProductID = product.Id,
				Count = count,
				ImportId = emp.ID,
				ExpirationDate = eDate,
				ImportDate = DateTime.UtcNow.AddHours( 9 )
			};

			db.Stocks.Add( stock );
			db.SaveChanges( );

			return Ok( );
		}



		//put
		public IHttpActionResult Put(int id, int count)
		{
			var stock = db.Stocks.Find( id );

			if ( stock == null )
				return NotFound( );

			stock.Count = count;
			db.SaveChanges( );

			return Ok();
		}
		public IHttpActionResult Put(Stock stock, int count)
		{
			var newStock = db.Stocks.Find( stock.No );

			if ( newStock == null )
				return NotFound( );

			newStock.Count = count;
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Put(int localId, int productId, int count)
		{
			var stock = db.Stocks.SingleOrDefault( p => p.LocalId == localId && p.ProductID == productId );

			if ( stock == null )
				return NotFound( );

			stock.Count = count;
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Put(int localId, Product product, int count)
		{
			var stock = db.Stocks.SingleOrDefault( p => p.LocalId == localId && p.ProductID == product.Id );

			if ( stock == null )
				return NotFound( );

			stock.Count = count;
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Put(Branch2 local, int productId, int count)
		{
			var stock = db.Stocks.SingleOrDefault( p => p.LocalId == local.Id && p.ProductID == productId );

			if ( stock == null )
				return NotFound( );

			stock.Count = count;
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Put(Branch2 local, Product product, int count)
		{
			var stock = db.Stocks.SingleOrDefault( p => p.LocalId == local.Id && p.ProductID == product.Id );

			if ( stock == null )
				return NotFound( );

			stock.Count = count;
			db.SaveChanges( );

			return Ok( );
		}



		//get

		//post

		//update

	}
}
