#include <iostream>
#include <vector>
#include <queue>

#define     TREE_HEIGHT   141

using namespace std;

int tri[TREE_HEIGHT][TREE_HEIGHT] ;
int tri_end[TREE_HEIGHT];

int getHeight(int x)
{
    int i = 0;
    while(i <TREE_HEIGHT)
    {
        if(tri_end[i] >= x)
            return i;
        i++;
    }
    return -1;
}


int getIndex(int hight, int x, int start, int end)
{
    if( start > end)
        return -1;
    int mid = start + end;
    if(tri[hight][mid] == x)
        return mid;
    if(tri[hight][mid] > x)
        return getIndex(hight, x,start,mid-1);
    return getIndex(hight, x,mid+1,end);
}


int bfs(int s, int e)
{
    queue<pair<int,int>> que;
    int h = getHeight(s);
    int ind ;
    if( h != 0)
        ind = getIndex(h,s,0, h);
    else
        ind = 0;

    que.push(make_pair(h,ind));
    vector<vector<int>> dist(TREE_HEIGHT);

    for(int i = 0 ; i<TREE_HEIGHT; i++)
    {
        dist[i] = vector<int>(i+1,100000);
    }
    dist[h][ind] = 0;

    while(!que.empty())
    {
        int i = que.front().first;
        int j = que.front().second;
        que.pop();
        //cout<<tri[i][j] << "\t" << dist[i][j] <<"\t"<< i<<"\t"<<j<<endl;

        if(tri[i][j] == e)
            return dist[i][j];

        if( tri[i][j] == 0)
            cout<<"find"<<endl;

        if( tri[i][j] > e)
        {
            if( (i == 0 && j == 0) || i == 0)
                continue;
            else if( j == 0)
            {
                if(i-1 >= 0  && i-1 >= j && dist[i-1][j] > dist[i][j] +1)
                {
                    dist[i-1][j] = dist[i][j] +1;
                    que.push(make_pair(i-1,j));                
                }
            }
            else
            {
                if( j-1 >= 0 && i >= j-1 && dist[i][j-1] > dist[i][j] +1)
                {
                    dist[i][j-1] = dist[i][j] +1;
                    que.push(make_pair(i,j-1));
                }

                if(i-1 >= 0 && i-1 >= j && dist[i-1][j] > dist[i][j] +1)
                {
                    dist[i-1][j] = dist[i][j] +1;
                    que.push(make_pair(i-1,j));
                }

                if(i-1 >= 0 && j-1 >= 0 && dist[i-1][j-1] > dist[i][j] +1)
                {
                    dist[i-1][j-1] = dist[i][j] +1;
                    que.push(make_pair(i-1,j-1));
                }
            }
        }
        else
        {
            if( i == 0 && j == 0)
            {
                if(i+1<TREE_HEIGHT &&dist[i+1][j] > dist[i][j] +1)
                {
                    dist[i+1][j] = dist[i][j] +1;
                    que.push(make_pair(i+1,j));
                }
                if(i+1<TREE_HEIGHT && i >= j &&dist[i+1][j+1] > dist[i][j] +1)
                {
                    dist[i+1][j+1] = dist[i][j] +1;
                    que.push(make_pair(i+1,j+1));
                }
            }
            else if( i == 0)
            {
                if(i+1<TREE_HEIGHT && dist[i+1][j] > dist[i][j] +1)
                {
                    dist[i+1][j] = dist[i][j] +1;
                    que.push(make_pair(i+1,j));   
                }
                if(i+1<TREE_HEIGHT  && i >= j  &&  dist[i+1][j+1] > dist[i][j] +1)
                {
                    dist[i+1][j+1] = dist[i][j] +1;
                    que.push(make_pair(i+1,j+1));  
                }
            }
            else
            {
                if(i >= j+1 && dist[i][j+1] > dist[i][j] +1)
                {
                    dist[i][j+1] = dist[i][j] +1;
                    que.push(make_pair(i,j+1));
                }
                if(i+1<TREE_HEIGHT &&dist[i+1][j] > dist[i][j] +1)
                {
                    dist[i+1][j] = dist[i][j] +1;
                    que.push(make_pair(i+1,j));
                }
                if(i+1<TREE_HEIGHT  && i >= j && dist[i+1][j+1] > dist[i][j] +1)
                {
                    dist[i+1][j+1] = dist[i][j] +1;
                    que.push(make_pair(i+1,j+1));
                }
            }

        }

    }
    
    h = getHeight(e);
    ind ;
    if( h != 0)
        ind = getIndex(h,e,0, h);
    else
        ind = 0;

    return dist[h][ind];
    
}

int main()
{
    int ind = 1;

    for(int i = 0; i<TREE_HEIGHT; i++)
    {
        for(int j = 0; j<=i; j++)
            tri[i][j] = ind ++;
        tri_end[i] = ind-1;
    }
        
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int a, b;
        cin>>a>>b;
        cout<<"#"<<testCase<<" "<<bfs(a,b)<<endl;
    }
    return 0;
}
