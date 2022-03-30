package com.example.SeedStarter.repository;

import com.example.SeedStarter.entity.SeedStarter;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface SeedStarterRepository extends JpaRepository<SeedStarter, Long> {
}
