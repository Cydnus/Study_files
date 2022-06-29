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
        vector<int> hash(26,0);
        string str;
        cin>>str;
        for(char c : str)
            hash[c-'a']++;
        
        cout<<"#"<<testCase<<" ";
        bool check = true;
        for(int i = 0 ; i<26;i++)
        {
            if(hash[i] %2 == 1)
            {
                cout<<(char)(i+'a');
                check = false;
            }
        }
        if(check)
            cout<<"Good";
        cout<<endl;
    }
    return 0;
}
