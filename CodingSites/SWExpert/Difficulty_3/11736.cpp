#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b, int c)
{
    if( a > b)
        a = b;
    if( a > c)
        a = c;
    return a;
}
int max(int a, int b, int c)
{
    if( a < b)
        a = b;
    if ( a < c)
        a = c;
    return a;
}

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i = 0 ; i<n;i++)
        {
            cin>>arr[i];
        }
        int cnt = 0;
        for(int i = 1; i < n-1; i++)
        {
            if(arr[i] != min(arr[i-1],arr[i],arr[i+1]) &&
            arr[i] != max(arr[i-1],arr[i],arr[i+1])  )
            cnt ++;
        }

        cout<<"#"<<testCase<<" "<<cnt<<endl;
    }
    return 0;
}
