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
        int n,m;
        cin>>n>>m;

        vector<int> event(n);

        vector<int> organ(m);

        for(int i = 0; i<n; i++)
            cin>>event[i];
        for(int i = 0; i<m; i++)
            cin>>organ[i];
        
        vector<int> vote(n,0);

        for(int i = 0 ; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(event[j] <= organ[i])
                {  
                    vote[j] ++;
                    break;
                }
            }
        }
        int max = 0;
        for(int i = 1; i<n; i++)
        {
            if(vote[max] < vote[i])
            {
                max = i;
            }
        }

        cout<<"#"<<testCase<<" "<<max+1<<endl;
    }
    return 0;
}
