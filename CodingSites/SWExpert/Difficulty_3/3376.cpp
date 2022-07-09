#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    vector<uint64_t> arr = {1,1,1,2,2,3,4,5,7,9};
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;
        cout<<"#"<<testCase<<" ";
        if( n< arr.size())
            cout<<arr[n-1]<<endl;
        else
        {
            while( arr.size() < n+1)
            {
                arr.push_back(arr[arr.size()-2] + arr[arr.size()-3]);
            }            
            cout<<arr[n-1]<<endl;
        }

    }
    return 0;
}
