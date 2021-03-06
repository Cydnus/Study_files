package com.example.SeedStarter.service;

import com.example.SeedStarter.entity.SeedStarter;
import com.example.SeedStarter.entity.SeedStarterAddForm;
import com.example.SeedStarter.repository.SeedStarterRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.util.List;

@Service
@RequiredArgsConstructor
public class SeedStarterService {

    private final SeedStarterRepository seedStarterRepository;


    public List<SeedStarter> findWithFeature()
    {
        return this.seedStarterRepository.findWithFeature();
    }

    public List<SeedStarter> findWithDetail()
    {
        return this.seedStarterRepository.findWithDetail();
    }

    public SeedStarter saveSeedStarter( SeedStarter seedStarter )
    {
        return this.seedStarterRepository.save(seedStarter);
    }

}
