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

        try {
            tx.begin();

            Manuscript manuscript = new Manuscript();
            Book book = new Book();

            book.setISBN("ABCDEFG12");
            book.setManuscript(manuscript);

            manuscript.setBook(book);

            em.persist(manuscript);
            em.persist(book);


            tx.commit();
        }
        catch (Exception e)
        {
            tx.rollback();
        }
        finally {
            em.close();
        }
    }

}
