#include <iostream>
#include <vector>

#define MAX 10000

using namespace std;

int sumofmean(int n)
{
    int sum = 0;
    int i;
    for(i = 1 ; i*i < n; i++ )
    {
        if( n % i == 0)
        {
            sum += i;
            sum += n/i;
        }
    }
    if( i *i == n)
        sum += i;
    sum -= n;
    return sum;
}



int main()
{
    vector<int> d (MAX+1, -1);

    d[0] = -1;
    d[1] = 0;
    for(int i = 1; i<=MAX; i++)
    {
        if( d[i] == -1)
        {
            int som = sumofmean(i);
            d[i] = som;
            if( som <= MAX)
                d[som] = sumofmean(som);
        }
    }

    uint64_t sum = 0;

    for(int i = 1; i<= MAX ; i++)
    {
        if(d[i] <= MAX && d[d[i]]==i && d[i] != i)
        {
            cout<<i<<endl;
            sum += i;
        }
    }

    cout<<sum<<endl;

    return 0;
}
