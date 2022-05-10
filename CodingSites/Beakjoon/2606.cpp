#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main()
{
    int count;
    cin>>count;

    int row;
    cin>>row;

    vector<vector<int>> matrix(count,vector<int>(count,0));
    map<int,bool> isVisit;
    for(int i = 0; i<count; i++)
    {
        isVisit[i] = false;
    }

    for(int i = 0; i< row; i++)
    {
        int start, end;
        cin>>start>>end;
        start --;
        end --;
        matrix[start][end] = 1;
        matrix[end][start] = 1;
    }

    queue<int> que;

    que.push(0);
    isVisit[0] = true;

    int cnt = 0;

    while(!que.empty())
    {
        int front = que.front();
        que.pop();
        if(isVisit[front] == false)
            cnt ++;
        isVisit[front] = true;
        for(int i = 0; i<count; i++)
        {
            if(matrix[front][i] == 1 && isVisit[i]==false)
                que.push(i);
        }
    }
    cout<<cnt<<endl;
}