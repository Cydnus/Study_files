package boss.maple.calculate.service;

import boss.maple.calculate.entity.Achieve;
import boss.maple.calculate.entity.BossInfo;
import boss.maple.calculate.entity.ItemInfo;
import boss.maple.calculate.entity.LevelType;
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

    public  List<String> findAllItemInfoName()
    {
        return mapleBossAchieveRepository.findAllItemInfoName();
    }

    public  List<String> findAllBossInfoName()
    {
        return mapleBossAchieveRepository.findAllBossInfoName();
    }

    public BossInfo findBossInfoByNameAndLevel(String name, LevelType level )
    {
        return mapleBossAchieveRepository.findBossInfoByNameAndLevel(name, level);
    }

    public ItemInfo findItemInfoByName(String name)
    {
        return mapleBossAchieveRepository.findItemInfoByName(name);
    }

    public Achieve saveAchieve( Achieve achieve)
    {
        return this.mapleBossAchieveRepository.save(achieve);
    }

    public Achieve findAchieveById(Long id)
    {
        return this.mapleBossAchieveRepository.findAchieveById(id);
    }


}
