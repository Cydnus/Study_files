#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>> n;
        cout<<"#"<<testCase<<" ";
        for(int i = 0 ; i<n; i++)
            cout<<1<<"/"<<n<<" ";
        cout<<endl;
    }
    return 0;
}
