#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isComp(uint64_t a, uint64_t b)
{
    vector<int> cnt_a(10,0);
    vector<int> cnt_b(10,0);
    while( a > 0)
    {
        cnt_a[a%10]++;
        a /= 10;
    }
    
    while( b > 0)
    {
        cnt_b[b%10]++;
        b /= 10;
    }

    for(int i = 0 ; i< 10; i++)
    {
        if(cnt_a[i] != cnt_b[i])
            return false;
    }
    return true;
}


bool check_Multi(int n)
{
    uint64_t x2 = n * 2;
    uint64_t x3 = n * 3;
    uint64_t x4 = n * 4;
    uint64_t x5 = n * 5;
    uint64_t x6 = n * 6;
    
    return  isComp(n,x2) &&
            isComp(n,x3) &&
            isComp(n,x4) &&
            isComp(n,x5) &&
            isComp(n,x6);


}

int main()
{
    for(int i = 1; i<=10000000; i++)
    {
        if(check_Multi(i))
        {
            for(int j = 1; j<7; j++)
            {
                cout<<i*j<<"\t";
            }
            cout<<endl;
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
