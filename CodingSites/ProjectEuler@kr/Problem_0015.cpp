#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    freopen("output_15.txt", "w", stdout);  
    vector<vector<uint64_t>> mat(21,vector<uint64_t>(21,0));
    mat[0][0] = 0;
    for(int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if( i == 0 && j == 0)
                mat[i][j] = 1;
            else if( i == 0 || j == 0)
                mat[i][j] = 1;
            else
                mat[i][j] = mat[i-1][j]+mat[i][j-1];
        }
    }

    for(int i = 0; i<21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<mat[20][20]<<endl;
    return 0;
}
