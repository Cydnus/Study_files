#include <iostream>
#include <vector>
#include <string>

using namespace std;


string toPostOrder(string str)
{
    string ret = "";

    vector<char> opstack;

    for(char c : str)
    {
        if( c =='(' || c == '*')
            opstack.push_back(c);
        else if(c == '+')
        {
            while(!opstack.empty() && opstack.back() == '*')
            {
                ret += opstack.back();
                opstack.pop_back();
            }
            opstack.push_back(c);
        }
        else if( c >= '0' && c <= '9')
            ret += c;
        else
        {
            while( opstack.back() != '(')
            {
                ret += opstack.back();
                opstack.pop_back();
            }
            opstack.pop_back();
        }
    }
    if(!opstack.empty())
    {
        while(!opstack.empty())
        {
            ret += opstack.back();
            opstack.pop_back();
        }
    }

    return ret;
}


uint64_t solution(string str)
{
    string post = toPostOrder(str);
    vector<uint64_t> numstack;

    for(char c : post)
    {
        if( c == '*')
        {
            uint64_t a = numstack.back();
            numstack.pop_back();
            a *= numstack.back();
            numstack.pop_back();
            numstack.push_back(a);
        }
        else if( c == '+')
        {
            uint64_t a = numstack.back();
            numstack.pop_back();
            a += numstack.back();
            numstack.pop_back();
            numstack.push_back(a);            
        }
        else
            numstack.push_back(c-'0');

    }


    return numstack[0];
}


int main()
{
    int T=10;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        string str;
        cin>>n>>str;

        cout<<"#"<<testCase<<" "<<solution(str)<<endl;
    }
    return 0;
}
