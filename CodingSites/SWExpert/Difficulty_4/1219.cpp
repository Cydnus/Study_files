#include <iostream>
#include <vector>

#define MAX_LENGTH  100
#define END_NODE    99

using namespace std;


bool dfs(vector<vector<int>> graph, vector<bool> check, int node)
{
    if(node == 99)
        return true;
    
    check[node] = true;
    bool ret = false;
    for(int i =0;  i< graph[node].size() && ret==false; i++)
    {
        if(check[graph[node][i]] == false)
            ret |= dfs(graph, check, graph[node][i]);
    }
    return ret;    
}


int main()
{
    
    freopen("not_input_1219.txt", "r", stdin);

    int testNo;
    while(cin >> testNo)
    {
        int length;
        cin>>length;
        vector<vector<int>> graph(MAX_LENGTH);

        for(int i = 0 ; i<length; i++)
        {
            int p, q;
            cin>> p >>q;
            graph[p].push_back(q);
        }
        vector<bool> check(MAX_LENGTH, false);
        cout<<"#"<<testNo<<" ";
        if(dfs(graph,check,0))
            cout<<1<<endl;
        else
            cout<<0<<endl;

    }
    
    return 0;
}
                                                                