#ifndef ACHIEVE_H
#define ACHIEVE_H

#include "TotalHeader.h"

class AchieveEntity
{
    QDate date;
    QString bossName;
    QString bossLevel;
    QString itemName;
    uint64_t price;
    int itemCount;
    int partyCount;
    bool calEnd;
public:
    AchieveEntity();
    AchieveEntity(QDate date,
                  QString bossName,
                  QString bossLevel,
                  QString itemName,
                  uint64_t price,
                  int itemCount,
                  int partyCount,
                  bool calEnd);

    void setDate(QDate date){ this->date = date;}
    void setBossName(QString bossName){ this->bossName = bossName;}
    void setBossLevel(QString bossLevel){ this->bossLevel = bossLevel;}
    void setItemName(QString itemName){ this->itemName = itemName;}
    void setPrice(uint64_t price){ this->price = price;}
    void setItemCount(int itemCount){ this->itemCount = itemCount;}
    void setPartyCount(int partyCount){ this->partyCount = partyCount;}
    void setCalEnd(bool calEnd){ this->calEnd = calEnd;}


    QDate getDate(){return date;}
    QString getBossName(){return bossName;}
    QString getBossLevel(){return bossLevel;}
    QString getItemName(){return itemName;}
    uint64_t getPrice(){return price;}
    int getItemCount(){return itemCount;}
    int getPartyCount(){return partyCount;}
    bool isCalEnd(){return calEnd;}

};

class Achieve
{
public:
    Achieve* getInstance();
  private:
    Achieve *achieve = new Achieve();
    vector<AchieveEntity> achieveList;
    Achieve();

};


#endif // ACHIEVE_H
