#include <iostream>

using namespace std;


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        uint64_t num;
        scanf("%lld",&num);
        uint64_t temp = 0;
        while(num != 0)
        {
            int t =  temp + num%10;
            temp = t/10 + t%10;
            num/=10;
        }
        printf("#%d %lld\n",testCase,temp);
    }
    return 0;
}
