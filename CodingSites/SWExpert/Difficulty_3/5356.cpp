#include <iostream>
#include <vector>
#include <string>

#define NUMOFSTRINGS    5

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        vector<string> str(NUMOFSTRINGS,"");
        int max_ind = 0;
        for(int i = 0 ; i<NUMOFSTRINGS; i++)
        {
            cin>>str[i];
            if(max_ind < str[i].size())
                max_ind = str[i].size();
        }
        
        cout<<"#"<<testCase<<" ";
        for(int i = 0; i<max_ind; i++)
        {
            for(int j = 0; j<NUMOFSTRINGS; j++)
            {
                if( str[j].size() > i)
                    cout<<str[j][i];
            }
        }
        cout<<endl;
    }
    return 0;
}
