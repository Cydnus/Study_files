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

        vector<int> input(n,0);
        for(int i = 0 ;i<n; i++)
        {
            int num;
            cin>>num;
            input[i] = num;
        }
        int max = input[0];

        for(int i = 1; i<n; i++)
        {
            if(input[i-1] >= 0 && input[i] + input[i-1] >= 0)
                input[i] += input[i-1];
p 
            if(max < input[i])
                max = input[i];
        }

        cout<<"#"<<testCase<<" "<<max<<endl;

    }
    return 0;
}
