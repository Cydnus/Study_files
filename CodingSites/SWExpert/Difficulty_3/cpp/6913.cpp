#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n, m;
        cin>>n>>m;

        vector<int> per(m+1,0);

        for(int i  = 0; i<n; i++)
        {
            int sum = 0;
            for(int j = 0; j<m;j++)
            {
                int col;
                cin>>col;
                if( col == 1)
                    sum++;
            }
            per[sum] ++;
        }

        int ind = m;
        for(int i = m; i >= 0 && per[ind] == 0; i--)
            if(per[i] != 0)
                ind = i;

        cout<<"#"<<testCase<<" "<<per[ind]<<" "<<ind<<endl;
    }
    return 0;
}
