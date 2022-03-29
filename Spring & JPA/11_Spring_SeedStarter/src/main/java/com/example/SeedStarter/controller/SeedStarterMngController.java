package com.example.SeedStarter.controller;

import com.example.SeedStarter.entity.SeedStarter;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

//@Controller
@RestController
public class SeedStarterMngController {
    @RequestMapping({"/","/seedstartermng"})
    public String showSeedStarters(final SeedStarter seedStarter , Model model)
    {
        return "<html><h1>hello seed starter</h1></html>";
    }
}
