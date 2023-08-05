#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        uint64_t n;
        cin>>n;
        uint64_t mid = (uint64_t) sqrt(n);

        while(n % mid != 0){
            mid --;
        }
        uint64_t answer = mid + n/mid -2;

        cout<<"#"<<testCase<<" "<<answer<<endl;
    }
    return 0;
}