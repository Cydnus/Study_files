package com.example.SeedStarter.controller;

import com.example.SeedStarter.entity.SeedStarter;
import com.example.SeedStarter.repository.SeedStarterRepository;
import com.example.SeedStarter.service.SeedStarterService;
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


    @RequestMapping({"/","/seedstartermng"})
    public String showSeedStarters(final SeedStarter seedStarter , Model model)
    {
       //return "<html><h1>hello seed starter</h1></html>";
        List<SeedStarter> all = SeedStarterService.findAll();
        all.stream().forEach(v-> System.out.println("v.getId() = " + v.getId() ));

        return "hello";
    }
}
