#include <iostream>
#include <vector>
#include <string>

#define INFIN    0x00ffffff

using namespace std;

vector<vector<int>> FloydWarshall(vector<vector<int>> graph)
{
    int size =graph.size();
    vector<vector<int>> p(size,vector<int>(size,-1));
    vector<vector<int>> d(size,vector<int>(size,INFIN));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            d[i][j] = graph[i][j];
        }        
    }
    

    for(int k = 0; k<size-1;k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k]+d[k][j];
                    p[i][j] = k;
                }
            }        
        }
    }

    cout<<"\t";
    for (int i = 0; i < size; i++)
    {
        cout<<i<<"\t\t";
    }
    cout<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<i<<"\t";
        for (int j = 0; j < size; j++)
        {
            cout<<d[i][j]<<"\t\t";
        }        
        cout<<endl;
    }

    return p;
}

void PrintPath(vector<vector<int>> p, int s, int t)
{
    if(p[s][t] == -1)
        return;
    PrintPath(p,s,p[s][t]);
    cout<<p[s][t]<<"\t";
    PrintPath(p,p[s][t],t);
}


int main()
{
    vector<vector<int>> arr = 
    {
        {   INFIN,      10,       5,   INFIN,   INFIN  },
        {   INFIN,   INFIN,       2,       1,   INFIN  },
        {   INFIN,       3,   INFIN,       9,       2  },
        {   INFIN,   INFIN,   INFIN,   INFIN,       4  },
        {       7,   INFIN,   INFIN,   INFIN,       6  }
    };
    
    auto par = FloydWarshall(arr);

    cout<<"0"<<"\t";
    PrintPath(par,0,3);
    cout<<"3"<<endl;
}
