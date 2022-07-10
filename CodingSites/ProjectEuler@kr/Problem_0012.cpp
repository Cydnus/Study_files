#include <iostream>
#include <vector>
#include <string>

using namespace std;

int CountOfDiv(uint64_t num)
{
    int ret = 0;
    int i = 1;
    for(i = 1; i*i <num; i++)
    {
        if( num % i == 0)
            ret ++;
    }
    ret *=2;
    if(i *i == num)
        ret++;
    return ret;
}

int main()
{
    int sum = 1;
    int ind = 2;
    while(CountOfDiv(sum)<500)
    {
        sum += ind;
        ind ++;
    }
    cout<<sum<<endl;

    return 0;
}
