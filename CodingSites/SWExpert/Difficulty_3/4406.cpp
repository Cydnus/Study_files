#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string strInput, strOutput ="";
        cin>>strInput;

        for(char c: strInput)
        {
            if(c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u')
                continue;
            strOutput += c;
        }

        cout<<"#"<<testCase<<" "<<strOutput<<endl;
    }
    return 0;
}
