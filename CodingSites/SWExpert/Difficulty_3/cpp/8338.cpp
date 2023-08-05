#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    
    int inp;
    uint64_t result = 0;
    int n;
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        scanf("%d", &n);

        result = 0;
        scanf("%d", &inp);
        result = inp;

        for(int i = 1 ; i< n; i++)
        {
            scanf("%d", &inp);
            if(inp == 0 || inp == 1 || result <= 1)
                result += inp;
            else
                result *= inp;
        }

        printf("#%d %u\n",testCase, result);

    }
    return 0;
}