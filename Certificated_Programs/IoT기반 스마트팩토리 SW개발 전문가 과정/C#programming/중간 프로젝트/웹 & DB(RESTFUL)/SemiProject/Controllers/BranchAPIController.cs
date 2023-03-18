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
using System.Web.Http;

namespace SemiProject.Controllers
{
    public class BranchAPIController : ApiController
    {
        private MEGADB db = new MEGADB();

		//get

		//post

		//update
		public IHttpActionResult Get()
		{
			var branch = db.Branch2.ToList( );
			if ( branch == null )
				return NotFound( );
			return Ok(branch);
		}
		public IHttpActionResult Get(int id)
		{
			Branch2 branch = db.Branch2.Find( id );
			if ( branch == null )
				return NotFound( );

			return Ok( branch );
		}
		public IHttpActionResult Get(string name)
		{
			Branch2 branch = db.Branch2.SingleOrDefault(p => p.Name == name);
			if ( branch == null )
				return NotFound( );

			return Ok( branch );
		}



		//post
		public IHttpActionResult Post(string name, string address)
		{
			Branch2 branch = new Branch2
			{
				Name = name,
				Address = address
			};

			db.Branch2.Add( branch );
			db.SaveChanges( );
			return Ok( );
		}
		public IHttpActionResult Post(string name, string address, string tel)
		{
			Branch2 branch = new Branch2
			{
				Name = name,
				Address = address,
				Tel = tel
			};

			db.Branch2.Add( branch );
			db.SaveChanges( );
			return Ok( );
		}



		//put
		public IHttpActionResult Put(int id, int type, string str)
		{
			Branch2 branch = db.Branch2.Find( id );
			if ( branch == null )
				return NotFound( );

			switch(type)
			{
				case 1:
					branch.Name = str;
					break;
				case 2:
					branch.Address = str;
					break;
				case 3:
					branch.Tel = str;
					break;
			}

			db.SaveChanges( );

			return Ok( );
		}

		public IHttpActionResult Put(Branch2 branch, int type, string str)
		{
			Branch2 local = db.Branch2.Find( branch.Id );

			if ( local == null )
				return NotFound( );

			switch ( type )
			{
				case 1:
					branch.Name = str;
					break;
				case 2:
					branch.Address = str;
					break;
				case 3:
					branch.Tel = str;
					break;
			}


			db.SaveChanges( );

			return Ok( );
		}



	}
}
