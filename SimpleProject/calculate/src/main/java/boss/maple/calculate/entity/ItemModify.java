package boss.maple.calculate.entity;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

@Getter
@Setter
@ToString
public class ItemModify {
    String id;
    String date;
    String blevel;
    String bname;
    String iname;
    String itemCount;
    String price;
    String partyInfo;
    boolean calEnd;
}
