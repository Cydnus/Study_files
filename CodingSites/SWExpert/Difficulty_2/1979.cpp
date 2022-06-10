#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getVer(vector<vector<int>> mat, int row, int target)
{
    int cnt = 0;
    int ret = 0;
    for(int i = 0 ; i< mat.size()-1; i++)
    {   
        if( mat[row][i] == 1)
        {
            cnt ++;
            if( cnt == target && mat[row][i+1] == 0)
                ret ++;
        }
        else if(mat[row][i] == 0)
        {
            cnt = 0;
        }
    }
    if( mat[row][mat.size()-1] == 1)
    {
        cnt ++;
        if( cnt == target )
            ret ++;
    }
    return ret;
}
int getHor(vector<vector<int>> mat, int col, int target)
{
    int cnt = 0;
    int ret = 0;
    for(int i = 0 ; i< mat.size()-1; i++)
    {   
        if( mat[i][col] == 1)
        {
            cnt ++;
            if( cnt == target && mat[i+1][col] == 0)
                ret ++;
        }
        else if(mat[i][col] == 0)
        {
            cnt = 0;
        }
    }
    if( mat[mat.size()-1][col] == 1)
    {
        cnt ++;
        if( cnt == target )
            ret ++;
    }
    return ret;
}


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n, k;
        cin>>n>>k;

        vector<vector<int>> matrix(n,vector<int>(n,0));

        for(int i =0 ; i<n;i++)
        {
            for(int j = 0; j<n ; j++)
            {
                int inp;
                cin>>inp;
                matrix[i][j] = inp;
            }
        }
        int sum = 0;
        for(int i = 0 ; i<n;i++)
        {
            sum += getHor(matrix,i,k) + getVer(matrix,i,k);
        }


        cout<<"#"<<testCase<<" "<<sum<<endl;
    }
    return 0;
}
