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
/*
// 1
            Item item1 = new Item();
            item1. setName("치킨");

            Item item2 = new Item();
            item2. setName("치즈볼");

            PurchaseOrder order = new PurchaseOrder();
            order.setUserName("sangho");

            item1.setOrder(order);
            item2.setOrder(order);

           // order.getItems().add(item1);
           // order.getItems().add(item2);

            em.persist(order);
            em.persist(item1);
            em.persist(item2);


       //     em.persist(item1);
     //       em.persist(item2);
       //     em.persist(order);


            em.flush();
            em.clear();


            Item findItem = em.find(Item.class, 1L);

            System.out.println("findItem.getOrder().getUserName() = " + findItem.getOrder().getUserName());

//2

            Item item1 = new Item();
            item1. setName("치킨");

            Item item2 = new Item();
            item2. setName("치즈볼");

            PurchaseOrder order = new PurchaseOrder();
            order.setUserName("sangho");

            order.getItems().add(item1);
            order.getItems().add(item2);

            em.persist(order);
            em.persist(item1);
            em.persist(item2);

            em.flush();
            em.clear();


// 3



            Item item1 = new Item();
            item1. setName("치킨");

            Item item2 = new Item();
            item2. setName("치즈볼");

            PurchaseOrder order = new PurchaseOrder();
            order.setUserName("sangho");

            order.getItems().add(item1);
            order.getItems().add(item2);

            em.persist(item1);
            em.persist(item2);
            em.persist(order);

            em.flush();
            em.clear();

            PurchaseOrder findOrder = em.find(PurchaseOrder.class , 1L);
            findOrder.getItems().remove(0);

*/

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
