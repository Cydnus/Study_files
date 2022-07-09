#include <iostream>
#include <vector>

#define MAX_SIZE    1000000

using namespace std;


int main()
{
    vector<bool> check(MAX_SIZE+1, true);

    check[0] = false;
    check[1] = false;

    for(int i = 2 ; i<=MAX_SIZE; i++)
    {
        if( check[i] )
        {
            for(int j = 2; i*j<=MAX_SIZE; j++)
            {
                check[j*i] = false;
            }
        }
    }
    for(int i = 1 ; i <= MAX_SIZE; i++)
        if(check[i]==true)
            printf("%d ", i);


    return 0;
}
