package Study;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Persistence;

public class Main {
    public static void main(String[] args) {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("playground");
        EntityManager em = emf.createEntityManager();
        EntityTransaction tx = em.getTransaction();

        try
        {
            tx.begin();

            Address address1 = new Address();
            address1.setCity("city1");
            address1.setStreet("street1");
            address1.setZipCode("zipCode1");

            Address address2 = new Address();
            address2.setCity("city1");
            address2.setStreet("street1");
            address2.setZipCode("zipCode1");

            Person person = new Person();
            person.setName("sangho");

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

            Person findPerson = em.find(Person.class, 1);
            em.remove(findPerson);



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
