package boss.maple.calculate.entity;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Getter
@Setter
@Entity
public class Acheive {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "ACHEIVE_ID")
    private Long id;

    private Long Price;
    private int count;

    private Long PartyInfo;

    @OneToOne(fetch = FetchType.LAZY)
    @JoinColumn(name="BOSS_INFO_ID")
    private BossInfo boss;

    @OneToOne(fetch = FetchType.LAZY)
    @JoinColumn(name="Item_INFO_Id")
    private ItemInfo item;


}
