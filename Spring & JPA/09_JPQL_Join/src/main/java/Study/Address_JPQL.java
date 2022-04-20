package Study;

import javax.persistence.*;

@Entity
public class Address_JPQL {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    private String street;
    private String city;
    private String zipCode;

    @ManyToOne(fetch = FetchType.LAZY)
    private Person_JPQL person;

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

    public Person_JPQL getPerson() {
        return person;
    }

    public void setPerson(Person_JPQL person) {
        this.person = person;
    }
}
