using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mission5Lib.Model
{
    public class BookDAO : IDAO<Book>
    {
        private static BookDAO bookDAO;
        private BookDAO() { }

        public static BookDAO GetInstance()
        {
            if (bookDAO == null)
                bookDAO = new BookDAO();

            return bookDAO;
        }

        public DAOResult Add(Book item)
        {
            try
            {
                using (var db = new DataContext())
                {
                    var old = db.Books.FirstOrDefault(p => p.Id == item.Id);

                    if (old != null)
                        return DAOResult.AlreadyExist;

                    db.Books.Add(item);
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
                    var old = db.Books.FirstOrDefault(p => p.Id == id);

                    if (old == null)
                        return DAOResult.NotFound;

                    db.Books.Remove(old);
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

        public Book Get(int id)
        {
            Book entity = null;

            try
            {
                using (var db = new DataContext())
                {
                    return db.Books.FirstOrDefault(p => p.Id == id);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.Message}");
            }

            return entity;
        }

        public Book Get(string bookCode)
        {
            Book entity = null;

            try
            {
                using (var db = new DataContext())
                {
                    return db.Books.FirstOrDefault(p => p.BookCode == bookCode);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.StackTrace}");
            }

            return entity;
        }

        public List<Book> GetAll()
        {
            List<Book> list = null;

            try
            {
                using (var db = new DataContext())
                {
                    list = db.Books.ToList();
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.StackTrace}");
            }

            return list;
        }

        public List<Book> GetAllByKeyword(string title = "", string author = "")
        {
            List<Book> list = null;

            try
            {
                using (var db = new DataContext())
                {
                    list = db.Books.Where(p=>p.Title.IndexOf(title) >= 0 && p.Author.IndexOf(author) >= 0).ToList();
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.StackTrace}");
            }

            return list;
        }

        public DAOResult Update(Book entity)
        {
            try
            {
                using (var db = new DataContext())
                {
                    var old = db.Books.FirstOrDefault(p => p.Id == entity.Id);

                    if (old == null)
                        return DAOResult.NotFound;

                    old.BookCode = entity.BookCode;
                    old.Author = entity.Author;
                    old.PublishDate = entity.PublishDate;
                    old.Publisher = entity.Publisher;
                    old.Title = entity.Title;

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
