#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int k;
        cin>>k;
        int cnt = pow(2,k)-1;
        vector<int> tree(cnt,0);
        for(int i = 0 ;i< cnt; i++)
            cin>>tree[i];

        cout<<"#"<<testCase<<" ";
        vector<bool> check(cnt,false);
        for(int i = (cnt+1)/2; i > 0 ; i/=2)
        {
            for(int j = i-1; j<cnt; j+= i)
            {
                if(!check[j])
                {
                    cout<<tree[j]<<" ";
                    check[j] = true;
                }
            }
            cout<<endl;
        }
    }
    
    return 0;
}
