using SemiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace SemiProject.Controllers
{
    public class TitleAPIController : ApiController
    {
		MEGADB db = new MEGADB();

		public IHttpActionResult Get(int id)
		{
			Title title = db.Titles.Find(id);
			if (title == null)
				return NotFound();

			return Ok(title.TitleName);
		}

    }
}
