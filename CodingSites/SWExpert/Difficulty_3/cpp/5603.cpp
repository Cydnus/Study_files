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
        vector<int> rick(n,0);
        int sum = 0;
        for(int i = 0; i<n; i++)
        {
            cin>>rick[i];
            sum += rick[i];
        }
        int aver = sum / n;
        sum = 0;
        for(int i = 0 ; i< n; i++)
        {
            if( rick[i] < aver)
                sum += aver - rick[i];
        }

        cout<<"#"<<testCase<<" "<<sum<<endl;
    }
    return 0;
}
