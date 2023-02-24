#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;
        vector<int> person(n,0);
        double aver = 0;
        for(int i = 0; i<n; i++)
        {
            cin>>person[i];
            aver += person[i];
        }
        aver /= n;
        int cnt = 0;
        for(int i : person)
            if( i <= aver)
                cnt ++;

        cout<<"#"<<testCase<<" "<<cnt<<endl;
    }
    return 0;
}
