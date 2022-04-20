package com.example.SeedStarter.entity;

import lombok.Getter;
import lombok.Setter;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

@Getter
@Setter
public class SeedStarterAddForm {

    private String datePlanted;
    private boolean covered;
    private String type;

    private String substrate;
    private String fertilizer;
    private String phCorrector;

    public SeedStarter toSeedStarter()
    {
        SeedStarter ss = new SeedStarter();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy/MM/dd");
        ss.setDatePlanted(LocalDateTime.of( LocalDate.parse(datePlanted, formatter), LocalTime.of(0,0)));
        ss.setCovered(covered);

        if( type.compareTo("PLASTIC") == 0 )
        {
            ss.setType(Type.PLASTIC);
        }
        else
        {
            ss.setType(Type.WOOD);
        }

        if(substrate != null)
        {
            Feature fs = new Feature();
            fs.setName(FeatureType.SUBSTRATE);
            ss.setFeature(fs);
        }
        if(fertilizer != null)
        {
            Feature ff = new Feature();
            ff.setName(FeatureType.FERTILIZER);
            ss.setFeature(ff);
        }
        if(phCorrector != null)
        {
            Feature fp = new Feature();
            fp.setName(FeatureType.PH_CORRECTOR);
            ss.setFeature(fp);
        }


        return ss;
    }


}
