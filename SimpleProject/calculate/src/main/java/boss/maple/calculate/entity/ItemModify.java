package boss.maple.calculate.entity;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

@Getter
@Setter
@ToString
public class ItemModify {
    Long id;
    String blevel;
    String bname;
    String iname;
    int itemCount;
    Long price;
    Long partyInfo;
    boolean calEnd;
}
