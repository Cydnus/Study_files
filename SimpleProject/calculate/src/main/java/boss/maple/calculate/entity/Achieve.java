package boss.maple.calculate.entity;

import com.fasterxml.jackson.annotation.JsonManagedReference;
import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.time.LocalDateTime;

@Getter
@Setter
@Entity
public class Achieve {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "ACHIEVE_ID")
    private Long id;

    private LocalDateTime dateTime;
    private Long price;
    private int itemCount;

    private Long partyInfo;

    private boolean calEnd;

    private boolean visibleOnTable;

    @OneToOne
    @JoinColumn(name="BOSS_INFO_ID")
    @JsonManagedReference
    private BossInfo boss;

    @OneToOne
    @JoinColumn(name="ITEM_INFO_ID")
    @JsonManagedReference
    private ItemInfo item;

}
