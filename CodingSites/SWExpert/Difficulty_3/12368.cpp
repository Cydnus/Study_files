#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int a, b;
        cin>> a>>b;

        a = (a+b)%24;
        
        cout<<"#"<<testCase<<" "<<a<<endl;
    }
    return 0;
}
