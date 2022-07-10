#include <iostream>
#include <vector>


#define MAX_SIZE    15

using namespace std;

int main()
{
    
    freopen("input_18.txt", "r", stdin);

    vector<vector<int>> tri(MAX_SIZE);

    for(int i = 0 ; i<MAX_SIZE; i++)
    {
        for(int  j = 0 ; j<=i; j++)
        {
            int n; 
            cin>>n;
            tri[i].push_back(n);
        }
    }
    
    for(int i = 0 ; i<MAX_SIZE; i++)
    {
        for(int  j = 0 ; j<=i; j++)
        {
            if( i==0 && j == 0)
                tri[i][j] = tri[i][j];
            else if( i == j)
                tri[i][j] += tri[i-1][j-1];
            else if( j == 0)
                tri[i][j] += tri[i-1][j];
            else
            {
                int a = tri[i-1][j];
                int b = tri[i-1][j-1];

                if( a > b)
                    tri[i][j] += a;
                else
                    tri[i][j] += b;
            }
        }
    }

    int max = 0;
    for(int i = 0; i<MAX_SIZE; i++)
    {
        if( max < tri[MAX_SIZE-1][i])
            max = tri[MAX_SIZE-1][i];
    }
    cout<<max<<endl;

    return 0;
}
