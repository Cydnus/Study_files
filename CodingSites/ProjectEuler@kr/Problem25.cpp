#include <iostream>
#include <vector>

#define END_POINT   1000

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
    vector<string> fibo;
    fibo.push_back("1");
    fibo.push_back("1");

    while(fibo.back().size() < END_POINT )
    {
        fibo.push_back(add(fibo[fibo.size()-1], fibo[fibo.size()-2]));
    }
    cout<<fibo.size()<<endl;

    string a = "1";
    string b = "1";
    int n = 2;
    while( b.size() < END_POINT)
    {
        string temp = add(a,b);
        a = b;
        b = temp;
        n++;
    }
    cout<<n<<endl;


    return 0;
}
