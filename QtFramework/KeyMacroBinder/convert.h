#ifndef CONVERT_H
#define CONVERT_H
#include <QString>
#include <map>

using namespace std;

class Convert
{
public:
    static Convert* getInstance();


    int getKeyCode(QString Key);
    QString getKeyString(int);

private:
    Convert();
    static Convert* convert;

    map<QString, int> codeMap;

    map<int, QString> keyMap ;

};

#endif // CONVERT_H
