#ifndef ACHIEVEENTITY_H
#define ACHIEVEENTITY_H

#include <QMainWindow>
#include <QFile>
#include <QDate>

#include <QCheckBox>
#include <vector>

using namespace std;

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
    bool visible;
public:
    AchieveEntity(){}
    AchieveEntity(QDate date,
                  QString bossName,
                  QString bossLevel,
                  QString itemName,
                  int itemCount,
                  uint64_t price,
                  int partyCount,
                  bool calEnd,
                  bool visible)
    {
        this->date = date;
        this->bossName = bossName;
        this->bossLevel = bossLevel;
        this->itemName = itemName;
        this->price = price;
        this->itemCount =  itemCount;
        this->partyCount = partyCount;
        this->calEnd = calEnd;
        this->visible = visible;
    }

    void setDate(QDate date){ this->date = date;}
    void setBossName(QString bossName){ this->bossName = bossName;}
    void setBossLevel(QString bossLevel){ this->bossLevel = bossLevel;}
    void setItemName(QString itemName){ this->itemName = itemName;}
    void setPrice(uint64_t price){ this->price = price;}
    void setItemCount(int itemCount){ this->itemCount = itemCount;}
    void setPartyCount(int partyCount){ this->partyCount = partyCount;}
    void setCalEnd(bool calEnd){ this->calEnd = calEnd;}
    void setVisible(bool visible){ this->visible = visible;}


    QDate getDate(){return date;}
    QString getBossName(){return bossName;}
    QString getBossLevel(){return bossLevel;}
    QString getItemName(){return itemName;}
    uint64_t getPrice(){return price;}
    int getItemCount(){return itemCount;}
    int getPartyCount(){return partyCount;}
    bool isCalEnd(){return calEnd;}
    bool isVisible(){return visible;}

};

#endif // ACHIEVEENTITY_H
