#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n ;
        cin>>n;
        
        vector<bool> check(26,false);

        for(int i = 0 ; i<n ; i++)
        {
            string temp;
            cin>>temp;
            check[temp[0]-'A'] = true;
        }

        int cnt = 0;

        for(int i = 0 ; i<26 && check[i]; i++)
            cnt ++;

        cout<<"#"<<testCase<<" "<<cnt<<endl;

    }
    return 0;
}
