#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n,d;
        cin>>n>>d;
        d = d*2 +1;
        n += d-1;
        cout<<"#"<<testCase<<" "<<n/d<<endl;
    }
    return 0;
}
