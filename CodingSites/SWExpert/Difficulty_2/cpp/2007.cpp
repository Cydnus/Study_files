#include <iostream>
#include <string>

using namespace std;


bool findWord(string str, int length)
{
    for(int i = 0; i<length; i++)
    {
        if(str[i] != str[length+i])
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string str;
        cin>>str;

        cout<<"#"<<testCase<<" ";
        for(int i = 1; i<= 10; i++)
            if(findWord(str, i))
            {
                cout<<i<<endl;
                break;
            }
    }
    return 0;
}
