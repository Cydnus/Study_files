#include <iostream>

using namespace std;

bool isOn(int num, int cnt)
{
    if( cnt == 0)
        return true;
    if( (num & 0x01) == 0)
        return false;

    return isOn(num>>1, cnt-1);
}


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n,m;
        cin>>n>>m;

        cout<<"#"<<testCase<<" ";
        if(isOn(m,n))        
            cout<<"ON"<<endl;
        else
            cout<<"OFF"<<endl;
    }
    return 0;
}
