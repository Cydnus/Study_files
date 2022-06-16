#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T=10;
    freopen("not_input_1228.txt", "r", stdin);
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;
        vector<int> nums(n,0);
        for(int i = 0 ; i<n; i++)
            cin>>nums[i];

        cin>>n;
        for(int i = 0 ; i< n; i++)
        {
            char oper;
            int x;
            cin>>oper>>x;
            if( oper == 'I')
            {
                int y;
                cin>> y;
                vector<int> ins(y,0);
                for(int j = 0 ; j<y; j++)
                    cin>>ins[j];
                
                nums.insert(nums.begin()+x, ins.begin(), ins.end());
            }
        }

        cout<<"#"<<testCase<<" ";
        for(int i = 0; i< 10; i++)
            cout<<nums[i]<<" ";
        cout<<endl;
    }
    return 0;
}
