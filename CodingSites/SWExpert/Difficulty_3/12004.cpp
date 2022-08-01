#include <iostream>

using namespace std;

bool check(int n)
{

    for(int i = 9; i>=1; i--)
    {
        if( n % i == 0)
        {
            if( n / i >= 10)
                return false;
            return true;
        }
    }
    return false;
}


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;

        cout<<"#"<<testCase<<" ";

        if( check(n))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
