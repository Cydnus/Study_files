#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string num;
        cin>>num;
        int n = num.back()-'0';
        
        cout<<"#"<<testCase<<" ";

        if(n %2 == 0)
            cout<<"Even"<<endl;
        else
            cout<<"Odd"<<endl;

    }
    return 0;
}
