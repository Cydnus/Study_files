#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int T=10;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int cnt;
        cin>> cnt;
        string str;
        cin>>str;
        stack<char> st;

        bool check = true;

        for(int i = 0 ; i<cnt; i++)
        {
            if( str[i] == '{'||str[i] == '('||str[i] == '['||str[i] == '<')
                st.push(str[i]);
            else if(str[i] == '}')
            {
                if( st.top() != '{')
                {
                    check = false;
                    break;
                }        
                st.pop();
            }
            else if(str[i] == ')')
            {
                if( st.top() != '(')
                {
                    check = false;
                    break;
                }            
                st.pop();            
            }
            else if(str[i] == ']')
            {
                if( st.top() != '[')
                {  
                    check = false;
                    break;
                }                
                st.pop();        
            }
            else if(str[i] == '>')
            {
                if( st.top() != '<')
                {
                    check = false;
                    break;
                }                
                st.pop();
            }
        }

        cout<<"#"<<testCase<<" ";
        if(check)
            cout<<1<<endl;
        else
            cout<<0<<endl;

    }
    return 0;
}
