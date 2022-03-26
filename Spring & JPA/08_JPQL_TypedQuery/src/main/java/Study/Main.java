package Study;

import javax.persistence.*;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("playground");
        EntityManager em = emf.createEntityManager();
        EntityTransaction tx = em.getTransaction();

        try
        {
            tx.begin();

            Address_JPQL address1 = new Address_JPQL();
            address1.setCity("city1");
            address1.setStreet("street1");
            address1.setZipCode("zipCode1");

            Address_JPQL address2 = new Address_JPQL();
            address2.setCity("city1");
            address2.setStreet("street1");
            address2.setZipCode("zipCode1");

            Person_JPQL person = new Person_JPQL();
            person.setName("sangho");
            person.setAge(20);

            person.getAddresses().add(address1);
            person.getAddresses().add(address2);

            address1.setPerson(person);
            address2.setPerson(person);

            //casecadetype persist
            em.persist(person);
            em.persist(address1);
            em.persist(address2);

            em.flush();
            em.clear();

            /*

            TypedQuery<Person_JPQL> query =
                    em.createQuery(
                            "SELECT p FROM Person_JPQL AS p",
                            Person_JPQL.class);

            List<Person_JPQL> resultList= query.getResultList();

            resultList.stream().forEach(v -> System.out.println("v = " + v));

            */

            /*

            TypedQuery<String> query =
                    em.createQuery(
                            "SELECT p.name FROM Person_JPQL AS p",
                            String.class);

            List<String> resultList= query.getResultList();

            resultList.stream().forEach(v -> System.out.println("v = " + v));


            */

            Query query = em.createQuery("SELECT p.name, p.age FROM Person_JPQL AS p");

            List resultList = query.getResultList();

            for(Object o : resultList)
            {
                Object[] result = (Object[]) o;
                System.out.println("result[0] = " + result[0]);
                System.out.println("result[1] = " + result[1]);
            }

            System.out.println("===================\tBefore\t===================");

            tx.commit();

            System.out.println("===================\tAfter\t===================");
        }
        catch(Exception e)
        {
            tx.rollback();
        }
        finally {
            em.close();
        }
    }
}
