#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string str;
        cin>>str;

        int now = 0;
        int hire = 0;
        for(int i = 0; i<str.size(); i++)
        {
            if(now >= i)
            {
                now += str[i]-'0';
            }
            else
            {
                hire += i - now;
                now += i - now;
                now += str[i]-'0';
            }
        }

        cout<<"#"<<testCase<<" "<<hire<<endl;
    }
    return 0;
}
