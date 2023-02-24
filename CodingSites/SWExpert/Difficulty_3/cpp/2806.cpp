#include <iostream>
#include <vector>
using namespace std;


bool promissing(vector<int> cols, int level)
{
    for(int i = 1 ; i < level; i++)
    {
        if( cols[i] == cols[level] )
            return false;
        if( (level - i) == abs(cols[level] - cols[i]))
            return false;
    }
    return true;
}


int checkQueen(vector<int> cols, int level=0)
{
    int cnt = 0;

    if( !promissing(cols, level))
        return 0;

    if(level == cols.size()-1)
        return 1;

    for(int i = 1; i< cols.size(); i++)
    {
        cols[level+1] = i;
        int check = checkQueen(cols, level+1);
        if(check != 0)
            cnt+= check;
    }

    return cnt;
}


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;
        vector<int> cols(n+1,-1);
        int cnt = checkQueen(cols);

        cout<<"#"<<testCase<<" "<<cnt<<endl;
    }
    return 0;
}
