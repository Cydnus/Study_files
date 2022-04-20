package boss.maple.calculate.entity;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Getter
@Setter
@Entity
public class BossInfo {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name= "BOSS_INFO_ID")
    private Long id;

    private String name;

    @Enumerated(EnumType.STRING)
    private LevelType level;

}
