#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> setSubStr;

void powerSet(string str, int ind=0, string sub="", bool temp = true)
{
    if(ind == str.size())
    {
        setSubStr.insert(sub);
        return;
    }
    if( sub=="")
    {
        powerSet(str, ind+1, sub, true);
        sub += str[ind];
        powerSet(str, ind+1, sub, true);
    }
    else if(temp)
    {
        powerSet(str, ind+1, sub, false);
        sub += str[ind];
        powerSet(str, ind+1, sub, true);
    }
    else
    {
        powerSet(str, ind+1, sub, false);
    }
}


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        string str;
        cin>>n>>str;

        //init
        setSubStr.clear();  

        powerSet(str);

        set<string>::iterator iter = setSubStr.begin();
        int i = 0;
        
        while(i < n && iter != setSubStr.end())
        {
            i++;
            iter ++;
        }


        cout<<"#"<<testCase<<" "<<*iter<<endl;
    }
    return 0;
}
