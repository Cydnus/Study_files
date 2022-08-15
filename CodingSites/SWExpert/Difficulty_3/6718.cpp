#include <iostream>

using namespace std;

int main()
{
    //freopen("not_input_6718.txt","r",stdin);

    int T;
    scanf("%d", &T);
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        uint64_t dia;

        scanf("%ld", &dia);

        int ret = 0;
        if( dia >= 1000000)
            ret = 5;
        else if( dia >= 100000)
            ret = 4;
        else if( dia >= 10000)
            ret = 3;
        else if( dia >= 1000)
            ret = 2;
        else if( dia >= 100)
            ret = 1;

        printf("#%d %d\n", testCase, ret);
    }
    return 0;
}
