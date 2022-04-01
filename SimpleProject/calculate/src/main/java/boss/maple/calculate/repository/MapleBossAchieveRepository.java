package boss.maple.calculate.repository;

import boss.maple.calculate.entity.Achieve;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface MapleBossAchieveRepository extends JpaRepository<Achieve, Long> {


    @Query("SELECT a FROM Achieve a WHERE a.visibleOnTable = false")
    List<Achieve> findAllByVisibleOnTable();



}
