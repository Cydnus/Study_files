#include <iostream>
#include <vector>

#include <queue>

using namespace std;


int main()
{
    int count, src, target,num;
    cin>>count;
    cin>>src>>target;
    cin>>num;

    vector<vector<int>> graph(count+1,vector<int>(count+1,0));

    for(int i = 0; i<num; i++)
    {
        int c,p;
        cin>>p>>c;

        graph[p][c] = 1;
        graph[c][p] = 1;
    }
    vector<vector<int>> visit(count+1,vector<int>(2,-1));

    queue<int> que;
    que.push(src);

    while(!que.empty())
    {
        int front = que.front();
        que.pop();
        
        for(int i =1; i<count+2; i++)
        {
            if(graph[front][i] == 1 &&  visit[i][0] == -1)
            {
                visit[i][0] = visit[front][0] +1;
                visit[i][1] = front;
                que.push(i);
            }
        }
    }
    if(visit[target][0] == -1)
        cout<<visit[target][0]<<endl;
    else
        cout<<visit[target][0]+1<<endl;
    

}
