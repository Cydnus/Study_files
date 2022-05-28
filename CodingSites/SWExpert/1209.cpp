#include <iostream>
#include <vector>

#define MAX_SIZE    100

using namespace std;

int main()
{

    for(int testCase = 1; testCase<=10; testCase++)
    {
        int n;
        cin >> n ;
        vector<vector<int>> table(MAX_SIZE,vector<int>(MAX_SIZE,0));
        for(int i = 0; i<MAX_SIZE; i++)
        {
            for(int j = 0 ; j<MAX_SIZE;j++)
            {
                int inp;
                cin>>inp;
                table[i][j] =inp;
            }
        }

        int max = 0;
        int sum_s = 0, sum_rs = 0;

        for(int i = 0; i<MAX_SIZE; i++)
        {
            int sum_col=0, sum_row=0;
            for(int j = 0 ; j<MAX_SIZE; j++)
            {
                sum_col += table[i][j];
                sum_row += table[j][i];
            }
            sum_s += table[i][i];
            sum_rs += table[i][MAX_SIZE-1-i];

            if( max < sum_col)
                max = sum_col;
            if( max < sum_row )
                max = sum_row;
        }

        if( max < sum_s)
            max = sum_s;
        if( max < sum_rs )
            max = sum_rs;



        cout<<"#"<<testCase<<" "<<max<<endl;

    }
}
