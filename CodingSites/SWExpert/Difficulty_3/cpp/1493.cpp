#include <iostream>
#include <vector>
#include <string>

#define MAX_ARR 300

using namespace std;

void setMap(vector<vector<int>> &graph, int &value, int x, int y)
{
    if(y < 0)
        return;

    graph[y][x] = value;
    value++;

    setMap(graph,value,x+1,y-1);
    
}

vector<int> findPosition(vector<vector<int>> graph, int target)
{
    int temp = MAX_ARR;
    for(int i = 0 ; i< MAX_ARR && graph[i][0]<=target; i++)
    {
        for(int j = 0; j < temp; j++)
        {
            if( graph[i][j] > target)
            {
                temp = j;
                break;
            }
            else if( graph[i][j] == target)
                return {j,i};
        }
    }
    return {-1,-1};
}

int main()
{
    freopen("not_input_1493.txt", "r", stdin);
    int T;
    cin>>T;
    
    vector<vector<int>> graph(MAX_ARR,vector<int>(MAX_ARR,0));
    int num = 1;
    for(int i = 0; i<MAX_ARR; i++)
        setMap(graph,num,0,i);

    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int p,q;
        cin>>p>>q;

        vector<int> a,b;
        a = findPosition(graph,p);
        b = findPosition(graph,q);
        a[0] += b[0]+1;
        a[1] += b[1] +1;
        cout<<"#"<<testCase<<" "<< graph[a[1]][a[0]] <<endl;
    }
    return 0;
}
