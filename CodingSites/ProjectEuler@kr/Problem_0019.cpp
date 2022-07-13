#include <iostream>
#include <vector>



using namespace std;

int main()
{
    int year = 1900;
    int weekOfDay = 1;

    vector<int> dayOfMonth = {
        31,28,31, 30,31,30,
        31,31,30, 31,30,31
        };

    // set Date 1901 01 01
    weekOfDay += 365;
    if(year % 400 == 0 && year % 4 == 0)
        weekOfDay ++;
    weekOfDay %=7;    
    year ++;

    int month = 0;
    int cnt = 0;
    while( year < 2001)
    {
        weekOfDay += dayOfMonth[month];
        if(month == 1 && year % 4 == 0 && ( year %100 != 0 || year % 400 == 0 ))
            weekOfDay ++;
        weekOfDay %=7;

        month ++;
        if( month == 12)
        {
            year ++;
            month = 0;
        }
        if(weekOfDay == 0)
            cnt ++;
    }

    cout<<year<<"\t"<<month<<"\t"<<weekOfDay<<"\t"<<cnt<<endl;

    return 0;
}
