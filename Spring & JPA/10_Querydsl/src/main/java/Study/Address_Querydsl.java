package Study;

import javax.persistence.*;

@Entity
public class Address_Querydsl {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    private String street;
    private String city;
    private String zipCode;

    @ManyToOne(fetch = FetchType.LAZY)
    private Person_Querydsl person;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getZipCode() {
        return zipCode;
    }

    public void setZipCode(String zipCode) {
        this.zipCode = zipCode;
    }

    public Person_Querydsl getPerson() {
        return person;
    }

    public void setPerson(Person_Querydsl person) {
        this.person = person;
    }

    public Address_Querydsl(String street, String city, String zipCode) {
        this.street = street;
        this.city = city;
        this.zipCode = zipCode;
    }

    public void addPerson(Person_Querydsl person)
    {
        this.person = person;
        person.getAddresses().add(this);
    }

    public Address_Querydsl() {
    }
}
