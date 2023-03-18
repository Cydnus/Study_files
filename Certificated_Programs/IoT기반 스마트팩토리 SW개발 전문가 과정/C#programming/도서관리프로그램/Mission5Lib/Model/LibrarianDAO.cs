using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mission5Lib.Model
{
    public class LibrarianDAO : IDAO<Librarian>
    {
        private static LibrarianDAO librarianDAO;
        private LibrarianDAO() { }

        public static LibrarianDAO GetInstance()
        {
            if (librarianDAO == null)
                librarianDAO = new LibrarianDAO();

            return librarianDAO;
        }

        public DAOResult Add(Librarian item)
        {
            try
            {
                using (var db = new DataContext())
                {
                    var old = db.Librarians.FirstOrDefault(p => p.LoginId == item.LoginId);

                    if (old != null)
                        return DAOResult.AlreadyExist;

                    db.Librarians.Add(item);
                    db.SaveChanges();

                    return DAOResult.Success;
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.Message}");
                return DAOResult.SqlError;
            }
        }

        public DAOResult Delete(int id)
        {
            try
            {
                using (var db = new DataContext())
                {
                    var old = db.Librarians.FirstOrDefault(p=>p.Id == id);

                    if (old == null)
                        return DAOResult.NotFound;

                    db.Librarians.Remove(old);
                    db.SaveChanges();

                    return DAOResult.Success;
                }
            }
            catch(Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.Message}");
                return DAOResult.SqlError;
            }
        }

        public Librarian Get(int id)
        {
            Librarian entity = null;

            try
            {
                using (var db = new DataContext())
                {
                    return db.Librarians.FirstOrDefault(p => p.Id == id);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.Message}");
            }

            return entity;
        }

        public Librarian Get(string loginId)
        {
            Librarian entity = null;

            try
            {
                using (var db = new DataContext())
                {
                    return db.Librarians.FirstOrDefault(p => p.LoginId == loginId);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.Message}");
            }

            return entity;
        }

        public List<Librarian> GetAll()
        {
            List<Librarian> list = null;

            try
            {
                using (var db = new DataContext())
                {
                    list = db.Librarians.ToList();
                }
            }
            catch(Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.Message}");
            }

            return list;
        }

        public DAOResult Update(Librarian entity)
        {
            try
            {
                using (var db = new DataContext())
                {
                    var old = db.Librarians.FirstOrDefault(p => p.Id == entity.Id);

                    if (old == null)
                        return DAOResult.NotFound;

                    old.LoginId = entity.LoginId;
                    old.Name = entity.Name;
                    old.Password = entity.Password;
                    old.PhoneNo = entity.PhoneNo;
                    old.Status = entity.Status;

                    db.SaveChanges();

                    return DAOResult.Success;
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.Message}");
                return DAOResult.SqlError;
            }
        }
    }
}
