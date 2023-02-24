#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        cout<<"#"<<testCase<<" ";
        if( a == b)
            cout<<c<<endl;
        else if( a == c)
            cout<<b<<endl;
        else if( b == c)
            cout<<a<<endl;

    }
    return 0;
}
