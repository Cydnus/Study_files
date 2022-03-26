#include <iostream>
#include <string>
#include <queue>

using namespace std;

vector<vector<int>> Make_Adj_List(int node, vector<vector<int>> condition )
{    
    vector<vector<int>> mat(node+1);

    for(vector<int> con : condition)
    {
        mat[con[0]].push_back(con[1]);
        mat[con[1]].push_back(con[0]);
    }
    return mat;
}

void BFS(vector<vector<int>> mat, int start)
{
    queue<int> que;
    int n = mat.size();
    vector<bool> visit(n, false);

    que.push(start);
    visit[start] = true;

    while(!que.empty())
    {
        int t = que.front();
        que.pop();

        cout<<t<<"\t";

        for(int i : mat[t])
        {
            if( visit[i] == false)
            {          
                visit[i] =true;
                que.push(i);
            }
        }
    }

    cout<<endl;
}

vector<vector<int>> BFS_Info(vector<vector<int>> mat, int start)
{
    queue<int> que;
    int n = mat.size();
    vector<vector<int>> visit(n, vector<int>(2,-1));

    que.push(start);

    visit[start][0] = 0;
    visit[start][1] = -1;

    while(!que.empty())
    {
        int t = que.front();
        que.pop();

        for(int i : mat[t])
        {
            if( visit[i][0] == -1)
            {          
                visit[i][0] = visit[t][0] +1;
                visit[i][1] = t;
                que.push(i);
            }
        }
    }

    return visit;
}


void Print_Path(vector<vector<int>> info, int start, int target)
{
    if(start == target)
        cout<< start<<"\t";
    else if( info[target][1] == -1)
    {
        cout<< "No Path " << start<<" to " <<target<<endl;
    }
    else
    {
        Print_Path(info, start, info[target][1]);
        cout<<target<<"\t";
    }
}



int main()
{
    vector<vector<int>> mat = Make_Adj_List(8,
    {
        {1,2}, {1,3}, {2,4}, {2,5},
        {4,5}, {3,5}, {3,7}, {3,8},
        {7,8}, {6,5}
    });

    BFS(mat, 1);
    vector<vector<int>> tmp = BFS_Info(mat, 1);

    Print_Path(tmp,1,6 );
    cout<<endl;
    
}