#include <iostream>
#include <vector>
#include <string>

using namespace std;


uint64_t modpow(uint64_t a, uint64_t e, uint64_t m)
{
    uint64_t r = 1, b = a%m;
    while( e> 0)
    {
        if( e& 1)
            r = (r*b)%m;
        b = (b*b) % m;
        e >>= 1;
    }
    return r;
}

bool check_composition(uint64_t n, uint64_t a, uint64_t d, uint64_t s)
{
    uint64_t x = modpow(a,d,n);
    if( x == 1 || x == n-1)
        return false;
    for(int r = 1; r<s; r++)
    {
        x = (uint64_t) x * x % n;
        if( x == n-1)
            return false;
    }

    return true;
}


bool miller_rabin(uint64_t n)
{
    if( n < 2)
        return false;
    int r= 0;
    uint64_t d = n-1;
    while((d&1) == 0)
    {
        d>>=1;
        r++;
    }
    for(int a : {2,3,5,7,11,13,17,19,23,29,31,37})
    {
        if( n == a)
            return true;
        if( check_composition(n,a,d,r))
            return false;
    }
    return true;

}




bool isPrime(int n)
{
    if(n %2 == 0 )
        return false;
    for(int i = 3; i*i<=n; i++)
    {
        if( n %i == 0)
            return false;
    }
    return true;
}

int main()
{
    vector<int> diag;
    int cnt_diag = 1;
    int side = 3;
    double primeper = 0;
    while(true )
    {
        cout<<side<<"\t";
        int sq = side *side;
        for(int i = 0; i< 4; i++)
        {
            int d = sq - i *(side-1);
            cout<<d<<"\t";
            if(miller_rabin(d))           // if(isPrime(d))
                diag.push_back(d);
        }
        cnt_diag +=4;
        primeper = (double) diag.size()/cnt_diag;
        cout<<cnt_diag<<"\t"<<primeper<<endl;
        if(diag.size() != 0 && primeper <= 0.1)
            break;
        side +=2;
    }

    cout<<side<<endl;


    return 0;
}
