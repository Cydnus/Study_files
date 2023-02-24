#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int testCase = 1; testCase <= T; testCase++)
    {
        int size;
        cin>>size;

        vector<int> arr;
        for(int i = 0 ; i< size; i++)
        {
            int input;
            cin>>input;
            arr.push_back(input);
        }
        sort(arr.begin(), arr.end());
        cout<<"#"<<testCase<<" ";
        for(int i =0 ; i<size; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
