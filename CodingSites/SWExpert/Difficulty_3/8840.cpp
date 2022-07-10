#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        long n;
        scanf("%ld", &n);
        n /=2;
        n *= n;
        printf("#%d %ld",testCase,n);
    }
    return 0;
}
