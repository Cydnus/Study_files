#include <iostream>
#include <vector>
#include <string>

#define INFIN   0xffffffff

using namespace std;

void Dijkstra(vector<vector<uint32_t>> mat, int start)
{
    int size = mat.size();
    vector<int> s(size, 0);
    vector<uint32_t> d(size, INFIN);
    vector<int> p(size, -1);

    d[start] = 0;
    int cnt = 1;
    while(cnt < size+1 )
    {
        int min = INFIN;
        int min_ind = -1;
        
        for(int i = 0; i<size; i++)
        {
            if( s[i] == 0 && min > d[i])
            {
                min = d[i];
                min_ind = i;
            }
        }
        cout<<min_ind<<"\t";
        s[min_ind] = cnt++;

        for(int i = 0; i<size; i++)
        {
            if( s[i] == 0 && mat[min_ind][i] != INFIN && d[i] > d[min_ind]+mat[min_ind][i])
            {
                d[i] =  d[min_ind] + mat[min_ind][i];
                p[i] = min_ind;
            }
        }

    }

    cout<<endl;
    cout<<endl;
    
    for(int i = 0; i<size; i++)
        cout<<i<<"\t";
    cout<<endl;
    for(int i = 0; i<size; i++)
        cout<<d[i]<<"\t";
    cout<<endl;
}


int main()
{
    vector<vector<uint32_t>> arr = 
    {
        {   INFIN,      10,       5,   INFIN,   INFIN  },
        {   INFIN,   INFIN,       2,       1,   INFIN  },
        {   INFIN,       3,   INFIN,       9,       2  },
        {   INFIN,   INFIN,   INFIN,   INFIN,       4  },
        {       7,   INFIN,   INFIN,   INFIN,       6  }
    };

    Dijkstra(arr, 0);
}
