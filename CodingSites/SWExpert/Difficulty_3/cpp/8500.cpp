#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;
        vector<int> people(n,0);
        for(int i = 0; i<n;i++)
            cin>>people[i];
        
        sort(people.begin(),people.end());

        int sum = n;
        for(int i =0 ;i<n;i++)
            sum+= people[i];
        sum+=people.back();


        cout<<"#"<<testCase<<" "<<sum<<endl;
    }
    return 0;
}
