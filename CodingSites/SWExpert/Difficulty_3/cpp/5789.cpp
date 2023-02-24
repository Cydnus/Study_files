#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n, q;
        cin>>n>>q;
        vector<int> arr(n,0);
        for(int i = 1; i<= q; i++)
        {
            int l, r;
            cin>>l>>r;
            for(int j = l-1; j<r; j++)
            {
                arr[j] = i;
            }
        }
        cout<<"#"<<testCase<<" ";
        for(int i : arr)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
