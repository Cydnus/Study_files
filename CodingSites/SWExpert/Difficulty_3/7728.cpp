#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n ;
        cin>>n;

        vector<int> hash(10,0);
        while(n>0)
        {
            hash[n%10] ++;
            n /= 10;
        }
        int cnt = 0;
        for(int i = 0 ; i<10; i++)
            if(hash[i] != 0)
                cnt++;

        cout<<"#"<<testCase<<" "<<cnt<<endl;
    }
    return 0;
}
