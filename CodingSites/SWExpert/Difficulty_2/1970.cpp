#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    vector<int> money={50000,10000,5000,1000,500,100,50,10};
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int inp;
        cin>>inp;


        cout<<"#"<<testCase<<endl;
        for(int m : money)
        {
            int cnt = inp/m;
            inp -= m*cnt;
            cout<<cnt<<" ";
        }
        cout<<endl;
    }
    return 0;
}
