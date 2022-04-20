#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

class Graph
{
    map<int, vector<int>> mat;
    int size;

    
    void Print_Path(map<int,int> upper, int start, int target)
    {        
        if(start == target)
            cout<< start<<"\t";
        else if( upper[target] == -1)
        {
            cout<< "No Path " << start<<" to " <<target<<endl;
        }
        else
        {
            Print_Path(upper, start, upper[target]);
            cout<<target<<"\t";
        }
    }

public: 
    Graph(int node, vector<vector<int>> condition)
    {
        size = node+1;
        for(int i = 1; i<= node; i++)
        {
            mat[i].clear();
        }

        for(vector<int> con : condition)
        {
            mat[con[0]].push_back(con[1]);
            mat[con[1]].push_back(con[0]);
        }
    }

    void BFS(int start)
    {
        queue<int> que;
        
        map<int,bool> visit;

        que.push(start);
        visit[start] = true;

        while(!que.empty())
        {
            int t = que.front();
            que.pop();

            cout<< t <<"\t";

            for(int i : mat[t])
            {
                if( visit.find(i) == visit.end() )
                {
                    visit[i] = true;
                    que.push(i);
                }
            }
        }

        cout<<endl;

    }

    
    void BFS(int start, int target)
    {
        queue<int> que;
        
        map<int,int> dist;
        map<int, int> upper;

        for(int i = 1 ; i<size; i ++ )
        {
            dist[i] = -1;
            upper[i] = -1;
        }

        que.push(start);
        
        dist[start] = 0;
        upper[start] = -1;

        while(!que.empty())
        {
            int t = que.front();
            que.pop();

            for(int i : mat[t])
            {
                if( dist[i] == -1 )
                {
                    dist[i] = dist[t]+1;
                    upper[i] = t;
                    que.push(i);
                }
            }
        }
        
        cout<< "Distance : " << dist[target] <<endl;
        Print_Path(upper, start, target);

        cout<<endl;
    }
        
};


int main()
{
    
    Graph g(8,
    {
        {1,2}, {1,3}, {2,4}, {2,5},
        {4,5}, {3,5}, {3,7}, {3,8},
        {7,8}, {6,5}
    });

    g.BFS(1);
    g.BFS(1,6);
    
}