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

            Book2 book2 = new Book2();
            book2.setTitle("어린왕자");
            book2.setVersion(1);
            book2.setPages(200);

            BlogPost blogPost = new BlogPost();
            blogPost.setTitle("어린왕자 리뷰");
            blogPost.setVersion(1);
            blogPost.setUrl("http:abc.xyz/review/littlePrince");

            em.persist(book2);
            em.persist(blogPost);

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
