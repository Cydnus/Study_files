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


            TypedQuery<Person_JPQL> query =
                    em.createQuery(
                            "SELECT distinct p FROM Person_JPQL AS p join fetch p.addresses",
                            Person_JPQL.class);

            List<Person_JPQL> resultList= query.getResultList();

            //여기까지 Select문 하나
            //PersistentBag으로 Address를 불러옴.

           resultList.stream().forEach(v -> System.out.println("v = " + v));


            tx.commit();

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
