#include <iostream>
#include <cmath>
using namespace std;


bool isLeft(int v)
{
    while(v > 3)
    {
        v = v/2;
    }
    if( v == 3)
        return false;
    return true;
}


int find(int n, int v)
{
    int depth = log2(n);
    if(n < 3)
        return depth;

    int gotoRoot = log2(v);

    bool vLeft = isLeft(v);
    bool nLeft = isLeft(n);

    if(v != 1 && vLeft && nLeft)
        return  gotoRoot + depth-1;
    else    // 둘다 오른쪽
        return  gotoRoot + depth;
}


int main()
{
    int T;
    scanf("%d", &T);
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        //Write Your Code
        int n, v;
        scanf("%d %d", &n, &v);

        int visit = find(n, v);
        printf("#%d %d\n", testCase, visit);
    }
    return 0;
}
