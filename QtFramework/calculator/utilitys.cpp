#include "utilitys.h"

uint64_t getMeso(QString str)
{
    if(str.contains("메소"))
        return str.sliced(0,str.size()-2).replace(",","").toULongLong();
    return str.replace(",","").toULongLong();
}


QStringList getcbItemsFromFile(QString fileName) /* 파일 읽어오기 */
{
    QFile fItemName(fileName);

    if(!fItemName.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"Not Open";

    }

    QTextStream tsItems(&fItemName);

    QStringList items;
    while(!tsItems.atEnd())
    {
        QString item = tsItems.readLine();
        items.append(item);
    }
    return items;
}
