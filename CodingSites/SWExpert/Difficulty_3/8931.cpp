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
        cin>> n;
        vector<int> arr;
        for(int i = 0 ; i< n; i++)
        {
            int inp;
            cin>>inp;
            if( inp == 0)
                arr.pop_back();
            else
                arr.push_back(inp);

        }
        int sum = 0;
        for(int i : arr)
            sum += i;
        cout<<"#"<<testCase<<" "<<sum<<endl;
    }
    return 0;
}
