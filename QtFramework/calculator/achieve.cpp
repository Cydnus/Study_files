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
        if( lst[8] == "true" )
            b1 = true;
        if(lst[9] == "true")
            b2 = true;
        // qDebug()<<lst[0].split(' ')[0]<<"\t"<<QDate::fromString(lst[0].split(' ')[0], "yyyy-MM-dd");
        AchieveEntity ae(
                    lst[0].toInt(),
                    QDate::fromString(lst[1], "yyyy-MM-dd"),
                    lst[3],
                    lst[2],
                    lst[5],
                    lst[4].toInt(),
                    lst[6].toULongLong(),
                    lst[7].toInt(),
                    b1,
                    b2);

        achieveTotalList.push_back(ae);
    }
    fLog.close();

}

Achieve* Achieve::getInstance()
{
    if(!achieve)
        achieve = new Achieve;
    return achieve;
}


uint64_t Achieve::getAddIndex()
{
    uint64_t ret = achieveTotalList.size();

    //qDebug()<<ret<<"\t"<<(achieveTotalList.end()-1)->getId();

    if( ret <= (achieveTotalList.end()-1)->getId())
    {
        ret = (achieveTotalList.end()-1)->getId()+1;
    }
    return ret;
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
    QFile fLog("log.Maple");


    if(!fLog.open(QFile::WriteOnly | QFile::Text))
    {
        return false;
    }

    for(AchieveEntity ae : achieveTotalList)
    {
        fLog.write(ae.toWriteFile().toStdString().c_str());
    }

    fLog.close();

    return true;
}

int getIndexFromId(vector<AchieveEntity> data, uint64_t id, int start, int end)
{
    if( start >= end)
        return -1;

    int mid = (start + end) / 2;

    if(data[mid].getId() == id)
        return mid;
    if(data[mid].getId() < id )
        return getIndexFromId(data, id, mid+1, end);
    return getIndexFromId(data, id,start, mid-1);

}


void Achieve::setCalEnd(uint64_t id, bool state)
{
    int ind = getIndexFromId(achieveTotalList, id, 0,achieveTotalList.size());
    if( ind == -1)
        return;
    achieveTotalList[ind].setCalEnd(state);

}
void Achieve::setAllCalEnd()
{
    int size =  achieveTotalList.size();
    for(int i = 0 ; i< size; i ++)
        achieveTotalList[i].setCalEnd(true);
    saveData();
}

void Achieve::changeData(AchieveEntity ae)
{
    int ind = getIndexFromId(achieveTotalList, ae.getId(), 0,achieveTotalList.size());

    achieveTotalList[ind] = ae;

    saveData();
}
