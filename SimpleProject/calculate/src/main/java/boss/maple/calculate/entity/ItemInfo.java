package boss.maple.calculate.entity;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Getter
@Setter
@Entity
public class ItemInfo {
    // Enum으로도 가능하지만 후에 아이템이 추가될 상황을 대비해서 테이블로 생성
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name="Item_INFO_Id")
    private Long id;

    private String name;

    @Enumerated(EnumType.STRING)
    private ItemType type;

}
