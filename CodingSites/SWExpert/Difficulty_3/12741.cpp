#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    int a, b, c, d;
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);

        if( a < c)
            a = c;
        
        if( b > d)
            b = d;
        a = b-a;
        if( a < 0)
            a = 0;

        printf("#%d %d\n",testCase, a);
    }
    return 0;
}
