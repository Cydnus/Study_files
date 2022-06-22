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
        double sum = 0;
        for(int i = 0; i<n; i++)
        { 
            double p;
            int inp;
            cin>>p>>inp;
            sum+=p*inp;
        }
        cout.setf(ios::fixed);
        cout.precision(6);
        cout<<"#"<<testCase<<" "<<sum<<endl;
    }
    return 0;
}
