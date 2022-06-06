#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int cnt;
        cin>> cnt;
        int mod = 1, sum = 0;
        for(int i = 1 ; i<=cnt ; i++)
        {
            sum += i*mod;
            mod *= -1;
        }
        cout<<"#"<<testCase<<" "<<sum<<endl;
    }
    return 0;
}
