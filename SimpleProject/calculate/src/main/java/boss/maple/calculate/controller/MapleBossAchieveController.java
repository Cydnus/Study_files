package boss.maple.calculate.controller;

import boss.maple.calculate.entity.Achieve;
import boss.maple.calculate.entity.AchieveForShow;
import boss.maple.calculate.service.MapleBossAchieveService;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.List;

@RequiredArgsConstructor
@Controller
//@RestController
public class MapleBossAchieveController {

    private final MapleBossAchieveService mbas;
    private final ObjectMapper mapper;

    @RequestMapping({"/api/", "/api/achieve"})
    public String showAchieve(final Achieve achieve, Model model) throws JsonProcessingException
    {
        List<Achieve> all = mbas.findAllByVisibleOnTable();
        List<AchieveForShow> shows = new ArrayList<AchieveForShow>();
        all.stream().forEach(v->shows.add(new AchieveForShow(v)));

        model.addAttribute("achieveWithBossAndItem", shows);
        shows.stream().forEach(v-> System.out.println("v.isCalEnd() = " + v.isCalEnd()));
        //return mapper.writeValueAsString(shows);
        return "Acheive";
    }


}
