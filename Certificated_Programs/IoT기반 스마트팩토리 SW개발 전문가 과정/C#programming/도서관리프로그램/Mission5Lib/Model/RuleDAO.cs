using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mission5Lib.Model
{
    public class RuleDAO
    {
        private static RuleDAO ruleDAO;
        private RuleDAO() { }

        public static RuleDAO GetInstance()
        {
            if (ruleDAO == null)
                ruleDAO = new RuleDAO();

            return ruleDAO;
        }

        public Rule Get()
        {
            try
            {
                using (var db = new DataContext())
                {
                    return db.Rules.FirstOrDefault();
                }
            }
            catch
            {
                return null;
            }
        }
    }
}
