#include "achieve.h"

Achieve* Achieve::achieve = nullptr;

Achieve::Achieve()
{    

    QFile fLog("log.Maple");


    if(!fLog.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"Not Open";
    }
    QTextStream tsLogs(&fLog);

    QStringList logs = tsLogs.readAll().split("\n");

    int row = 0;
    for(QString str : logs)
    {
        if(str.length()== 0)
            continue;

        QStringList lst = str.split("\t");
        //  2021-10-09 20:44:43	하드	스우	2	추가 경험치 쿠폰	2199800	4	1	1
        bool b1 = false ,b2 = false;
        if( lst[7].toInt() == 1 )
            b1 = true;
        if(lst[8].toInt() == 1)
            b2 = true;
        // qDebug()<<lst[0].split(' ')[0]<<"\t"<<QDate::fromString(lst[0].split(' ')[0], "yyyy-MM-dd");
        AchieveEntity ae(
                    QDate::fromString(lst[0].split(' ')[0], "yyyy-MM-dd"), lst[1], lst[2], lst[4],lst[3].toInt(), lst[5].toULongLong(), lst[6].toInt(), b1,b2);

        achieveTotalList.push_back(ae);
    }

}

Achieve* Achieve::getInstance()
{
    if(!achieve)
        achieve = new Achieve;
    return achieve;
}


vector<AchieveEntity> Achieve::getVisibleList()
{
    vector<AchieveEntity> ret;
    int size = achieveTotalList.size();
    for(int i = 0 ; i< size ; i++)
    {
        if( achieveTotalList[i].isVisible() == false )
            ret.push_back(achieveTotalList[i]);
    }
    return ret;
}

void Achieve::AppendData(AchieveEntity ae)
{
    achieveTotalList.push_back(ae);
    saveData();
}

bool Achieve::saveData()
{
    return true;
}
