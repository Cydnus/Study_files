#include <iostream>
#include <vector>
#include <string>

using namespace std;

void setBit(string &str, int ind, char bit)
{
    for(int i = ind; i<str.size(); i++)
        str[i] = bit;
}


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string target;
        cin>>target;
        string src= target;
        for(int i = 0 ; i< target.size(); i++ )
        {
            src[i] = '0';
        }

        int cnt = 0;
        
        for(int i = 0 ; i< target.size(); i++ )
        {
            if(target[i] != src[i])
            {
                cnt ++;
                setBit(src,i,target[i]);
            }
        }


        cout<<"#"<<testCase<<" "<<cnt<<endl;
    }
    return 0;
}
