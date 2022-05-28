#include <iostream>
#include <vector>

using namespace std;
/*
int max_score(vector<vector<int>> table, vector<bool> &select, int max_cal, int ind = 0)
{
    if(max_cal == 0 || ind == table.size())
    {
        int sum = 0;
        for(int i = 0 ; i<select.size(); i++)
            if( select[i] == true)
                sum+=table[i][0];
        return sum;
    }

    int a = 0;
    if( max_cal - table[ind][1] >= 0)
    {
        select[ind] = true;
        a = max_score(table,select,max_cal-table[ind][1], ind+1);
        select[ind] = false;
    }
    int b = max_score(table,select,max_cal, ind+1);
    if( a > b) 
        return a;   
    return b;
}

int main()
{
    int testNo;
    cin>>testNo;

    for (int testCase = 1; testCase <= testNo; testCase++)
    {
        int n, l;
        cin>>n>>l;

        vector<vector<int>> table(n,vector<int>(2,0));
        vector<bool> select(n,false);

        for(int i = 0; i<n; i++)
        {
            int score, cal;
            cin>>score>>cal;
            table[i][0] = score;
            table[i][1] = cal;
        }
        int max = max_score(table, select,l,0);
        cout<<"#"<< testCase<<" "<<max<<endl;
    }
    

}
*/
int main()
{
    int testNo;
    cin>>testNo;

    for (int testCase = 1; testCase <= testNo; testCase++)
    {
        int n, l;
        cin>>n>>l;

        vector<vector<int>> table(n,vector<int>(2,0));
        for(int i = 0; i<n; i++)
        {
            int score, cal;
            cin>>score>>cal;
            table[i][0] = score;
            table[i][1] = cal;
        }

        vector<vector<int>> dta(n+1,vector<int>(l+1,0));

        for(int i = 1 ; i<= n ; i++ )
        {   
            for(int j = 1; j <= l; j++)
            {
                if( table[i-1][1] > j )
                    dta[i][j] = dta[i-1][j]; 
                else if( dta[i-1][j] > table[i-1][0] + dta[i-1][j-table[i-1][1]] )
                    dta[i][j] = dta[i-1][j]; 
                else
                    dta[i][j] = table[i-1][0] + dta[i-1][j-table[i-1][1]];
            }
        }
        cout<<"#"<< testCase<<" "<<dta[n][l]<<endl;
    }
}