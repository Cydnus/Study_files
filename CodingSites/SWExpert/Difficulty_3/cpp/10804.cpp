#include <iostream>
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
        string ret="";
        for(int i = str.size()-1; i>=0; i--)
        {
            if( str[i] == 'b')
                ret += 'd';
            else if( str[i] == 'd')
                ret += 'b';
            else if( str[i] == 'p')
                ret += 'q';
            else if( str[i] == 'q')
                ret += 'p';
        }

        cout<<"#"<<testCase<<" "<<ret<<endl;
    }
    return 0;
}
