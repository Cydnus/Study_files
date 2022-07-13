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




string multiply(string a, string b)
{    
    if(a.size() < b.size())
    {
        string temp = a;
        a = b;
        b= temp;
    }

    int offset = 1;

    string num;
    for(offset = 0 ; offset<b.size(); offset++)
    {
        num.push_back('0');
        int mul = b[offset]-'0';
        string step = a;
        int step_carry = 0;
        int i = 0;
        for(i = 0; i < step.size(); i++)
        {
            int temp = (step[step.size()-1 - i]-'0') * mul + step_carry;
            step_carry = temp/10;
            step[step.size()-1 - i] = temp%10 + '0';
        }

        while( step_carry != 0)
        {
            if( i > step.size())
            {
                step.insert(step.begin(),step_carry+'0');
                step_carry = 0;
            }
            else if( i < step.size())
            {
                int temp = step[step.size()-i] -'0'+ step_carry ;
                step_carry = temp / 10;
                step[step.size()-i] = temp+'0';
            }
        
            i ++;
        }

        num = add(num,step);
    }

    return num;
}

int main()
{
    string str = "1";
    for(int i = 1; i<=100; i++)
    {
        str = multiply(str, to_string(i));
    }
    uint64_t sum = 0;
    for(char c:str)
        sum += c-'0';
    cout<<sum<<endl;
    return 0;
}
