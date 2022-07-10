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
        string a, b;
        cin>>a>>b;
        
        if( a.size() < b.size())
        {
            string temp = a;
            a = b;
            b= temp;
        }

        int carry = 0;
        int offset = 1;

        for(offset = 1 ; offset <= b.size(); offset++)
        {
            int temp = (b[b.size()-offset]-'0' +
                                    a[a.size()-offset] -'0'+ carry ) %10;
            carry += b[b.size()-offset] -'0' + a[a.size()-offset] -'0';
            carry /=10;
            a[a.size()-offset] = temp+'0';
        }
        while( carry != 0)
        {
            if( offset > a.size() && carry != 0)
            {
                a.insert(a.begin(),carry+'0');
                carry = 0;
            }
            else if( offset <= a.size() && carry != 0)
            {
                int temp = ( a[a.size()-offset] -'0'+ carry ) %10;
                carry += a[a.size()-offset] -'0';
                carry /= 10;
                a[a.size()-offset] = temp+'0';
            }
            
            offset ++;
        }
        cout<<"#"<<testCase<<" "<<a<<endl;
    }
    return 0;
}
