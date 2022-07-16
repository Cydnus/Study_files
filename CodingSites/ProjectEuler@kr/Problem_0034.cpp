#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<uint64_t> fect(10);
    fect[0] = 1;
    for(int i =1 ; i<10; i++)
        fect[i] = fect[i-1] * i;
    
    cout<<fect[9]<<endl;
    // 362880 ==> 최대 1000000까지 돌리면됨
    uint64_t sumOfNum = 0;
    uint64_t sumOfFactorion = 0;
    for(int i = 10; i<1000000; i++)
    {
        sumOfNum = 0;
        int temp = i;
        while(temp > 0)
        {
            sumOfNum += fect[temp%10];
            temp /= 10;
        }
        if(sumOfNum == i)
        {
            sumOfFactorion += i;
            cout<<i<<"\t"<<sumOfFactorion<<endl;
        }
    }
    cout<<sumOfFactorion<<endl;

    return 0;
}
