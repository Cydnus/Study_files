#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE    100000

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;
    

    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int nodes, lines, start_node, end_node;
        cin>>nodes>>lines>>start_node>>end_node;

        start_node --;
        end_node --;

        vector<vector<pair<int,int64_t>>> graph(nodes);
        vector<int64_t> dist(nodes,20000000000000000);

        for(int i = 0 ; i<lines; i++)
        {
            int s, e;
            int w;
            cin>>s>>e>>w;
            s--;
            e--;
            graph[s].push_back(make_pair(e, w));
            graph[e].push_back(make_pair(s, w));
        }

        dist[start_node] = 0;
        vector<bool> check(nodes,false);
        queue<int> que;
        
        que.push(start_node);
        check[start_node] = true;

        while(!que.empty())
        {
            int top = que.front();
            que.pop();
            check[top] = false;

            for(int i = 0; i<graph[top].size(); i++)
            {
                int ind = graph[top][i].first;
                int64_t weight = graph[top][i].second;
                if( dist[ind] > dist[top] + weight)
                {
                    dist[ind] = dist[top] + weight;
                    if(check[ind] == false)
                    {
                        que.push(ind);
                        check[ind] = true;
                    }

                }
            }

        }


        cout<<"#"<<testCase<<" "<<dist[end_node]<<"\n";
    }

    return 0;
}
