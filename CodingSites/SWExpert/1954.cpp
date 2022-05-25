#include <iostream>
#include <vector>
#include <string>

using namespace std;


void SnailRight(vector<vector<int>> &graph, int &s, int &t, int &n)
{
    int size = graph.size();   
    while(s >=0 && s< size && t>=0 && t<size && graph[s][t] == 0 )
    {        
        graph[s][t] = n++; 
        if( t+1 == size || graph[s][t+1] != 0)
            break;
        t++;
    }
    s++;
}
void SnailDown(vector<vector<int>> &graph, int &s, int &t, int &n)
{
    int size = graph.size();
    while(s >=0 && s< size && t>=0 && t<size && graph[s][t] == 0 )
    {
        graph[s][t] = n++; 
        if( s+1 == size  || graph[s+1][t] != 0)
            break;
        s++;
    } 
    t--;
}

void SnailLeft(vector<vector<int>> &graph, int &s, int &t, int &n)
{
    int size = graph.size();
    while(s >=0 && s< size && t>=0 && t<size && graph[s][t] == 0 )
    {
        graph[s][t] = n++;         
        if( t-1 == -1 || graph[s][t-1] != 0)
            break;
        t--;
    }
    s--;
}

void SnailUp(vector<vector<int>> &graph, int &s, int &t, int &n)
{
    int size = graph.size();
    while(s >=0 && s< size && t>=0 && t<size && graph[s][t] == 0 )
    {
        graph[s][t] = n++; 
        if( s-1 == -1  || graph[s-1][t] != 0)
            break;
        s--;
    }
    t++;
}




void MakeSnail(int n)
{
    vector<vector<int>> graph(n,vector<int>(n,0));

    int s=0,t=0,m=1;
    while(graph[n/2][(n-1)/2] == 0)
    {
        cout<< s<<"\t"<<t<<"\t" <<m<<endl;
        SnailRight(graph, s, t, m);
        cout<< s<<"\t"<<t<<"\t" <<m<<endl;
        SnailDown(graph, s, t, m);
        cout<< s<<"\t"<<t<<"\t" <<m<<endl;
        SnailLeft(graph, s, t, m);
        cout<< s<<"\t"<<t<<"\t" <<m<<endl;
        SnailUp(graph, s, t, m);
    }

    for(int i = 0 ; i< n; i++)
    {
        for(int j = 0; j<n; j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
        
}


int main()
{
    int test_no;

    cin>>test_no;

    for(int i = 0 ; i< test_no; i++)
    {
        int n ;
        cin>> n;
        MakeSnail(n);
    }

}
