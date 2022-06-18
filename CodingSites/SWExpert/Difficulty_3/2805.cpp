#include <iostream>
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
        
        int sum = 0;
        int mid = n/2;

        for(int i = 0 ; i< n; i++)
        {
            string str;
            cin>>str;
            
            if( i > mid )
                for(int j = (i - mid) ; j< n-(i-mid); j++ )
                    sum+= str[j]-'0';
            else
                for(int j = mid - i; j <= mid +i; j++)
                    sum += str[j] -'0';

        }
        cout<<"#"<<testCase<<" "<<sum<<endl;
    }
    return 0;
}
