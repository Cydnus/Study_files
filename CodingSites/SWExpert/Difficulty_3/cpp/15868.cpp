#include <iostream>
#include <string>

using namespace std;

string check_array(string mat[], int n, int m)
{
    string rev ="";
    for(int i = 0; i< m; i++)
        rev += (mat[0][i] + 1) % 2 + '0';

    for(int i = 1; i < n; i++)
        if(mat[i] != mat[0] && mat[i] != rev)
            return "no";
    return "yes";
}

int main()
{
    int T;
    cin>>T;
    string mat[5];
    for(int testCase = 1; testCase<=T; testCase ++)
    {

        int n, m;
        cin>>n>>m;

        for(int i = 0 ; i< n; i++)
            cin>>mat[i];       

        cout<<"#"<<testCase<<" "<<check_array(mat, n, m)<<endl;
    }
    return 0;
}
