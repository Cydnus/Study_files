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
        int n, cnt;
        cin>>n>>cnt;
        vector<int> vec(n, 0);
        for(int i = 0 ; i<cnt; i++)
        {
            int per;
            cin>>per;
            vec[per-1] =1;
        }

        
        cout<<"#"<<testCase<<" ";
        
        for(int i = 0 ; i<n; i++)
            if(vec[i] == 0)
                cout<<i+1<<" ";

        cout<<endl;
    }
    return 0;
}
