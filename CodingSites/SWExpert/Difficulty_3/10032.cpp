#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n, k;
        cin>>n>>k;

        cout<<"#"<<testCase<<" ";

        if( n %k == 0 )
            cout<<0<<endl;
        else   
            cout<<1<<endl;

    }
    return 0;
}
