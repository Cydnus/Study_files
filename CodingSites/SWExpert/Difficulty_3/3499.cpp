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
        int n;
        cin>>n;

        vector<string> strArr(n,"");
        for(int i = 0; i<n;i++)
            cin>>strArr[i];
        int mid = (n+1)/2;

        cout<<"#"<<testCase<<" ";
        
        for(int i = 0; i<mid;i++)
        {
            cout<<strArr[i]<<" ";
            if(i+mid < n)
                cout<<strArr[i+mid]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
