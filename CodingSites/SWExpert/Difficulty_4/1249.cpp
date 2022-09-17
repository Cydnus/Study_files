#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE    100

using namespace std;

class point
{
public:
    int x;
    int y;
};

int graph[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];


void init()
{
    for(int i = 0 ; i< MAX_SIZE; i++)
    {
        for(int j = 0 ; j< MAX_SIZE; j++)
        {
            graph[i][j] = -1;
            dist[i][j] = -1;
        }
    }
}

point getPoint(int x, int y)
{
    point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int bfs(int n)
{

    queue<point> que;
    que.push(getPoint(0,0));
    dist[0][0] = 0;
    while(!que.empty())
    {
        point front = que.front();
        que.pop();
        //cout<<front.x<<"\t"<<front.y << "\t : "<<dist[front.x][front.y]<<endl;
        if( front.x == 0 && front.y == 0)
        {
            if(front.y+1 < n && 
            (dist[front.x][front.y+1] == -1 ||
            dist[front.x][front.y+1] > dist[front.x][front.y] + graph[front.x][front.y+1]))
            {
                dist[front.x][front.y+1] = 
                dist[front.x][front.y] + graph[front.x][front.y+1];
                que.push(getPoint(front.x,front.y+1));
            }
            if(front.x+1 < n && 
            (dist[front.x+1][front.y] == -1 ||
            dist[front.x+1][front.y] > dist[front.x][front.y]+graph[front.x+1][front.y]))
            {
                dist[front.x+1][front.y] = dist[front.x][front.y]+graph[front.x+1][front.y];
                que.push(getPoint(front.x+1,front.y));
            }
        }
        else if( front.x == 0)
        {
            if(front.y+1 < n && 
            (dist[front.x][front.y+1] == -1 ||
            dist[front.x][front.y+1] > dist[front.x][front.y] + graph[front.x][front.y+1]))
            {
                dist[front.x][front.y+1] = 
                dist[front.x][front.y] + graph[front.x][front.y+1];
                que.push(getPoint(front.x,front.y+1));
            }
            if(front.x+1 < n &&
            (dist[front.x+1][front.y] == -1 ||
            dist[front.x+1][front.y] > dist[front.x][front.y]+graph[front.x+1][front.y]))
            {
                dist[front.x+1][front.y] = dist[front.x][front.y]+graph[front.x+1][front.y];
                que.push(getPoint(front.x+1,front.y));
            }
            if(dist[front.x][front.y-1] == -1 ||
            dist[front.x][front.y-1] > dist[front.x][front.y] + graph[front.x][front.y-1])
            {
                dist[front.x][front.y-1] = 
                dist[front.x][front.y] + graph[front.x][front.y-1];
                que.push(getPoint(front.x,front.y-1));
            }
        }
        else if( front.y == 0)
        {
            if(front.y+1 < n && 
            (dist[front.x][front.y+1] == -1 ||
            dist[front.x][front.y+1] > dist[front.x][front.y] + graph[front.x][front.y+1]))
            {
                dist[front.x][front.y+1] = 
                dist[front.x][front.y] + graph[front.x][front.y+1];
                que.push(getPoint(front.x,front.y+1));
            }
            if(front.x+1 < n && 
            (dist[front.x+1][front.y] == -1 ||
            dist[front.x+1][front.y] > dist[front.x][front.y]+graph[front.x+1][front.y]))
            {
                dist[front.x+1][front.y] = dist[front.x][front.y]+graph[front.x+1][front.y];
                que.push(getPoint(front.x+1,front.y));
            }
            if(dist[front.x-1][front.y] == -1 ||
            dist[front.x-1][front.y] > dist[front.x][front.y]+graph[front.x-1][front.y])
            {
                dist[front.x-1][front.y] = dist[front.x][front.y]+graph[front.x-1][front.y];
                que.push(getPoint(front.x-1,front.y));
            }

        }       
        else
        {
            if(front.y+1 < n && 
            (dist[front.x][front.y+1] == -1 ||
            dist[front.x][front.y+1] > dist[front.x][front.y] + graph[front.x][front.y+1]))
            {
                dist[front.x][front.y+1] = 
                dist[front.x][front.y] + graph[front.x][front.y+1];
                que.push(getPoint(front.x,front.y+1));
            }
            if(front.x+1 < n && 
            (dist[front.x+1][front.y] == -1 ||
            dist[front.x+1][front.y] > dist[front.x][front.y]+graph[front.x+1][front.y]))
            {
                dist[front.x+1][front.y] = dist[front.x][front.y]+graph[front.x+1][front.y];
                que.push(getPoint(front.x+1,front.y));
            }
            if(dist[front.x][front.y-1] == -1 ||
            dist[front.x][front.y-1] > dist[front.x][front.y] + graph[front.x][front.y-1])
            {
                dist[front.x][front.y-1] = 
                dist[front.x][front.y] + graph[front.x][front.y-1];
                que.push(getPoint(front.x,front.y-1));
            }
            if(dist[front.x-1][front.y] == -1 ||
            dist[front.x-1][front.y] > dist[front.x][front.y]+graph[front.x-1][front.y])
            {
                dist[front.x-1][front.y] = dist[front.x][front.y]+graph[front.x-1][front.y];
                que.push(getPoint(front.x-1,front.y));
            }
        }
    }

    return dist[n-1][n-1];
}


int main()
{

    freopen("not_input_1249.txt","r",stdin);
    int T;
    scanf("%d", &T);


    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        scanf("%d", &n);

        init();

        for(int i = 0; i < n; i++)
            for(int j =0; j < n; j++)
                scanf("%1d",&graph[i][j]);

        printf("#%d %d\n", testCase, bfs(n));

    }
    return 0;
}
