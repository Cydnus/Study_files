#include <iostream>

#include <vector>

using namespace std;

int matrix(vector<vector<int>> mat,int m, int n)
{
    vector<vector<int>> cache(mat.size(), vector<int>(mat[0].size()));

    for(int i =0; i<=m; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            if(i== 0 && j == 0)
                  cache[i][j] = mat[0][0];
            else if( i == 0)
                cache[i][j] = mat[i][j]+cache[i][j-1];
            else if( i == 0)
                cache[i][j] = mat[i][j]+cache[i-1][j];
            else
            {
                cache[i][j] = mat[i][j];
                if( cache[i][j-1] > cache[i-1][j])
                    cache[i][j] += cache[i-1][j];
                else
                   cache[i][j] += cache[i][j-1];
            }

        }
    }
    return cache[m][n];
}


int lcs_int(string x, string y)
{
    int m = x.size(), n = y.size();
    vector<vector<int>> mat(m+1,vector<int>(n+1));

    for(int i = 1; i <=m; i++)
    {
        for(int j = 1; j<=n ; j++)
        {
            if(x[i] == y[j])
                mat[i][j] = mat[i-1][j-1]+1;
            else
            {
                if(mat[i-1][j] > mat[i][j-1])
                    mat[i][j] = mat[i-1][j];
                else
                    mat[i][j] = mat[i][j-1];

            }
        }
    }
    return mat[m][n];


}



int main()
{
    vector<vector<int>> mat = {
        {6,7,12,5},
        {5,3,11,18},
        {7,17,3,3},
        {8,10,14,9}
    } ;

    cout<<matrix(mat,3,3)<<endl;

    cout<< lcs_int("ABCBDAB","BDCABA")<<endl;

    return 0;
}