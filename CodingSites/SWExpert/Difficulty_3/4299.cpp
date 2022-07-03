#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    int def = (11*24+11)*60+11;
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int d,h,m;
        cin>>d>>h>>m;

        int toMin = (d * 24 +h) *60 + m;
        cout<<"#"<<testCase<<" ";
        if( toMin < def)
            cout<<-1<<endl;
        else if( toMin == def)
            cout<<0<<endl;
        else if( toMin > def)
            cout<<toMin-def<<endl;
        
    }
    return 0;
}
