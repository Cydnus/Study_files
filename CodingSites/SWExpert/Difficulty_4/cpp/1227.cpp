#include <iostream>
#include <string>

#define     MAP_SIZE    100

using namespace std;

int findPoint(string s, char target, int start=0, int end=MAP_SIZE-1)
{
    if(start > end)
        return -1;
    int mid = (start + end)/2;
    if(s[mid]==target)
        return mid;
    int ret = findPoint(s,target,start,mid-1);
    if( ret == -1)
        ret = findPoint(s,target,mid+1,end);
    return ret;
}

bool dfs(string graph[], int si, int sj)    
{

    if(si <0 || si >= MAP_SIZE || sj < 0 || sj >= MAP_SIZE)
        return false;

    if(graph[si][sj] == '1')
        return false;
    if(graph[si][sj] == '3')
        return true;
        
    graph[si][sj] = '4';
    bool temp = false;
    if( graph[si][sj+1] == '0' || graph[si][sj+1] == '3' )
        temp |= dfs(graph,si,sj+1);
    if(graph[si+1][sj] == '0' || graph[si+1][sj] == '3' )
        temp |= dfs(graph,si+1,sj);
    if(graph[si][sj-1] == '0' || graph[si][sj-1] == '3' )
        temp |= dfs(graph,si,sj-1);
    if(graph[si-1][sj] == '0' || graph[si-1][sj] == '3' )
        temp |= dfs(graph,si-1,sj); 

    return temp;
}



int main()
{
    freopen("not_input_1227.txt","r",stdin);
    int T = 10;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;

        string graph[MAP_SIZE];
        int sp[2]={-1,-1}, ep[2]={-1,-1};
        for(int i = 0; i< MAP_SIZE; i++)
        {
            cin>>graph[i];
            if( sp[0] == -1)
            {
                int temp = findPoint(graph[i],'2');
                if(temp != -1)
                {
                    sp[0] = i;
                    sp[1] = temp;
                }
            }
            if( ep[0] == -1)
            {
                int temp = findPoint(graph[i],'3');
                if(temp != -1)
                {
                    ep[0] = i;
                    ep[1] = temp;
                }
            }
        }

        cout<<"#"<<testCase<<" ";
        if(dfs(graph,sp[0],sp[1]))
            cout<<1<<endl;
        else
            cout<<0<<endl;


    }

    return 0;
}
