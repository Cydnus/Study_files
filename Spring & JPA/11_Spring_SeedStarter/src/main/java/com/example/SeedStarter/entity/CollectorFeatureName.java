package com.example.SeedStarter.entity;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class CollectorFeatureName {
    public static final List<FeatureType> name(Stream<Feature> stream)
    {
        return stream.map(v->v.getName()).collect(Collectors.toList());
    }
}
