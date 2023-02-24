#include <iostream>
#include <vector>
#include <string>

#define MODNUM  1234567891

using namespace std;

uint64_t x_y(uint64_t x, uint64_t y)
{
    uint64_t xy = 1;
    while(y>0)
    {
        if( y %2 == 1)
        {
            xy *= x;
            y --;
            xy %= MODNUM;
        }
        x *= x;
        x %= MODNUM;
        y /= 2;
    }
    return xy;
}

int main()
{
    
    int testNo;
    cin>>testNo;

    for (int testCase = 1; testCase <= testNo; testCase++)
    {
        uint64_t n, r;
        cin>>n>>r;
        if( r == 0)
        {           
            cout<<"#"<<testCase<< " "<<1<<endl;
            continue;
        }

        vector<uint64_t> factorial(n+1,1);

        for(uint64_t i = 1; i<=n; i++)
        {
            factorial[i] = (i * factorial[i-1]) % MODNUM;
        }

        uint64_t top = factorial[n];        
        uint64_t bot = (factorial[r] * factorial[n-r]) % MODNUM;
        
        bot = x_y(bot,MODNUM-2);
        bot %= MODNUM;
        top *= bot;
        top %= MODNUM;

        cout<<"#"<<testCase<< " "<<top<<endl;
    }

    return 0;
}
