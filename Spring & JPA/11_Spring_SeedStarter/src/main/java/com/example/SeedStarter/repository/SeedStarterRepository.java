package com.example.SeedStarter.repository;

import com.example.SeedStarter.entity.SeedStarter;
import org.springframework.data.jpa.repository.EntityGraph;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface SeedStarterRepository extends JpaRepository<SeedStarter, Long> {
    @EntityGraph(value = "SeedStarter.all", type= EntityGraph.EntityGraphType.LOAD)
    @Query("SELECT DISTINCT s FROM SeedStarter s")
    List<SeedStarter> findWithFeatureAndDetail();
}
