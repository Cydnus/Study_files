#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string str;
        cin>>str;
        map<char,int> hash;
        vector<char> cnt; 
        for(char c:str)
        {
            if(hash.find(c)!=hash.end())
                hash[c] ++;
            else
            {
                hash[c] = 1;
                cnt.push_back(c);
            }
        }

        cout<<"#"<<testCase<<" ";
        if(cnt.size() == 2 && hash[cnt[0]] == hash[cnt[1]] )
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}
