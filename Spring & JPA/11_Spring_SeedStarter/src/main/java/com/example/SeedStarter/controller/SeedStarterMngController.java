package com.example.SeedStarter.controller;

import com.example.SeedStarter.entity.SeedStarter;
import com.example.SeedStarter.entity.SeedStarterAddForm;
import com.example.SeedStarter.service.SeedStarterService;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.List;


@Controller
@RequiredArgsConstructor
public class SeedStarterMngController {

    private final SeedStarterService SeedStarterService;
/*
    @Autowired
    public SeedStarterMngController(SeedStarterService seedStarterService) {
        SeedStarterService = seedStarterService;
    }
*/
    private final ObjectMapper mapper;

    @ModelAttribute
    public void addAddtribute(Model model)
    {

        model.addAttribute("seedStarterAddForm", new SeedStarterAddForm() );

    }

    @RequestMapping({"/","/seedstartermng"})
    public String showSeedStarters(final SeedStarter seedStarter , Model model) throws JsonProcessingException
    {
       //return "<html><h1>hello seed starter</h1></html>";
        List<SeedStarter> seedStarterWithFeature = SeedStarterService.findWithFeature();
        List<SeedStarter> seedStarterWithDetail = SeedStarterService.findWithDetail();
        //seedStarterWithFeature.stream().forEach(v-> System.out.println("v.getId() = " + v.getId() ));
        //return "hello";
        //return mapper.writeValueAsString(seedStarterWithFeature);
        //에러발생 (양방향) @JsonManagedReference / @JsonBackReference 로 해결

        model.addAttribute("seedStarterWithFeature",seedStarterWithFeature );
        model.addAttribute("seedStarterWithDetail",seedStarterWithDetail );

        return "seedstartermng";
    }

    @PostMapping("/seedstartermng")
    public String addSeedStarter(@ModelAttribute SeedStarterAddForm seedStarterAddForm, Model model)
    {
        System.out.println("seedStarterAddForm.getDatePlanted() = " + seedStarterAddForm.getDatePlanted());
        System.out.println("seedStarterAddForm.isCovered() = " + seedStarterAddForm.isCovered());
        System.out.println("seedStarterAddForm.getType() = " + seedStarterAddForm.getType());
        System.out.println("seedStarterAddForm.getFertilizer() = " + seedStarterAddForm.getFertilizer());
        System.out.println("seedStarterAddForm.getSubstrate() = " + seedStarterAddForm.getSubstrate());
        SeedStarterService.saveSeedStarter( seedStarterAddForm.toSeedStarter() );
        return "redirect:/";
    }
}
