#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string a, b,c;
        cin>>a>>b>>c;

        cout<<"#"<<testCase<<" ";
        cout<<(char)toupper(a[0])<<(char)toupper(b[0])<<(char)toupper(c[0])<<endl;
    }
    return 0;
}
