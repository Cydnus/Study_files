#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool compare(string a, string b, int pos)
{
    for(int i = 0 ; i<b.size(); i++)
    {
        if( a[pos-i] != b[b.size()-1-i])
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
        string a, b;
        cin>>a>>b;
        int b_size = b.size();
        vector<int> alpha(26, b_size);

        for(int i = 0 ; i<b_size; i++)
        {
            if(alpha[b[b_size-1-i]-'a'] > i)
                alpha[b[b_size-1-i]-'a'] = i;
        }

        for(int i = b_size-1; i<a.size(); i++)
        {
            if(a[i] != b[b_size-1])
            {
                i += alpha[a[i]-'a']-1;
            }
            else
            {
                if( compare(a, b, i))
                {
                    a = a.replace(a.begin() + i - b_size+1, a.begin() + i+1, "1");
                    i -= b_size;
                    i+=2;
                }
            }
        }

        cout<<"#"<<testCase<<" "<<a.size()<<endl;
    }
    return 0;
}
