#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int test_case;
    cin>> test_case;

    vector<int> Days = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    for(int test_num = 1 ; test_num<= test_case ; test_num++)
    {
        
        string str;
        cin>>str;

        int date = stoi(str);
        
        int day = date%100;
        date /= 100;
        int month = date %100;
        date /= 100;

        cout<<"#"<<test_num<<" ";
        if(month >= 1 && month <= 12 && day >= 1 && day<=Days[month])
        {
            str.insert(str.begin()+6,'/');
            str.insert(str.begin()+4,'/');
            cout<<str<<endl;
        }
        else
            cout<<-1<<endl;

    }
    return 0;
}
