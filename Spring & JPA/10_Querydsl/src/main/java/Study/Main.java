package Study;

import com.querydsl.core.QueryResults;
import com.querydsl.jpa.impl.JPAQueryFactory;

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


            Address_Querydsl address1 = new Address_Querydsl("street1","city1","zipcode1");
            Address_Querydsl address2 = new Address_Querydsl("street2","city2","zipcode2");
            Address_Querydsl address3 = new Address_Querydsl("street3","city3","zipcode3");

            Person_Querydsl kim = new Person_Querydsl("kim", 20);
            Person_Querydsl lee = new Person_Querydsl("lee", 30);
            Person_Querydsl park = new Person_Querydsl("park", 25);
            Person_Querydsl hong = new Person_Querydsl("hong", 15);

            kim.addAddress(address1);
            kim.addAddress(address2);
            lee.addAddress(address3);

            em.persist(kim);
            em.persist(lee);
            em.persist(park);
            em.persist(hong);

            em.flush();
            em.clear();



            JPAQueryFactory query = new JPAQueryFactory(em);
            QPerson_Querydsl person = new QPerson_Querydsl("p");
            QAddress_Querydsl address = new QAddress_Querydsl("a");


  /*
            List<Person_Querydsl> persons= query.select(person)
                                            .from(person)
                                            .fetch();
            persons.stream().forEach(v -> System.out.println("v.getName() = " + v.getName()));
*/

/*          실행결과
            v.getName() = kim
            v.getName() = lee
            v.getName() = park
            v.getName() = hong
*/
/*

            List<Person_Querydsl> persons= query.selectFrom(person)
                    .where(person.name.eq("kim"))
                    .fetch();
            persons.stream().forEach(v -> System.out.println("v.getName() = " + v.getName()));
*/
/*          실행결과
            v.getName() = kim
*/


/*
            List<Person_Querydsl> persons= query.selectFrom(person)
                    .where(person.name.contains("k"))
                    .fetch();
            persons.stream().forEach(v -> System.out.println("v.getName() = " + v.getName()));
*/

/*          실행결과
            v.getName() = kim
            v.getName() = park
*/


/*
            List<Person_Querydsl> persons= query.selectFrom(person)
                    .where(person.name.contains("k"), person.age.gt(22))
                    .fetch();
            persons.stream().forEach(v -> System.out.println("v.getName() = " + v.getName()));
*/

/*          실행결과
            v.getName() = park
*/

/*
            List<Person_Querydsl> persons= query.selectFrom(person)
                    .where(person.name.contains("k").or(person.age.gt(22)))
                    .fetch();
            persons.stream().forEach(v -> System.out.println("v.getName() = " + v.getName()));
*/

/*          실행결과
            v.getName() = kim
            v.getName() = lee
            v.getName() = park
*/


/*
           List<Person_Querydsl> persons= query.selectFrom(person)
                        .innerJoin(person.addresses, address)
                        .fetch();
            System.out.println("persons.get(0).getAddresses().get(0).getCity() = "
                    + persons.get(0).getAddresses().get(0).getCity());
*/

/*          실행결과
            persons.get(0).getAddresses().get(0).getCity() = city1
*/

/*
            List<Person_Querydsl> persons= query.selectFrom(person)
                    .innerJoin(person.addresses, address).fetchJoin()
                    .fetch();
            System.out.println("persons.get(0).getAddresses().get(0).getCity() = "
                    + persons.get(0).getAddresses().get(0).getCity());
*/

/*          실행결과
            persons.get(0).getAddresses().get(0).getCity() = city1
*/

/*
            List<Person_Querydsl> persons = query.selectFrom(person)
                                            .orderBy(person.age.asc())
                                            .offset(0).limit(2)
                                            .fetch();
            persons.stream().forEach(v-> System.out.println("v.getName() = " + v.getName()));
*/

/*          실행결과
            v.getName() = hong
            v.getName() = kim
*/

            QueryResults<Person_Querydsl> result = query.selectFrom(person)
                    .orderBy(person.age.asc())
                    .offset(0).limit(2)
                    .fetchResults();

            long count = result.getTotal();
            List<Person_Querydsl> fetchResult = result.getResults();
            System.out.println("count = " + count);
            fetchResult.stream().forEach(v->System.out.println("v.getName() = " + v.getName()));


/*          실행결과
            count = 4
            v.getName() = hong
            v.getName() = kim
*/

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
