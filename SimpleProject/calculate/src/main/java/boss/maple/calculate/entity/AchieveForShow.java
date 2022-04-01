package boss.maple.calculate.entity;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class AchieveForShow extends Achieve {

    private Long priceExcludeCommission;
    private Long pricePerOne;
    private String boss_level;
    private String boss_name;
    private String item_type;
    private String item_name;


    public AchieveForShow(Achieve a)
    {
        this.setId(a.getId());
        this.setDateTime(a.getDateTime());
        this.setPrice(a.getPrice());
        this.setItemCount(a.getItemCount());
        this.setPartyInfo(a.getPartyInfo());
        this.setCalEnd(a.isCalEnd());
        this.setVisibleOnTable(a.isVisibleOnTable());

        this.item_name = a.getItem().getName();
        this.boss_name = a.getBoss().getName();

        this.item_type = a.getItem().getType().toString();
        this.boss_level = a.getBoss().getLevel().toString();

        priceExcludeCommission = (new Double(this.getPrice() * 0.95)).longValue();
        pricePerOne = priceExcludeCommission / this.getPartyInfo();

    }
}
