#ifndef CONVERT_H
#define CONVERT_H
#include <QString>
#include <map>
#include <QStringList>

using namespace std;

class Convert
{
public:
    static Convert* getInstance();


    int getKeyCode(QString Key);
    QString getKeyString(int);
    QStringList getKeyStrings();

private:
    Convert();
    static Convert* convert;

    map<QString, int> codeMap;

    map<int, QString> keyMap ;
    QStringList keyStrings;

};

#endif // CONVERT_H
