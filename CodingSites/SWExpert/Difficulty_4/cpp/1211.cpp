#include <iostream>
#include <vector>
#include <string>

#define     MAX_MAP_SIZE    100

using namespace std;

int findPath(vector<vector<int>> ladder, int ind)
{
    int dep = 0;
    int cnt = 0;
    while(dep != MAX_MAP_SIZE -1)
    {
        cnt ++;
        ladder[dep][ind] = 2;

        if(ind < 1)
        {
            if(ladder[dep][ind+1] == 1)
                ind +=1;
            else if(ladder[dep+1][ind] == 1)
                dep +=1 ;
        }
        else
        {
            if(ladder[dep][ind-1] == 1)
                ind -= 1;
            else if( ladder[dep][ind+1] == 1)
                ind += 1;
            else if( ladder[dep+1][ind] == 1)
                dep++;
        }
    }
    return cnt;
}


int main()
{
    freopen("not_input_1211.txt", "r", stdin);
    int T=10;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        //Write Your Code
        int n;
        cin>>n;

        vector<vector<int>> ladder(100,vector<int>(100,0));

        for(int i = 0 ; i<MAX_MAP_SIZE; i++)
            for(int j = 0 ; j<MAX_MAP_SIZE; j++)
                cin>>ladder[i][j];
        int min = 100000;
        int min_ind = 0;
        for(int i = 0; i<MAX_MAP_SIZE; i++)
        {
            if(ladder[0][i] == 1)
            {
                int cnt = findPath(ladder, i);
                if( cnt < min )
                {
                    min = cnt;
                    min_ind = i;
                }
            }
        }


        cout<<"#"<<testCase<<" "<<min_ind<<endl;
    }
    return 0;
}
