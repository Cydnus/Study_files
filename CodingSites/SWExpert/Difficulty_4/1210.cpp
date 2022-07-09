#include <iostream>
#include <vector>

#define MAX_MAP_SIZE    100

using namespace std;

int bottomUp(vector<vector<int>> ladderMap, int row, int col)
{
    if( row == 0)
        return col;

    ladderMap[row][col] = 3;
    if(col+1 < MAX_MAP_SIZE && ladderMap[row][col+1] == 1)
        return bottomUp(ladderMap, row, col+1);
    if(col-1 > -1 && ladderMap[row][col-1] == 1)
        return bottomUp(ladderMap,row,col-1);
    return bottomUp(ladderMap,row-1,col);
}

int main()
{
    
    freopen("not_input_1210.txt", "r", stdin);

    int T = 10;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int testNo;
        cin>>testNo;L

        vector<vector<int>> ladderMap(MAX_MAP_SIZE,vector<int>(MAX_MAP_SIZE,0));

        int end_x = 0;

        for(int i =0 ; i<MAX_MAP_SIZE; i++)
        {
            for(int j = 0 ; j<MAX_MAP_SIZE; j++)
            {
                cin>>ladderMap[i][j];
                if( ladderMap[i][j] == 2)
                    end_x = j;
            }
        }
        

        cout<<"#"<<testCase<<" "<<bottomUp(ladderMap,MAX_MAP_SIZE-1,end_x)<<endl;
    }
    return 0;
}
