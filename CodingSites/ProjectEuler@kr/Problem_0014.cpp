#include <iostream>
#include <vector>
#include <string>

#define     EVEN(n) (n/2)
#define     ODD(n)  (3 * n +1)

using namespace std;

int Collatz(vector<int> &step, uint64_t n)
{
    if( n == 1)
        return 0;
    if( n < 1000000 && step[n] != -1)
        return step[n];
    
    int ret ;
    if( n %2 == 0)
    {
        ret = Collatz(step,EVEN(n))+1;
        if( n < 1000000)
            step[n] = ret;
    }
    else
    {
        ret = Collatz(step,ODD(n))+1;
        if( n < 1000000)
            step[n] = ret;
    }
    return ret;

}




int main()
{
    vector<int> step(1000000,-1);

    int max = 0;
    int num = 0;
    for(uint64_t i = 1; i<1000000; i++)
    {
        int col = Collatz(step,i);
       // cout<<i<<"\t"<< col <<endl;
        if( max < col)
        {
            num = i;
            max = col;
        }
    }
    cout<<num<<endl;



    return 0;
}
