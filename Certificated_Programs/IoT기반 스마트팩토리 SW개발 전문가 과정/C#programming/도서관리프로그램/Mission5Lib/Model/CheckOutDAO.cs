using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mission5Lib.Model
{
    public class CheckOutDAO : IDAO<CheckOut>
    {
        private static CheckOutDAO checkOutDAO;
        private CheckOutDAO() { }

        public static CheckOutDAO GetInstance()
        {
            if (checkOutDAO == null)
                checkOutDAO = new CheckOutDAO();

            return checkOutDAO;
        }

        public DAOResult Add(CheckOut entity)
        {
            try
            {
                using (var db = new DataContext())
                {
                    db.CheckOuts.Add(entity);
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
            throw new NotImplementedException();
        }

        public CheckOut Get(int id)
        {
            try
            {
                using (var db = new DataContext())
                {
                    return db.CheckOuts.FirstOrDefault(p => p.Id == id);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.StackTrace}");
                return null;
            }
        }

        public List<CheckOut> GetAll()
        {
            throw new NotImplementedException();
        }

        public DAOResult Update(CheckOut entity)
        {
            try
            {
                using (var db = new DataContext())
                {
                    var old = db.CheckOuts.FirstOrDefault(p => p.Id == entity.Id);

                    if (old == null)
                        return DAOResult.NotFound;

                    old.DueDate = entity.DueDate;
                    old.ReturnDate = entity.ReturnDate;
                    old.OverdueDays = entity.OverdueDays;
                    old.OverdueCharge = entity.OverdueCharge;
                    old.LibrarianId = entity.LibrarianId;
                    old.BookCopyId = entity.BookCopyId;
                    old.CheckOutDate = entity.CheckOutDate;

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
