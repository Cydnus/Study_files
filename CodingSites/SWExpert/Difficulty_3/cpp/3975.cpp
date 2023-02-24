#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d", &a,&b,&c,&d);
        
        a *= d;
        c *= b;

        if( a == c)
            printf("#%d DRAW\n",testCase);
        else if( a > c)
            printf("#%d ALICE\n",testCase);
        else
            printf("#%d BOB\n",testCase);

    }
    return 0; 
}
