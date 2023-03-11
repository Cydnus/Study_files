using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mission5Lib.Model
{
    public class BookCopyDAO : IDAO<BookCopy>
    {
        private static BookCopyDAO bookCopyDAO;
        private BookCopyDAO() { }

        public static BookCopyDAO GetInstance()
        {
            if (bookCopyDAO == null)
                bookCopyDAO = new BookCopyDAO();

            return bookCopyDAO;
        }

        public DAOResult Add(BookCopy entity)
        {
            try
            {
                using (var db = new DataContext())
                {
                    var old = db.BookCopies.FirstOrDefault(p => p.Id == entity.Id);

                    if (old != null)
                        return DAOResult.AlreadyExist;

                    db.BookCopies.Add(entity);
                    db.SaveChanges();

                    return DAOResult.Success;
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.StackTrace}");
                return DAOResult.SqlError;
            }
        }

        public DAOResult Delete(int id)
        {
            try
            {
                using (var db = new DataContext())
                {
                    var old = db.BookCopies.FirstOrDefault(p => p.Id == id);

                    if (old == null)
                        return DAOResult.NotFound;

                    db.BookCopies.Remove(old);
                    db.SaveChanges();

                    return DAOResult.Success;
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.StackTrace}");
                return DAOResult.SqlError;
            }
        }

        public BookCopy Get(int id)
        {
            BookCopy entity = null;

            try
            {
                using (var db = new DataContext())
                {
                    return db.BookCopies.FirstOrDefault(p => p.Id == id);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.StackTrace}");
            }

            return entity;
        }

        public BookCopy Get(string bookCopyCode)
        {
            BookCopy entity = null;

            try
            {
                using (var db = new DataContext())
                {
                    entity = db.BookCopies.FirstOrDefault(p => p.BookCopyCode == bookCopyCode);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.StackTrace}");
            }

            return entity;
        }

        public List<BookCopy> GetAll()
        {
            List<BookCopy> list = null;

            try
            {
                using (var db = new DataContext())
                {
                    list = db.BookCopies.ToList();
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.StackTrace}");
            }

            return list;
        }

        public DAOResult Update(BookCopy entity)
        {
            try
            {
                using (var db = new DataContext())
                {
                    var old = db.BookCopies.FirstOrDefault(p => p.Id == entity.Id);

                    if (old == null)
                        return DAOResult.NotFound;

                    old.BookId = entity.BookId;
                    old.BookStatus = entity.BookStatus;
                    old.ArrivalDate = entity.ArrivalDate;
                    old.BookCopyCode = entity.BookCopyCode;

                    db.SaveChanges();

                    return DAOResult.Success;
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.StackTrace}");
                return DAOResult.SqlError;
            }
        }
    }
}
