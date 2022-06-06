#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool CheckVertical(vector<vector<int>> g, int n)
{
    vector<int> check(9,0);
    for(int i =0  ; i<9 ; i++)
    {
        check[g[i][n]-1]++;
        if( check[g[i][n]-1] > 1)
            return false;
    }
    return true;
}

bool CheckHorizontal(vector<vector<int>> g, int n)
{
    vector<int> check(9,0);
    for(int i =0  ; i<9 ; i++)
    {
        check[g[n][i]-1]++;
        if( check[g[n][i]-1] > 1)
            return false;
    }
    return true;
}

bool CheckCube(vector<vector<int>> g, int n, int m)
{
    vector<int> check(9,0);
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            check[g[n+i][m+j]-1] ++;
            if(check[g[n+i][m+j]-1]>1)
                return false;
        }
    }
    return true;
}


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        vector<vector<int>> graph(9,vector<int>(9,0));

        for(int i =0 ; i<9; i++)
        {
            for(int j = 0; j<9;j++)
            {
                int inp;
                cin>> inp;
                graph[i][j] = inp;
            }
        }
        bool check = true;
        for(int i =0; i<9 && check ; i++)
        {
            check &= CheckVertical(graph,i) & CheckHorizontal(graph,i);
        }
        for(int i = 0; i<9 && check; i+=3)
        {
            for(int j = 0 ; j<9 && check ; j+=3)
            {
                check &= CheckCube(graph,i,j);
            }
        }
        cout<<"#"<<testCase<<" ";
        
        if(check)
            cout<<1<<endl;
        else   
            cout<<0<<endl;
    }
    return 0;
}
