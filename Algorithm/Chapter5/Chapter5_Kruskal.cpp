#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findRoot(vector<int> &parent , int x)
{
    while(x != parent[x])
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unionSet(vector<int> &parent , vector<int> &size, int a, int b)
{
    int x = findRoot(parent, a);
    int y = findRoot(parent, b);

    if( size[x] > size[y])
    {
        parent[y] = x;
        size[x] += size[y];
    }
    else
    {
        parent[x] = y;
        size[y] += size[x];
    }
}




void kruskal(vector<vector<int>> mat)
{    
    vector<int> parent(mat.size(),0);
    vector<int> size(mat.size(),0);
    
    vector<vector<int>> weight_edge(mat.size(), vector<int>(3,0) );
    // {{w, start, end}}

    for(int i = 0; i<mat.size(); i++)
    {
        for(int j = 0 ; j< i; j++)
        {
            if(mat[i][j] != -1)
                weight_edge.push_back({mat[i][j],i,j});
        }
        parent[i] = i;
        size[i] = 1;
    }

    sort(weight_edge.begin(), weight_edge.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0];});

    vector<vector<int>> Aset;
    Aset.clear();
    int sum = 0;

    for(vector<int> e : weight_edge)
    {
        int x = findRoot(parent, e[1]);
        int y =  findRoot(parent, e[2]);
        if( x != y)
        {        
            cout<< (char)('a'+e[1]) <<"\t"<<(char)('a'+e[2])<<"\t"<< e[0]<<endl;
            sum+= e[0];
            unionSet(parent, size, e[1], e[2]);
            Aset.push_back(e);
        }
        if(Aset.size() == mat.size()-1)
            break;
    }

}


int main()
{
    vector<vector<int>> arr = {
        //  a       b       c       d       e       f       g       h       i  
        {   -1,     4,    -1,      -1,      -1,    -1,     -1,      8,     -1   },  //a
        {   4,     -1,     8,      -1,      -1,    -1,     -1,     11,     -1   },  //b
        {   -1,     8,    -1,       7,      -1,     4,     -1,     -1,      2   },  //c
        {   -1,    -1,     7,      -1,       9,    14,     -1,     -1,     -1   },  //d
        {   -1,    -1,    -1,       9,      -1,    10,     -1,     -1,      1   },  //e
        {   -1,    -1,     4,      14,      10,    -1,      2,     -1,     -1   },  //f
        {   -1,    -1,    -1,      -1,      -1,     2,     -1,      1,      6   },  //g
        {   8,     11,    -1,      -1,      -1,    -1,      1,     -1,      7   },  //h
        {   -1,    -1,     2,      -1,      -1,    -1,      6,      7,     -1    }  //i
    };

    kruskal(arr);

}
