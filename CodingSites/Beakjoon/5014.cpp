#include <iostream>
#include <vector>
#include <string>

#include <queue>


using namespace std;

int main()
{
    int maxStair, startFloor, goalFloor, up,down;

    cin>>maxStair>>startFloor>>goalFloor>>up>>down;
    
    queue<int> que;

    que.push(startFloor);

    vector<int> visit(maxStair+1,-1);

    visit[startFloor] = 0;

    while(!que.empty())
    {
        int floor = que.front();
        que.pop();

        if(floor == goalFloor)
            break;
        if( floor + up <= maxStair && visit[floor+up] == -1)
        {
            visit[floor+up] = visit[floor]+1;
            que.push(floor+up);
        }        
        if( floor - down >= 1 && visit[floor-down] == -1)
        {
            visit[floor-down] = visit[floor]+1;
            que.push(floor-down);
        }
    }

    if(visit[goalFloor] == -1)
        cout<< "use the stairs";
    else
        cout<<visit[goalFloor];

}
