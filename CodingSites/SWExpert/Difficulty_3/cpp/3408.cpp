#include <iostream>


#define SIGMA(x)    (x*(x+1)/2)

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        uint64_t n;
        cin>>n;

        cout<<"#"<<testCase<<" ";
        cout<<(uint64_t) SIGMA(n) <<" ";
        cout<<(uint64_t)(SIGMA(n)*2-n)<<" ";
        cout<<(uint64_t)(SIGMA(n)*2)<<endl;
    }
    return 0;
}
