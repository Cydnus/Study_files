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
        int n, k;
        cin>>n>>k;
        int count = n*k;
        int sw = 1, ind = 0;

        vector<int> sum(k,0);
        for(int i = 1; i <= count; i++)
        {
            sum[ind] += i;
            
            ind += sw;
            if( ind == k || ind == -1)
            {
                sw *= -1;
                ind += sw;                
            }
        }

        cout<<"#"<<testCase<<" ";
        for(int i = 0; i<k; i++)
            cout<<sum[i]<<" ";
        cout<<endl;

    }
    return 0;
}