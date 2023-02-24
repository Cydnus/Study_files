#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    
   //freopen("not_input_1859.txt", "r", stdin);

    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;
        
        vector<int64_t> trade(n,0);

        for(int i = 0; i<n; i++)
        {
            int64_t price;
            cin>>price;
            trade[i] = price;
        }

        int max = trade[n-1];
        int64_t price = 0;

        for(int i = n-2; i>=0; i--)
        {
            if( max < trade[i])
                max = trade[i];
            else if(max > trade[i])
                price += max-trade[i];
        }

        cout<<"#"<<testCase<<" "<<price<<endl;
    }
    return 0;
}
