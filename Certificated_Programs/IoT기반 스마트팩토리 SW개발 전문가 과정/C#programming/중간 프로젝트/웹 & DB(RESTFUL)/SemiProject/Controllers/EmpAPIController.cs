using SemiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Http;
using System.Web.Mvc;

namespace SemiProject.Controllers
{
    public class EmpAPIController : ApiController
    {
          private MEGADB mdb = new MEGADB();
          //get          /API/empapi?id=~&pw=~
          public  IHttpActionResult Get(string id, string pw )
		{
               Emp emp = mdb.Emps.SingleOrDefault(p => p.LoginID == id && p.LoginPW == pw);
               
               if(emp==null )
			{
                    return NotFound();
			}

               return Ok(emp);
          }

          public IHttpActionResult Get(int id)
          {
               Emp emp = mdb.Emps.Find( id );
               if ( emp == null )
               {
                    return NotFound( );
               }
               return Ok( emp );
          }
          public IHttpActionResult Get(string name)
          {
               List<Emp> emp = mdb.Emps.Where( p=> p.Name == name ).ToList();
               if (emp == null)
               {
                    return NotFound();
               }
               return Ok(emp);
          }

          public IHttpActionResult Get()
          {
               List<Emp> emp = mdb.Emps.ToList();
               if ( emp == null )
               {
                    return NotFound( );
               }
               return Ok( emp );
          }

          //Post
          public IHttpActionResult Post(Emp emp)
          {
               mdb.Emps.Add(emp);
               mdb.SaveChanges();
               return Ok();
          }


          //update
          public IHttpActionResult Put(Emp emp)
		{
               Emp oldEmp = mdb.Emps.Find(emp.ID);

               if (oldEmp == null)
                    return NotFound();

               oldEmp.LoginID = emp.LoginID;
               oldEmp.LoginPW = emp.LoginPW;
               oldEmp.Name = emp.Name;
               oldEmp.Phone = emp.Phone;
               oldEmp.UserLevel = emp.UserLevel;

               mdb.SaveChanges();

               return Ok();
		}


     }
}