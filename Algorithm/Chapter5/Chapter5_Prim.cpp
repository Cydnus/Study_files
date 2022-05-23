#include <iostream>
#include <vector>
#include <algorithm>

#include <queue>

using namespace std;


void prim(vector<vector<int>> mat, int start)
{  
    int size = mat.size();
    
    vector<int> key(size, -1);
    vector<int> pi(size, -1);

    for(int i =0 ; i<size; i++)
    {
        key[i] = mat[start][i];
    }

    vector<int> va(size, -1);
    int cnt = 1;
    va[start] = 0;
    key[start] = 100;
    cout<<(char)('a'+start)<< "\t";

    while(cnt < size)
    {
        int min = start;
        for(int i =0;i < size; i++)
        {
            if( va[i] == -1 && key[min] >= key[i])
                min = i;
        }

        va[min] = cnt++;
        cout<<(char)('a'+min)<< "\t";

        for( int i = 0 ; i< size; i++)
        {
            if(va[i] == -1 && key[i] > mat[min][i])
            { 
                key[i] = mat[min][i];
                pi[i] = min;
            }
        }
    }
    cout <<endl;
}


int main()
{
    vector<vector<int>> arr = {
        //  a       b       c       d       e       f       g       h       i  
        {   100,     4,    100,      100,      100,    100,     100,      8,     100   },  //a
        {   4,     100,     8,      100,      100,    100,     100,     11,     100   },  //b
        {   100,     8,    100,       7,      100,     4,     100,     100,      2   },  //c
        {   100,    100,     7,      100,       9,    14,     100,     100,     100   },  //d
        {   100,    100,    100,       9,      100,    10,     100,     100,      1   },  //e
        {   100,    100,     4,      14,      10,    100,      2,     100,     100   },  //f
        {   100,    100,    100,      100,      100,     2,     100,      1,      6   },  //g
        {   8,     11,    100,      100,      100,    100,      1,     100,      7   },  //h
        {   100,    100,     2,      100,      100,    100,      6,      7,     100    }  //i
    };
    prim(arr,0);

}
