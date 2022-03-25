package Study;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
public class PurchaseOrder {
    @Id
    @GeneratedValue(strategy =  GenerationType.IDENTITY)
    @Column(name = "PURCHASE_ORDER_ID")
    private Long id;
    private String userName;

     //@OneToMany(mappedBy = "order")
     @OneToMany
     @JoinColumn(name = "PURCHASE_ORDER_ID")
     private List<Item> items = new ArrayList<Item>();

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public List<Item> getItems() {
        return items;
    }

    public void setItems(List<Item> items) {
        this.items = items;
    }
/*
    public void addItem(Item item)
    {
        this.items.add(item);
        item.setOrder(this);
    }*/
}
