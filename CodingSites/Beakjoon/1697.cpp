#include <iostream>
#include <vector>
#include <string>

#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin>> n>>k;

    vector<vector<int>> visit(200002, vector<int>(2,-1));

    queue<int> que;
    que.push(n);
    visit[n][0] = 0;

    while(!que.empty())
    {
        int front = que.front();
        que.pop();

        if(front == k)
            break;
        else
        {
            if(front-1 >= 0 && visit[front-1][0] == -1 )
            {
                visit[front-1][0] = visit[front][0]+1;
                visit[front-1][1] = front;
                que.push(front-1);
            }
            if(front +1 < 200002 && visit[front +1][0] == -1 )
            {
                visit[front+1][0] = visit[front][0]+1;
                visit[front+1][1] = front;
                que.push(front+1);
            }
            if(front*2 < 200002 && visit[front *2][0] == -1 )
            {
                visit[front*2][0] = visit[front][0]+1;
                visit[front*2][1] = front;
                que.push(front*2);
            }
        }

    }
    cout<<visit[k][0];

}
