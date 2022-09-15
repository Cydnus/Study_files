#include <iostream>
#include <string>

using namespace std;

int CountOfAlpha(string str)
{
    for(int i = 0 ; i<str.size(); i++)
    {
        if( str[i] != 'a'+i)
            return i;
    }
    return str.size();
}

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string str;
        cin>>str;
        cout<<"#"<<testCase<<" "<<CountOfAlpha(str)<<endl;
    }
    return 0;
}
