package boss.maple.calculate.controller;

import boss.maple.calculate.entity.*;
import boss.maple.calculate.service.MapleBossAchieveService;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.nio.charset.StandardCharsets;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Base64;
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
        model.addAttribute("itemModifyListForm", new ItemModifyListForm() );

    }

    @RequestMapping({"/api/", "/api/achieve","/api/achieve/"})
    public ModelAndView showAchieve(final Achieve achieve) throws JsonProcessingException
    {
        List<Achieve> all = mbas.findAllByVisibleOnTable();
        List<String> itemNames = mbas.findAllItemInfoName();
        List<String> bossNames = mbas.findAllBossInfoName();


        List<LevelType> bossLevel = new ArrayList<>();
        bossLevel.add(LevelType.이지);
        bossLevel.add(LevelType.노말);
        bossLevel.add(LevelType.하드);
        bossLevel.add(LevelType.카오스);

        ModelAndView modelAndView = new ModelAndView("Achieve");
        modelAndView.addObject("achieveWithBossAndItem", all);
        modelAndView.addObject("itemNames", itemNames);
        modelAndView.addObject("bossNames", bossNames);
        modelAndView.addObject("bossTypes", bossLevel);
        //shows.stream().forEach(v-> System.out.println("v.isCalEnd() = " + v.isCalEnd()));
        //return mapper.writeValueAsString(shows);
        return modelAndView;
    }

    @RequestMapping(value = {"/api/achieve/{bLevel}/{bName}/{partyCnt}", "/api/achieve/"}, method = RequestMethod.GET)
    public ModelAndView showAchieveWithInfos(final Achieve achieve,
                                             @PathVariable("bLevel") @RequestParam(value = "bLevel", required=false) String bLevel,
                                             @PathVariable("bName") @RequestParam(value ="bName", required=false) String bName,
                                             @PathVariable("partyCnt") @RequestParam(value ="partyCnt", required=false) String partyCnt ) throws JsonProcessingException
    {
        if(bLevel == null || bName== null || partyCnt == null )
            return showAchieve(achieve);

        List<Achieve> all = mbas.findAllByVisibleOnTable();
        List<String> itemNames = mbas.findAllItemInfoName();
        List<String> bossNames = mbas.findAllBossInfoName();

        List<LevelType> bossLevel = new ArrayList<>();
        bossLevel.add(LevelType.이지);
        bossLevel.add(LevelType.노말);
        bossLevel.add(LevelType.하드);
        bossLevel.add(LevelType.카오스);

        List<String> infos = new ArrayList<>();
        infos.add(bossLevel.get(Integer.parseInt(bLevel.toString())).toString());

        infos.add(partyCnt.toString());

        List<Integer> list = new ArrayList<Integer>();

        int size = bName.toString().length();
        for(int i = 0; i< size; i+=3)
        {
            list.add(Integer.parseInt(bName.toString().substring(i, i+3)) *(-1));
        }
        byte[] recover = new byte[list.size()];

        for(int i = 0 ; i< list.size(); i++)
        {
            recover[i] = Byte.parseByte(list.get(i).toString());
        }

        infos.add(new String(recover,StandardCharsets.UTF_8));

        infos.stream().forEach(v-> System.out.println("v = " + v));

        ModelAndView modelAndView = new ModelAndView("Achieve");
        modelAndView.addObject("achieveWithBossAndItem", all);
        modelAndView.addObject("itemNames", itemNames);
        modelAndView.addObject("bossNames", bossNames);
        modelAndView.addObject("bossTypes", bossLevel);
        modelAndView.addObject("infos",infos);
        //shows.stream().forEach(v-> System.out.println("v.isCalEnd() = " + v.isCalEnd()));
        //return mapper.writeValueAsString(shows);
        return modelAndView;
    }

    @RequestMapping({"/api/achieve/items_modify","/api/achieve/items_modify/"})
    public ModelAndView showAchieveItems(final Achieve achieve) throws JsonProcessingException
    {
        List<Achieve> all = mbas.findAllByVisibleOnTable();
        List<String> itemNames = mbas.findAllItemInfoName();
        List<String> bossNames = mbas.findAllBossInfoName();


        List<LevelType> bossLevel = new ArrayList<>();
        bossLevel.add(LevelType.이지);
        bossLevel.add(LevelType.노말);
        bossLevel.add(LevelType.하드);
        bossLevel.add(LevelType.카오스);

        ModelAndView modelAndView = new ModelAndView("achieve/items_modify");
        modelAndView.addObject("achieveWithBossAndItem", all);
        modelAndView.addObject("itemNames", itemNames);
        modelAndView.addObject("bossNames", bossNames);
        modelAndView.addObject("bossTypes", bossLevel);
        //shows.stream().forEach(v-> System.out.println("v.isCalEnd() = " + v.isCalEnd()));
        //return mapper.writeValueAsString(shows);
        return modelAndView;
    }

    @PostMapping({"/api/achieve/items_modify/","/api/achieve/items_modify/"})
    public ModelAndView updates(@ModelAttribute ItemModifyListForm itemModifyListForm)
    {
         System.out.println("modifies = " + itemModifyListForm);

        ModelAndView mav = new ModelAndView("/api/achieve/");
        return mav;
    }


    @PostMapping("/api/achieve")
    public ModelAndView achieveAdd(@ModelAttribute AchieveAddForm achieveAddForm)
    {
        Achieve achieve = new Achieve();
        String viewName= "redirect:/api/achieve/?";
        ModelAndView mav = new ModelAndView("redirect:/api/achieve");
        achieve.setDateTime(LocalDateTime.now());
        BossInfo bossInfo;
        switch ( achieveAddForm.getBosslevel())
        {
            case "노말":
                viewName += "bLevel=1&";
                bossInfo = mbas.findBossInfoByNameAndLevel(achieveAddForm.getBossname(), LevelType.노말 );
                break;
            case "하드":
                viewName += "bLevel=2&";
                bossInfo = mbas.findBossInfoByNameAndLevel(achieveAddForm.getBossname(), LevelType.하드 );
                break;
            case "카오스":
                viewName += "bLevel=3&";
                bossInfo = mbas.findBossInfoByNameAndLevel(achieveAddForm.getBossname(), LevelType.카오스 );
                break;
            case "이지":
            default:
                viewName += "bLevel=0&";
                bossInfo = mbas.findBossInfoByNameAndLevel(achieveAddForm.getBossname(), LevelType.이지 );
                break;
        }

        //viewName += achieveAddForm.getBossname().getBytes(StandardCharsets.UTF_8) +"/";

        byte[] bytes = achieveAddForm.getBossname().getBytes(StandardCharsets.UTF_8);
        viewName +="bName=";
        for (byte b : bytes) {
            viewName += String.format("%03d", (int)b *-1);
            System.out.println(String.format("%03d", (int)b *-1));
        }
        viewName +="&partyCnt=";


        if(bossInfo == null)
        {
            mav.addObject("msg","보스 정보가 잘못되었습니다.");
            mav.addObject("url","/api/");
            mav.setViewName("Alert");
            return mav;
        }

        achieve.setBoss(bossInfo);
        ItemInfo itemInfo = mbas.findItemInfoByName(achieveAddForm.getItemname());

        if(itemInfo == null )
        {
            mav.addObject("msg","아이템 정보가 잘못되었습니다.");
            mav.addObject("url","/api/");
            mav.setViewName("Alert");
            return mav;
        }

        achieve.setItem(itemInfo);


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
            achieveAddForm.setCount(1);
        }

        try
        {
            achieve.setItemCount(achieveAddForm.getCount());
        }
        catch (Exception ex)
        {
            achieve.setItemCount(1);
        }
        if(achieveAddForm.getPartyInfo() == null)
        {
            mav.addObject("msg","파티 정보가 잘못되었습니다.");
            mav.addObject("url","/api/");
            mav.setViewName("Alert");
            return mav;
        }
        try
        {
            achieve.setPartyInfo(achieveAddForm.getPartyInfo());

            viewName +=achieveAddForm.getPartyInfo().toString();

        }
        catch (Exception ex)
        {
            achieve.setPartyInfo(1L);
            viewName +="1";
        }


        achieve.setCalEnd(false);
        achieve.setVisibleOnTable(false);

        mbas.saveAchieve(achieve);
        mav.setViewName(viewName);

        return mav;
    }




}
