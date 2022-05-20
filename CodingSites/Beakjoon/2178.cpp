#include <iostream>

#include <vector>
#include <string>

#include <queue>

#define CHECK(x,y) (graph[x][y] == 1 && visit[x][y][0] == -1)

using namespace std;


void Check_Top(vector<vector<int>> graph, 
                vector<vector<vector<int>>> &visit,
                queue<vector<int>> &que,
                int x, 
                int y
                )
{    
    if(CHECK(x-1,y) )
    {
        visit[x-1][y][0] = visit[x][y][0] +1;
        visit[x-1][y][1] = x;
        visit[x-1][y][2] = y;
        que.push({x-1,y});
    }
}
void Check_Right(vector<vector<int>> graph, 
                vector<vector<vector<int>>> &visit,
                queue<vector<int>> &que,
                int x, 
                int y
                )
{    
    if(CHECK(x, y+1) )
    {
        visit[x][y+1][0] = visit[x][y][0] +1;
        visit[x][y+1][1] = x;
        visit[x][y+1][2] = y;
        que.push({x,y+1});
    }
}
void Check_Left(vector<vector<int>> graph, 
                vector<vector<vector<int>>> &visit,
                queue<vector<int>> &que,
                int x, 
                int y
                )
{    
    if(CHECK(x,y-1) )
    {
        visit[x][y-1][0] = visit[x][y][0] +1;
        visit[x][y-1][1] = x;
        visit[x][y-1][2] = y;
        que.push({x,y-1});
    }
}
void Check_Bot(vector<vector<int>> graph, 
                vector<vector<vector<int>>> &visit,
                queue<vector<int>> &que,
                int x, 
                int y
                )
{    
    if(CHECK(x+1,y))
    {
        visit[x+1][y][0] = visit[x][y][0] +1;
        visit[x+1][y][1] = x;
        visit[x+1][y][2] = y;
        que.push({x+1,y});
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n,vector<int>(m,0));
    for(int i =0; i< n ; i++)
    {
        string temp;
        cin >>temp;
        for(int j = 0; j< m ; j++)
        {
            graph[i][j] = temp[j]-'0';
        }
    }


    queue<vector<int>> que;
    vector<vector<vector<int>>> visit(n,vector<vector<int>>(m,vector<int>(3,-1)));
    que.push({0,0});
    visit[0][0][0] = 1;

    while(!que.empty())
    {
        vector<int> front = que.front();
        que.pop();
        
        if(front[0] == n-1 && front[1] == m-1)
        {
            break;
        }
        else if(front[0] == 0 && front[1] == 0)
        {
            Check_Right(graph,visit,que,front[0],front[1]);
            Check_Bot(graph,visit,que,front[0],front[1]);
        }
        else if( front[0] == n-1)
        {
            Check_Top(graph,visit,que,front[0],front[1]);
            Check_Right(graph,visit,que,front[0],front[1]);
        }
        else if( front[1] == m-1)
        {            
            Check_Left(graph,visit,que,front[0],front[1]);
            Check_Bot(graph,visit,que,front[0],front[1]);
        }
        else if( front[0] == 0)
        {
            Check_Left(graph,visit,que,front[0],front[1]);
            Check_Right(graph,visit,que,front[0],front[1]);
            Check_Bot(graph,visit,que,front[0],front[1]);
        }
        else if( front[1] == 0)
        {
            Check_Top(graph,visit,que,front[0],front[1]);
            Check_Right(graph,visit,que,front[0],front[1]);
            Check_Bot(graph,visit,que,front[0],front[1]);
        }
        else
        {
            Check_Top(graph,visit,que,front[0],front[1]);
            Check_Left(graph,visit,que,front[0],front[1]);
            Check_Right(graph,visit,que,front[0],front[1]);
            Check_Bot(graph,visit,que,front[0],front[1]);
        }
    }
    
    cout<<visit[n-1][m-1][0]<<endl;

}
