#include <iostream>

#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>


using namespace std;


void DFS(map<int, vector<int>> graph, int start, int cnt)
{   
    vector<bool> visit(cnt+1, false);

    stack<int> st;

    st.push(start);

    while( !st.empty())
    {
        int top = st.top();
        st.pop();
        if(visit[top] == false)
            cout<<top<<" ";
        visit[top] = true;

        for(int n : graph[top])
        {
            if(visit[n] == false)
            {
                st.push(n);
            }
        }
    }
    cout<<endl;

}

void BFS(map<int, vector<int>> graph, int start, int cnt)
{  
    vector<bool> visit(cnt+1, false);

    queue<int> que;

    que.push(start);
    visit[start] = true;

    while( !que.empty())
    {
        int front = que.front();
        que.pop();
        cout<<front<<" ";

        for(int n : graph[front])
        {
            if(visit[n] == false)
            {
                visit[n] = true;
                que.push(n);
            }
        }
    }
    cout<<endl;
    
}

int main()
{
    int node_cnt, line_cnt, start;
    cin>>node_cnt>>line_cnt>>start;

    map<int, vector<int>> graph;

    for(int i = 0; i<line_cnt; i++)
    {
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i<=node_cnt; i++)    
        sort(graph[i].begin(),graph[i].end(),[](int a, int b){return a>b;});


    DFS(graph,start, node_cnt);

    for(int i = 1; i<=node_cnt; i++)    
        sort(graph[i].begin(),graph[i].end());

    BFS(graph,start, node_cnt);


}
