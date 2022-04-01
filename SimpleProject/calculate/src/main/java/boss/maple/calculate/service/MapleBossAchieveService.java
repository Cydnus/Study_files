package boss.maple.calculate.service;

import boss.maple.calculate.entity.Achieve;
import boss.maple.calculate.repository.MapleBossAchieveRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.List;

@RequiredArgsConstructor
@Service
public class MapleBossAchieveService {

    private final MapleBossAchieveRepository mapleBossAchieveRepository;

    public List<Achieve> findAll()
    {
        return this.mapleBossAchieveRepository.findAll();
    }
    public  List<Achieve> findAllByVisibleOnTable()
    {
        return this.mapleBossAchieveRepository.findAllByVisibleOnTable();
    }
}
