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

            /*
            Movie movie = new Movie();


            movie.setMovieid(1L);
            movie.setMoviename("타이타닉");
            
            em.persist(movie);
            
            */

            /*
             * 
            movie.setMovieid(2L);
            movie.setMoviename("오징어게임");
            
            em.persist(movie);
            
            */
            
            /*
           Movie findMovie = em.find(Movie.class, 1L);
           System.out.println("findMovie = " +findMovie);
           
//           findMovie.setMoviename("로미오와줄리엣");
           	
           //em.update() 와 같은 것은 필요없음 자동으로 업데이트
           
           em.remove(findMovie);
*/
            Movie movie1= new Movie();
            movie1.setMoviename("타이타닉");
            em.persist(movie1);

            Movie movie2= new Movie();
            movie2.setMoviename("오징어게임");
            em.persist(movie2);

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
