package com.example.SeedStarter.controller;

import com.example.SeedStarter.entity.SeedStarter;
import com.example.SeedStarter.repository.SeedStarterRepository;
import com.example.SeedStarter.service.SeedStarterService;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

//@Controller
@RequiredArgsConstructor
@RestController
public class SeedStarterMngController {

    private final SeedStarterService SeedStarterService;

    private final ObjectMapper mapper;

    @RequestMapping({"/","/seedstartermng"})
    public String showSeedStarters(final SeedStarter seedStarter , Model model) throws JsonProcessingException
    {
       //return "<html><h1>hello seed starter</h1></html>";
        List<SeedStarter> seedStarterWithFeature = SeedStarterService.findWithFeature();
        List<SeedStarter> seedStarterWithDetail = SeedStarterService.findWithDetail();
        seedStarterWithFeature.stream().forEach(v-> System.out.println("v.getId() = " + v.getId() ));
        //return "hello";
        return mapper.writeValueAsString(seedStarterWithFeature);
        //에러발생 (양방향) @JsonManagedReference / @JsonBackReference 로 해결

    }
}
