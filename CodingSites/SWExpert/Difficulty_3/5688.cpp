#include <iostream>

using namespace std;

int check(uint64_t num)
{
    uint64_t cmp = 1;
    int i = 1;
    while(cmp<num)
    {
        i++;
        cmp = i*i*i;
    }
    if( cmp == num)
        return i;
    return -1;
}

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        uint64_t inp;
        cin>>inp;

        cout<<"#"<<testCase<<" "<<check(inp)<<endl;
    }
    return 0;
}
