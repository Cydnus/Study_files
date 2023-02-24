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
        string str;
        cin>>str;
        vector<int> hash(10,0);
        string ret = "";
        for(char c:str)
        {
            if(hash[c-'0'] != 0)
            {
                hash[c-'0'] --;
                ret.erase(ret.find(c),1);
            }
            else
            {
                ret += c;
                hash[c-'0']++;
            }

        }
        cout<<"#"<<testCase<<" "<<ret.size()<<endl;
    }
    return 0;
}
