#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    
    freopen("input_11.txt", "r", stdin);

    vector<vector<uint64_t>> mat(20,vector<uint64_t>(20,0));

    for(int i =0 ; i<20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cin>> mat[i][j];
        }        
    }
    uint64_t max = 0;
    for(int i =0 ; i<17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            uint64_t w = mat[i][j] * mat[i][j+1] * mat[i][j+2] * mat[i][j+3];
            uint64_t h = mat[i][j] * mat[i+1][j] * mat[i+2][j] * mat[i+1][j];
            uint64_t c1 = mat[i][j] * mat[i+1][j+1] * mat[i+2][j+2] * mat[i+3][j+3];
            uint64_t c2 = mat[i][19-j] * mat[i+1][18-j] * mat[i+2][17-j] * mat[i+3][16-j];
            if( max < w)
                max = w;
            if( max < h)
                max = h;
            if(max < c1)
                max = c1;
            if(max < c2)
                max = c2;

        }        
    }
    cout<<max<<endl;

    return 0;
}
