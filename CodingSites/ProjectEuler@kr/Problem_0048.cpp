#include <iostream>
#include <vector>
#include <string>

#define     MOD     10000000000

using namespace std;

int main()
{
    uint64_t num=0;

    for(uint64_t i = 1; i<=1000; i++)
    {
        uint64_t add = i;
        cout.width(3);
        cout<<i<<"\t\t";
        for(int j = 1; j<i; j++)
        {
            add = (add *i) % MOD;
        }
        cout.width(10);
        cout<<add<<"\t\t";
        num = (num + add ) % MOD;
        cout.width(10);
        cout<<num<<endl;
    }
    cout<<num<<endl;
    return 0;
}
