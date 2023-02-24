#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int64_t l,u,x;
        cin>>l>>u>>x;

        cout<<"#"<<testCase<<" ";
        if( x < l)
            cout << l-x<<endl;
        else if( x > u)
            cout<< -1<<endl;
        else
            cout<<0<<endl;

    }
    return 0;
}
