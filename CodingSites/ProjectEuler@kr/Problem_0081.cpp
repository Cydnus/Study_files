#include <iostream>
#include <vector>

#define MAX_SIZE    80

using namespace std;

int main()
{
    freopen("input_81.txt", "r", stdin);

    vector<vector<int>> matrix(MAX_SIZE,vector<int>(MAX_SIZE,0));


    for(int i = 0; i<MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++)
            cin>>matrix[i][j];

    for(int i = 0; i<MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if( i == 0 && j == 0)
                matrix[i][j] = matrix[i][j];
            else if( i == 0)
                matrix[i][j] += matrix[i][j-1];
            else if( j == 0 )
                matrix[i][j] += matrix[i-1][j];
            else
            {
                int a = matrix[i-1][j];
                int b = matrix[i][j-1];

                if( a > b)
                    matrix[i][j] += b;
                else
                    matrix[i][j] += a;
            }
        }
    }
    cout<<matrix[MAX_SIZE-1][MAX_SIZE-1]<<endl;

    
    return 0;
}
