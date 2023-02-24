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
        if( a> b)
            a = c/b;
        else
            a= c/a;
        cout<<"#"<<testCase<<" "<<a<<endl;
    }
    return 0;
}
