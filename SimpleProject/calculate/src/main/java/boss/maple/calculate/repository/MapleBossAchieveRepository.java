package boss.maple.calculate.repository;

import boss.maple.calculate.entity.Achieve;
import boss.maple.calculate.entity.BossInfo;
import boss.maple.calculate.entity.ItemInfo;
import boss.maple.calculate.entity.LevelType;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import javax.transaction.Transactional;
import java.util.List;

@Repository
public interface MapleBossAchieveRepository extends JpaRepository<Achieve, Long> {


    @Query("SELECT a FROM Achieve a WHERE a.visibleOnTable = false")
    List<Achieve> findAllByVisibleOnTable();

    @Query("SELECT a FROM Achieve a")
    List<Achieve> findAchieveAll();

    @Query("SELECT DISTINCT i.name FROM ItemInfo i")
    List<String> findAllItemInfoName();


    @Query("SELECT DISTINCT i.name FROM BossInfo i")
    List<String> findAllBossInfoName();

    @Query("SELECT b FROM BossInfo b WHERE b.name=:#{#name} AND b.level=:#{#level}")
    BossInfo findBossInfoByNameAndLevel(@Param("name") String name, @Param("level") LevelType level );

    @Query("SELECT i FROM ItemInfo i WHERE i.name=:#{#name}")
    ItemInfo findItemInfoByName(@Param("name") String name);

    @Query("SELECT a FROM Achieve a WHERE a.id=:#{#id}")
    Achieve findAchieveById(@Param("id") Long id);

    @Transactional
    @Modifying
    @Query("DELETE FROM Achieve a WHERE a.id=:#{#id}")
    int deleteAchieveById(@Param("id") Long id);


    @Transactional
    @Modifying
    @Query("UPDATE Achieve a SET a.calEnd=true WHERE a.id=:#{#id}")
    int updateAchieveCalEndById(@Param("id") Long id);


    @Transactional
    @Modifying
    @Query("UPDATE Achieve a SET a.visibleOnTable=true WHERE a.id=:#{#id}")
    int updateAchieveVisibleOnTableById(@Param("id") Long id);

}
