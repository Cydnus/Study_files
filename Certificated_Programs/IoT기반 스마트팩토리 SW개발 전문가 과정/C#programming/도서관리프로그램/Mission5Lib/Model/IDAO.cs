using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mission5Lib.Model
{
    public interface IDAO<T>
    {
        T Get(int id);
        List<T> GetAll();
        DAOResult Add(T entity);
        DAOResult Update(T entity);
        DAOResult Delete(int id);
    }
}
