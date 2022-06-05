#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int hour, min;
        int add_hour, add_min;

        cin>>hour>>min>>add_hour>>add_min;

        min += add_min;
        hour+= add_hour;

        hour += min/60;
        min %= 60;

        hour %= 12;
        if(hour == 0)
            hour = 12;

        cout<<"#"<<testCase<<" "<<hour<<" "<<min<<endl;
    }
    return 0;
}
