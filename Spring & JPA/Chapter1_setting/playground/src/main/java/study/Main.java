package study;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Persistence;

public class Main {

    public static void main(String[] args)
    {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("playground");
        EntityManager em = emf.createEntityManager();

        EntityTransaction tx =  em.getTransaction();

        try
        {
            tx.begin();

            Movie movie = new Movie();
            
            /*
             * 
            movie.setMovieid(1L);
            movie.setMoviename("Ÿ��Ÿ��");
            
            em.persist(movie);
            
            */

            /*
             * 
            movie.setMovieid(2L);
            movie.setMoviename("��¡�����");
            
            em.persist(movie);
            
            */
            
            
           Movie findMovie = em.find(Movie.class, 1L);
           System.out.println("findMovie = " +findMovie);
           
//           findMovie.setMoviename("�ι̿����ٸ���");
           	
           //em.update() �� ���� ���� �ʿ���� �ڵ����� ������Ʈ
           
           em.remove(findMovie);

            tx.commit();
        }
        catch(Exception e)
        {
            tx.rollback();
        }
        finally
        {
            em.close();
        }
    }
}
