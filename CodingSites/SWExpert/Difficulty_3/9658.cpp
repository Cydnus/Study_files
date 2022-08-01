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

        int conv = 0;

        for (int i = 0; i < str.size() && i < 3; i++)
        {
            conv*=10;
            conv += str[i]-'0';
        }

        conv += 5;
        conv /= 10;
        int size = str.size()-1;
        if( conv >= 100)
        {
            size ++;
            conv/=10;
        }

        string result = to_string(conv);
        result.insert(result.begin()+1,'.');
        result += "*10^";


        cout<<"#"<<testCase<<" ";
        cout<< result<<size<<endl;
    }
    return 0;
}
