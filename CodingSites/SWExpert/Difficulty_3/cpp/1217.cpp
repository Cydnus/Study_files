#include <iostream>
#include <vector>
#include <string>

using namespace std;


int pow(int a, int b)
{
    if( b == 0)
        return 1;
    return a * pow(a,b-1);
}

int main()
{
    
    for(int testCase = 0; testCase<10; testCase ++)
    {
        int T;
        cin>>T;
        cout<<"#"<<T<<" ";
        int a, b;
        cin>>a>>b;
        cout<<pow(a,b)<<endl;
    }
    
}
