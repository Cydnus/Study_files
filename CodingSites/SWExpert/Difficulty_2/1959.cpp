#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;

    cin>>T;

    for(int testCase = 1; testCase <= T; testCase++)
    {
        int n,m;
        cin>>n>>m;

        vector<int64_t> vecA(n,0);
        vector<int64_t> vecB(m,0);

        for(int i = 0 ; i< n; i++)
        {  
            int64_t inp;
            cin>>inp;
            vecA[i] = inp;
        }

        for(int i = 0 ; i< m; i++)
        {  
            int64_t inp;
            cin>>inp;
            vecB[i] = inp;
        }

        if( n > m)
        {
            vector<int64_t> vectemp(vecA);
            vecA = vecB;
            vecB = vectemp;
            int itemp = m;
            m = n;
            n = itemp;
        }


        int max_sum = 0;
        for(int i = 0; i<m-n+1; i++)
        {
            int sum = 0;
            for(int j = 0; j<n;j++)
            {
                sum += vecA[j] * vecB[i+j];
            }
            if( sum > max_sum)
                max_sum = sum;
        }
        cout<<"#"<<testCase<<" "<<max_sum<<endl;


    }
    return 0;
}