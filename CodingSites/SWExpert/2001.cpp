#include <iostream>
#include <vector>

using namespace std;



int main()
{
    int TestNo;
    cin>>TestNo;

    for(int testCase = 1; testCase<=TestNo; testCase++)
    {
        int m, n;
        cin >> n >> m;
        vector<vector<int>> table(n,vector<int>(n,0));
        for(int i = 0; i<n; i++)
        {
            for(int j = 0 ; j<n;j++)
            {
                int inp;
                cin>>inp;
                table[i][j] =inp;
            }
        }
        int max = 0;
        for(int i = 0; i<n-m+1; i++)
        {
            for(int j = 0 ; j<n-m+1;j++)
            {
                int tmp = 0;
                for(int k = i; k<i+m; k++)
                    for(int l = j; l < j+m; l++)
                        tmp += table[k][l];

                if(max < tmp)
                    max = tmp;
            }
        }
        cout<<"#"<<testCase<<" "<<max<<endl;

    }
}
