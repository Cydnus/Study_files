#include "achieve.h"

Achieve* Achieve::achieve = nullptr;

Achieve::Achieve()  /* 생성자 */
{    

    QFile fLog("log.Maple");


    if(!fLog.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"Not Open";
    }
    QTextStream tsLogs(&fLog);

    QStringList logs = tsLogs.readAll().split("\n");

    int row = 0;
    for(const QString &str : logs)
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
        qDebug()<<"Achieve : Achieve() : "<<lst[0].toInt();
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

Achieve* Achieve::getInstance()  /* single ton patton */
{
    if(!achieve)
        achieve = new Achieve;
    return achieve;
}

uint64_t Achieve::getAddIndex() /* 추가시 들어갈 인덱스 */
{
    uint64_t ret = achieveTotalList.size();

    //qDebug()<<ret<<"\t"<<(achieveTotalList.end()-1)->getId();

    if( ret <= (achieveTotalList.end()-1)->getId())
    {
        ret = (achieveTotalList.end()-1)->getId()+1;
    }
    return ret;
}

vector<AchieveEntity> Achieve::getVisibleList() /* 테이블 표시 리스트  */
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

void Achieve::AppendData(AchieveEntity ae) /* 엔티티 추가 */
{
    achieveTotalList.push_back(ae);
    saveData();
}

bool Achieve::saveData() /* 저장 */
{
    QFile fLog("log.Maple");


    if(!fLog.open(QFile::WriteOnly | QFile::Text))
        return false;

    for(AchieveEntity ae : achieveTotalList)
        fLog.write(ae.toWriteFile().toStdString().c_str());

    fLog.close();

    return true;
}

int getIndexFromId(vector<AchieveEntity> data, uint64_t id, int start, int end) /* id로 부터 인덱스 찾기 */
{
    if( start > end)
        return -1;

    int mid = (start + end) / 2;

    if(data[mid].getId() == id)
        return mid;
    if(data[mid].getId() < id )
        return getIndexFromId(data, id, mid+1, end);
    return getIndexFromId(data, id,start, mid-1);

}

void Achieve::setCalEnd(uint64_t id, bool state) /* 한개 정산 */
{
    int ind = getIndexFromId(achieveTotalList, id, 0,achieveTotalList.size());
    if( ind == -1)
        return;
    achieveTotalList[ind].setCalEnd(state);

}

void Achieve::setAllCalEnd() /* 모두 정산 */
{
    int size =  achieveTotalList.size();
    for(int i = 0 ; i< size; i ++)
        achieveTotalList[i].setCalEnd(true);
    saveData();
}

void Achieve::changeData(AchieveEntity ae) /* 값 변경 */
{
    int ind = getIndexFromId(achieveTotalList, ae.getId(), 0,achieveTotalList.size());

    achieveTotalList[ind] = ae;

    saveData();
}

void Achieve::remove(vector<uint64_t> listId) /* 항목 삭제 */
{
    for(uint64_t id : listId )
    {
        int ind = getIndexFromId(achieveTotalList,id,0, achieveTotalList.size());
        qDebug()<<"Achieve Remove() : "<<id<<"\t" << ind;
        if(ind !=-1)
        {
            qDebug()<<(achieveTotalList.begin()+ind)->getId();
            achieveTotalList.erase(achieveTotalList.begin()+ind);
        }
    }
    saveData();
}

void Achieve::toLog(vector<uint64_t> listId)  /* 테이블 표시 제외 */
{
    for(uint64_t id : listId )
    {
        int ind = getIndexFromId(achieveTotalList,id,0, achieveTotalList.size());
        qDebug()<<"Achieve toLog() : "<<id<<"\t" << ind;
        if(ind !=-1)
        {
            qDebug()<<(achieveTotalList.begin()+ind)->getId();
            achieveTotalList[ind].setVisible(true);
        }
    }
    saveData();
}
