#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int a, b;
        cin>>a>>b;

        vector<int> hash(a+b+1,0);

        for(int i = 1; i<=a; i++)
        {
            for(int j = 1; j<=b;j++)
            {
                hash[i+j]++;
            }
        }
        int max = hash[0];
        for(int i = 1 ; i<hash.size(); i++)
            if( max < hash[i])
                max = hash[i];

        cout<<"#"<<testCase<<" ";

        for(int i = 1 ; i<hash.size(); i++)
            if( max == hash[i])
                cout<<i<<" ";
        cout<<endl;

    }
    return 0;
}
