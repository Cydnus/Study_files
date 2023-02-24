#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int T=10;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        string str;
        cin>>n>>str;

        stack<char> st;
        for(int i = 0; i<n; i++)
        {
            if(st.empty())
                st.push(str[i]);
            else if( st.top() == str[i])
                st.pop();
            else 
                st.push(str[i]);
        }
        string temp="";
        while(!st.empty())
        {
            temp += st.top();
            st.pop();
        }
        cout<<"#"<<testCase<<" ";
        for(int i = temp.size()-1 ; i>=0; i--)
            cout<<temp[i];
        cout<<endl;
    }
    return 0;
}
