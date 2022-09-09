#include <iostream>
#include <vector>

using namespace std;

int graph[12][2];
bool check[12];

int dfs(int cnt, int node=0, int sum=0)
{
    int ret = 2000;
    bool check_zero = true;
    
    for(int i = 2; i < cnt; i++)
    {
        if( check[i] == false)
        {
            check_zero = false;
            check[i] = true;
            int dist = abs(graph[node][0] - graph[i][0]) + 
                        abs(graph[node][1] - graph[i][1]);
            int tmp_ret = dfs(cnt, i, sum+dist);
            check[i] = false;
            if(tmp_ret < ret)
                ret = tmp_ret;
        }
    }
    if(check_zero)
    {
        int dist = abs(graph[node][0] - graph[1][0]) + 
                    abs(graph[node][1] - graph[1][1]);        
        return sum+dist;
    }
    return ret;
}

void init()
{
    for(int i = 0; i<12; i++)
    {
        graph[i][0] = 0;
        graph[i][1] = 0;
        check[i] = false;
    }
}

int main()
{
    int T;
    cin>>T;
    

    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;
        init();

       // vector<pair<int,int>> graph;
        // 0 : 회사  1 : 집  2~ : 고객좌표

        for(int i = 0 ; i<n+2; i++)
        {
           // int x, y;
            //cin>>x>>y;
            //graph.push_back(make_pair(x,y));
            cin>>graph[i][0]>>graph[i][1];
        }
        
        //vector<bool> check(n+2, false);

        cout<<"#"<<testCase<<" "<<dfs(n+2)<<endl;
    }

    return 0;
}
