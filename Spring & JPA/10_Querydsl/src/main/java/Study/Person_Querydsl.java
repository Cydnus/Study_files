package Study;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
public class Person_Querydsl {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    private String name;

    private int age;

    @OneToMany(mappedBy = "person", cascade = CascadeType.ALL)
    private List<Address_Querydsl> addresses = new ArrayList<Address_Querydsl>();

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<Address_Querydsl> getAddresses() {
        return addresses;
    }

    public void setAddresses(List<Address_Querydsl> addresses) {
        this.addresses = addresses;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
    public Person_Querydsl(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public void addAddress(Address_Querydsl address)
    {
        this.addresses.add(address);
        address.setPerson(this);
    }

    public Person_Querydsl() {
    }
}
