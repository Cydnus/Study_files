using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mission5Lib.Model
{
    public class MemberDAO : IDAO<Member>
    {
        private static MemberDAO memberDAO;
        private MemberDAO() { }

        public static MemberDAO GetInstance()
        {
            if (memberDAO == null)
                memberDAO = new MemberDAO();

            return memberDAO;
        }

        public DAOResult Add(Member item)
        {
            try
            {
                using (var db = new DataContext())
                {
                    var old = db.Members.FirstOrDefault(p => p.LoginId == item.LoginId);

                    if (old != null)
                        return DAOResult.AlreadyExist;

                    db.Members.Add(item);
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
                    var old = db.Librarians.FirstOrDefault(p => p.Id == id);

                    if (old == null)
                        return DAOResult.NotFound;

                    db.Librarians.Remove(old);
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

        public Member Get(int id)
        {
            Member entity = null;

            try
            {
                using (var db = new DataContext())
                {
                    return db.Members.FirstOrDefault(p => p.Id == id);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.Message}");
            }

            return entity;
        }

        public Member Get(string loginId)
        {
            Member entity = null;

            try
            {
                using (var db = new DataContext())
                {
                    return db.Members.FirstOrDefault(p => p.LoginId == loginId);
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.Message}");
            }

            return entity;
        }

        public List<Member> GetAll()
        {
            List<Member> list = null;

            try
            {
                using (var db = new DataContext())
                {
                    list = db.Members.ToList();
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine($"[Error] {ex.Message}");
            }

            return list;
        }

        public DAOResult Update(Member entity)
        {
            try
            {
                using (var db = new DataContext())
                {
                    var old = db.Members.FirstOrDefault(p => p.Id == entity.Id);

                    if (old == null)
                        return DAOResult.NotFound;

                    old.LoginId = entity.LoginId;
                    old.Name = entity.Name;
                    old.Password = entity.Password;
                    old.PhoneNo = entity.PhoneNo;
                    old.Address = entity.Address;
                    old.MemberLevel = entity.MemberLevel;

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
