#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;
        cout<<"#"<<testCase<<endl;
        vector<vector<int>> matrix(n,vector<int>(n,1));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j <= i; j++)
            { 
                if( i == 0)
                    matrix[i][j] = 1;
                else if( j == 0 || j == i)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
                
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
