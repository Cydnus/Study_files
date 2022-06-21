#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n, a, b;
        cin>>n>>a>>b;

        int min = a+b - n;
        if( min < 0 )
            min = 0;
        int max = (a>b)? b:a;

        cout<<"#"<<testCase<<" "<<max<<" "<<min<<endl;
    }
    return 0;
}
