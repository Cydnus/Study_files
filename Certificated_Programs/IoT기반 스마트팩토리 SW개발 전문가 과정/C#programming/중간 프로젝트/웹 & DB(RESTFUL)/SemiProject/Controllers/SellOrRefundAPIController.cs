using SemiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace SemiProject.Controllers
{

    public class SellOrRefundAPIController : ApiController
	{
		MEGADB db = new MEGADB();

		//get


		public IHttpActionResult Get(int id)
		{
			if (id == 0)
			{
				var temp = db.SellOrRefunds.ToList();
				if (temp == null)
					return NotFound();
				return Ok(temp);
			}
			SellOrRefund sor = db.SellOrRefunds.Find( id );

			if ( sor == null )
				return NotFound( );

			return Ok( sor );
		}

		public IHttpActionResult Get(Branch2 branch)
		{
			List<SellOrRefund> sor = db.SellOrRefunds.Where( p => p.LocalID == branch.Id ).ToList();
			if ( sor == null )
				return NotFound( );

			return Ok( sor );
		}
		public IHttpActionResult Get(Product product)
		{
			List<SellOrRefund> sor = db.SellOrRefunds.Where( p => p.ProductId == product.Id ).ToList( );
			if ( sor == null )
				return NotFound( );

			return Ok( sor );
		}

		public IHttpActionResult Get(DateTime srdate)
		{
			List<SellOrRefund> sor = db.SellOrRefunds.Where( p => p.SRDate == srdate ).ToList( );
			if ( sor == null )
				return NotFound( );

			return Ok( sor );
		}
		public IHttpActionResult Get(string payType)
		{
			List<SellOrRefund> sor = db.SellOrRefunds.Where( p => p.Payment == payType ).ToList( );
			if ( sor == null )
				return NotFound( );

			return Ok( sor );
		}

		public IHttpActionResult Get(int pbID, int type, DateTime srdate)
		{

			List<SellOrRefund> sor ;
			if(type == 1)
			sor	= db.SellOrRefunds.Where(p => p.SRDate == srdate && pbID == p.LocalID).ToList();
			else
			 sor = db.SellOrRefunds.Where( p => p.SRDate == srdate && pbID == p.ProductId ).ToList( );
			if ( sor == null )
				return NotFound( );

			return Ok( sor );
		}

		public IHttpActionResult Get(Branch2 branch, Product product)
		{
			List<SellOrRefund> sor = db.SellOrRefunds.Where( p => p.LocalID == branch.Id && product.Id == p.ProductId ).ToList( );
			if ( sor == null )
				return NotFound( );

			return Ok( sor );
		}

		public IHttpActionResult Get(Branch2 branch, string pay)
		{
			List<SellOrRefund> sor = db.SellOrRefunds.Where( p => p.Payment == pay && branch.Id == p.LocalID ).ToList( );
			if ( sor == null )
				return NotFound( );

			return Ok( sor );
		}

		public IHttpActionResult Get(DateTime srdate, int tradeNo)
		{
			List<SellOrRefund> sor = db.SellOrRefunds.Where( p => p.SRDate == srdate && p.TradeNo == tradeNo ).ToList( );
			if ( sor == null )
				return NotFound( );

			return Ok( sor );
		}



		//post
		public IHttpActionResult Post(int localid, int productid, int count, string paytype, int tradeNo)
		{
			SellOrRefund sor = new SellOrRefund
			{
				LocalID = localid,
				ProductId = productid,
				Count = count,
				Payment = paytype,
				SRDate = DateTime.UtcNow.AddHours(9),
				TradeNo = tradeNo
			};

			db.SellOrRefunds.Add( sor );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(int localid, int productid, int count, string paytype, int tradeNo, int age)
		{
			SellOrRefund sor = new SellOrRefund
			{
				LocalID = localid,
				ProductId = productid,
				Count = count,
				Payment = paytype,
				TradeNo = tradeNo,
				SRDate = DateTime.UtcNow.AddHours( 9 ),
				AgeOfCustomer = age
			};

			db.SellOrRefunds.Add( sor );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(int localid, Product product, int count, string paytype, int tradeNo)
		{
			SellOrRefund sor = new SellOrRefund
			{
				LocalID = localid,
				ProductId = product.Id,
				Count = count,
				Payment = paytype,
				SRDate = DateTime.UtcNow.AddHours( 9 ),
				TradeNo = tradeNo
			};

			db.SellOrRefunds.Add( sor );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(int localid, Product product, int count, string paytype, int tradeNo, int age)
		{
			SellOrRefund sor = new SellOrRefund
			{
				LocalID = localid,
				ProductId = product.Id,
				Count = count,
				Payment = paytype,
				TradeNo = tradeNo,
				SRDate = DateTime.UtcNow.AddHours( 9 ),
				AgeOfCustomer = age
			};

			db.SellOrRefunds.Add( sor );
			db.SaveChanges( );

			return Ok( );
		}

		public IHttpActionResult Post(Branch2 local, int productid, int count, string paytype, int tradeNo)
		{
			SellOrRefund sor = new SellOrRefund
			{
				LocalID = local.Id,
				ProductId = productid,
				Count = count,
				Payment = paytype,
				SRDate = DateTime.UtcNow.AddHours( 9 ),
				TradeNo = tradeNo
			};

			db.SellOrRefunds.Add( sor );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(Branch2 local, int productid, int count, string paytype, int tradeNo, int age)
		{
			SellOrRefund sor = new SellOrRefund
			{
				LocalID = local.Id,
				ProductId = productid,
				Count = count,
				Payment = paytype,
				SRDate = DateTime.UtcNow.AddHours( 9 ),
				TradeNo = tradeNo,
				AgeOfCustomer = age
			};

			db.SellOrRefunds.Add( sor );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(Branch2 local, Product product, int count, string paytype, int tradeNo)
		{
			SellOrRefund sor = new SellOrRefund
			{
				LocalID = local.Id,
				ProductId = product.Id,
				Count = count,
				Payment = paytype,
				SRDate = DateTime.UtcNow.AddHours( 9 ),
				TradeNo = tradeNo
			};

			db.SellOrRefunds.Add( sor );
			db.SaveChanges( );

			return Ok( );
		}
		public IHttpActionResult Post(Branch2 local, Product product, int count, string paytype, int tradeNo, int age)
		{
			SellOrRefund sor = new SellOrRefund
			{
				LocalID = local.Id,
				ProductId = product.Id,
				Count = count,
				Payment = paytype,
				SRDate = DateTime.UtcNow.AddHours( 9 ),
				TradeNo = tradeNo,
				AgeOfCustomer = age
			};

			db.SellOrRefunds.Add( sor );
			db.SaveChanges( );

			return Ok( );
		}



	}
}
