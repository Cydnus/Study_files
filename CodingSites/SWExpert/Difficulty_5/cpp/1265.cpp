#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n, p;

        cin>> n>> p;

        /*
            총량이 n으로 정해져 있는 부분들의 곱셈에서 가장 큰 수가 되게 하려면
            p등분 했을 경우에 가장 크게 생성이 됨.
        */

        int cnt = n/p;  // p 등분
        int diff = n % p; 
        // p등분 했을 경우 나머지 존재 가능성이 있음
        // 이를 각각에 1씩 더해주기 위하여 확인

        uint64_t prod= 1;
        for(int i = 0; i<p; i++)
        {
            if(diff > 0)
            {
                // 나머지만큼 각 부분에 1씩 더해줌
                prod*=cnt+1;
                diff--;
            }
            else    // 나머지 0이 되었기 때문에 p등분 한 값들을 곱해줌
                prod*=cnt;
        }

        cout<<"#"<<testCase<<" "<<prod<<endl;
    }
    return 0;
}
