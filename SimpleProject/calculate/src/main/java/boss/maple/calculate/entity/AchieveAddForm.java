package boss.maple.calculate.entity;

import lombok.Getter;
import lombok.Setter;

import java.time.LocalDateTime;

@Getter
@Setter
public class AchieveAddForm {

    private String bosslevel;
    private String bossname;
    private String itemname;
    private Integer count;
    private Long price;
    private Long partyInfo;

    @Override
    public String toString() {
        return "AchieveAddForm{" +
                "bosslevel='" + bosslevel + '\'' +
                ", bossname='" + bossname + '\'' +
                ", itemname='" + itemname + '\'' +
                ", count='" + count + '\'' +
                ", price='" + price + '\'' +
                ", partyInfo='" + partyInfo + '\'' +
                '}';
    }
}
