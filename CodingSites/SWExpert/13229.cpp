#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;

    map<string, int> days={
        {"SUN", 7},        {"MON", 6},        {"TUE", 5},
        {"WED", 4},        {"THU", 3},        {"FRI", 2},
        {"SAT", 1}
    };

    for(int i = 1; i<=t; i++)
    {
        string str;
        cin>>str;
        cout<<"#"<<i<<" "<<days[str]<<endl;
    }

    return 0;
}
