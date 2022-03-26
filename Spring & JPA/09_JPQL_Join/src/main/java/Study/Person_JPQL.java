package Study;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
public class Person_JPQL {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    private String name;

    private int age;

    @OneToMany(mappedBy = "person", cascade = CascadeType.REMOVE)
    private List<Address_JPQL> addresses = new ArrayList<Address_JPQL>();

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

    public List<Address_JPQL> getAddresses() {
        return addresses;
    }

    public void setAddresses(List<Address_JPQL> addresses) {
        this.addresses = addresses;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person_JPQL{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", age=" + age +
                ", addresses=" + addresses +
                '}';
    }
}
