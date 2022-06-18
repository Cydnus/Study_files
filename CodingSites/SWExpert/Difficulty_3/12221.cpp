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
        int a, b;
        cin>>a>>b;
        cout<<"#"<<testCase<<" ";
        if( a> 9 || b> 9)
            cout<<-1<<endl;
        else
            cout<<a *b <<endl;
    }
    return 0;
}
