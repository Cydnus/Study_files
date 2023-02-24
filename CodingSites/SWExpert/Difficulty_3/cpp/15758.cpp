#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    if(a < b)
    {
        int temp = b;
        b = a;
        a = temp;
    }

    if( b == 0)
        return a;
    return gcd(b, a%b);
}


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string s, t;
        cin>>s>>t;

        int lcd = (s.size() * t.size()) / gcd(s.size(), t.size());

        string conv_s = "", conv_t = ""; 
        for(int i = 0 ; i < (lcd / s.size() ) ; i++)
            conv_s += s;
        for(int i = 0 ; i < ( lcd / t.size() ) ; i++)
            conv_t += t;        

        cout<<"#"<<testCase<<" ";
        if( conv_s == conv_t)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;

    }
    return 0;
}
