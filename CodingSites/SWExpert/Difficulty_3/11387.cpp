#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int d, l, n;
        scanf("%d %d %d", &d, &l, &n);

        int damage = 0;

        damage = (n*(n-1))/2;
        damage *= l;
        damage += n *100;
        damage *= d/100;

        printf("#%d %d\n", testCase, (int)damage );

    }
    return 0;
}
