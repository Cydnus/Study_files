#include <iostream>
#include <vector>
#include <string>

using namespace std;


string add(string a, string b)
{
    if(a.size() < b.size())
    {
        string temp = a;
        a = b;
        b= temp;
    }

    int carry = 0;
    int i = 1;

    for(i = 1; i<=b.size(); i++)
    {
        int temp = (a[a.size()-i] - '0' + b[b.size()-i]-'0') + carry;
        carry = temp/10;
        temp %= 10;
        a[a.size()-i] = temp + '0';
    }

    while( carry != 0)
    {
        if( i > a.size() && carry != 0)
        {
            a.insert(a.begin(),carry+'0');
            carry = 0;
        }
        else if( i <= a.size() && carry != 0)
        {
            int temp = ( a[a.size()-i] -'0'+ carry ) %10;
            carry += a[a.size()-i] -'0';
            carry /= 10;
            a[a.size()-i] = temp+'0';
        }
        
        i ++;
    }
    return a;
}

int main()
{
    string str = "2";

    for(int i = 0 ; i< 999; i++)
    {
        str = add(str,str);
        cout<<i+2<<"\t"<<str<<endl;
    }
    int num  = 0;

    for(char c : str)
        num+= c-'0';

    cout<<num<<endl;
    return 0;
}
