package com.example.SeedStarter.entity;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Getter
@Setter
@Entity
public class Feature {

    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name ="FEATURE_ID")
    private Long id;

    @Enumerated(EnumType.STRING)
    private FeatureType name;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name="SEED_STARTER_ID")
    private SeedStarter seedStarter;

    public void setSeedStarter(SeedStarter seedStarter)
    {
        this.seedStarter = seedStarter;
        seedStarter.getFeatures().add(this);
    }
}
