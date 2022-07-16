#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> squared5(10,0);
    for(int i = 0; i<10; i++)
        squared5[i] = i*i*i*i*i;
    
    cout<<squared5[9]<<endl;
    //59049 => 6자리 (999999) -> 354294
    
    uint64_t sumOfReturn = 0;
    uint64_t sumOfsqur = 0;
    for(int i = 2; i<1000000; i++)
    {
        sumOfsqur = 0;
        int temp = i;
        while(temp>0)
        {
            sumOfsqur += squared5[temp%10];
            temp /=10;
        }

        if( sumOfsqur == i)
        {
            sumOfReturn += i;
            cout<<i<<"\t"<<sumOfReturn<<endl;
        }
    }
    cout<<sumOfReturn<<endl;


    return 0;
}
