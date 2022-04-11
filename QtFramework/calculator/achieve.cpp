#include "achieve.h"

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
        if(str.endsWith('0'))
            row++;
    }

}

Achieve* Achieve::getInstance()
{
    return achieve;
}
