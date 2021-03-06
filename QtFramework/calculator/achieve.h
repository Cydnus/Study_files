#ifndef ACHIEVE_H
#define ACHIEVE_H

#include "AchieveEntity.h"


class Achieve
{
public:
    static Achieve* getInstance();

    vector<AchieveEntity> getVisibleList();
    void AppendData(AchieveEntity ae);
    bool saveData();


    void setCalEnd(uint64_t ae, bool state);
    void setAllCalEnd();
    uint64_t getAddIndex();

    void changeData(AchieveEntity ae);

    void remove(vector<uint64_t>);
    void toLog(vector<uint64_t>);

    AchieveEntity getAchieveEntity(uint64_t id);

  private:

    static Achieve *achieve;
    vector<AchieveEntity> achieveTotalList;
    vector<AchieveEntity> visibleList;
    Achieve();


};



#endif // ACHIEVE_H
