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
    freopen("input_13.txt", "r", stdin);

    string str, sum="0";

    for(int i = 0; i<100; i++)
    {
        cin>>str;
        sum = add(sum,str);
    }
    cout<<sum<<endl;

    for(int i = 0 ; i<10; i++)
        cout<<sum[i];
    cout<<endl;
    return 0;
}
