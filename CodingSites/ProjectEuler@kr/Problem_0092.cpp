#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> numsq(10,1);

int sumOfNum(uint64_t n)
{
    int sum = 0;
    while(n>0)
    {
        sum+= numsq[n%10];
        n/=10;
    }
    return sum;
}

bool check(vector<int> &sop, int n)
{
    //cout<<n<<"\t";
    if( n == 1 ||( n < 568 && sop[n] == -1))
    {
        //cout<<sop[n]<<"\t";
        return false;
    }
    if( n == 89 || ( n < 568 &&sop[n] == -2))
    {
        //cout<<sop[n]<<"\t";
        return true;
    }

    int son = sumOfNum(n);
    bool c = check(sop,son);
    if(c)
        sop[son] = -2;
    else
        sop[son] = -1;
    return c;
}


int main()
{
    //999 9999
    for(int i = 0 ; i< 10; i++)
        numsq[i] = i*i;
    
    vector<int> sumOfPos(568,0);
    sumOfPos[1] = -1;
    sumOfPos[89] = -2;
    int cnt = 0;
    for(uint64_t i = 1; i<10000000; i++)
    {
        if(check(sumOfPos,i))
            cnt ++;
        //cout<<endl;
    }
    cout<<cnt<<endl;

    return 0;
}
    