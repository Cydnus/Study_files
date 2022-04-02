package boss.maple.calculate.controller;

import boss.maple.calculate.entity.*;
import boss.maple.calculate.service.MapleBossAchieveService;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.ModelAndView;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

@RequiredArgsConstructor
@Controller
//@RestController
public class MapleBossAchieveController {

    private final MapleBossAchieveService mbas;
    private final ObjectMapper mapper;


    @ModelAttribute
    public void addAddtribute(Model model)
    {

        model.addAttribute("achieveAddForm", new AchieveAddForm() );

    }

    @RequestMapping({"/api/", "/api/achieve"})
    public String showAchieve(final Achieve achieve, Model model) throws JsonProcessingException
    {
        List<Achieve> all = mbas.findAllByVisibleOnTable();
        List<String> itemNames = mbas.findAllItemInfoName();
        List<String> bossNames = mbas.findAllBossInfoName();


        List<LevelType> bossLevel = new ArrayList<>();
        bossLevel.add(LevelType.이지);
        bossLevel.add(LevelType.노말);
        bossLevel.add(LevelType.하드);
        bossLevel.add(LevelType.카오스);

        model.addAttribute("achieveWithBossAndItem", all);
        model.addAttribute("itemNames", itemNames);
        model.addAttribute("bossNames", bossNames);
        model.addAttribute("bossTypes", bossLevel);
        //shows.stream().forEach(v-> System.out.println("v.isCalEnd() = " + v.isCalEnd()));
        //return mapper.writeValueAsString(shows);
        return "Achieve";
    }

    @PostMapping("/api/achieve")
    public String achieveAdd(@ModelAttribute AchieveAddForm achieveAddForm, Model model )
    {
        System.out.println(achieveAddForm);



        Achieve achieve = new Achieve();

        achieve.setDateTime(LocalDateTime.now());
        BossInfo bossInfo;
        switch ( achieveAddForm.getBosslevel())
        {
            case "노말":
                bossInfo = mbas.findBossInfoByNameAndLevel(achieveAddForm.getBossname(), LevelType.노말 );
                break;
            case "하드":
                bossInfo = mbas.findBossInfoByNameAndLevel(achieveAddForm.getBossname(), LevelType.하드 );
                break;
            case "카오스":
                bossInfo = mbas.findBossInfoByNameAndLevel(achieveAddForm.getBossname(), LevelType.카오스 );
                break;
            case "이지":
            default:
                bossInfo = mbas.findBossInfoByNameAndLevel(achieveAddForm.getBossname(), LevelType.이지 );
                break;
        }


        if(bossInfo == null)
        {
            return "redirect:/api/";
        }

        achieve.setBoss(bossInfo);
        ItemInfo itemInfo = mbas.findItemInfoByName(achieveAddForm.getItemname());

        if(itemInfo == null )
        {
            return "redirect:/api/";
        }

        achieve.setItem(itemInfo);

        if(achieveAddForm.getPartyInfo() == null)
        {
            return "redirect:/api/";
        }
        try
        {
            achieve.setPartyInfo(achieveAddForm.getPartyInfo());

        }
        catch (Exception ex)
        {
            achieve.setPartyInfo(1L);
        }

        if(achieveAddForm.getPrice() == null)
        {
            achieveAddForm.setPrice(0L);
        }

        try {
            achieve.setPrice(achieveAddForm.getPrice());
        }
        catch(Exception ex)
        {
            achieve.setPrice(0L);
        }


        if(achieveAddForm.getCount() == null)
        {
            return "redirect:/api/";
        }

        try
        {
            achieve.setItemCount(achieveAddForm.getCount());
        }
        catch (Exception ex)
        {
            achieve.setItemCount(1);
        }

        achieve.setCalEnd(false);
        achieve.setVisibleOnTable(false);




        mbas.saveAchieve(achieve);

        return "redirect:/api/";
    }


}
