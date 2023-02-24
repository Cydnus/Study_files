#include <iostream>
#include <string>

using namespace std;

int checkPalindrome(string s, int b, int e)
{
    if(b >= e)
        return 1;
    if(s[b] != s[e])
        return 0;
    return checkPalindrome(s,b+1,e-1);
}

int main()
{
    int T;
    cin >> T;
    for(int testCase = 1; testCase<=T; testCase++)
    {
        string str;
        cin >> str;

        cout<<"#"<<testCase<< " " << checkPalindrome(str, 0, str.size()-1) <<endl;
    }
    return 0;
}
