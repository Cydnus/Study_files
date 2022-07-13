#include <iostream>
#include <vector>
#include <string>
#include <set>

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
    vector<vector<string>> arr(102,vector<string>(102,""));

    for(int i = 2; i<=100; i++)
    {
        for(int j = 1; j<=100; j++)
        {
            if( j == 1)
                arr[i-2][j] = to_string(i);
            else 
                arr[i-2][j] = multiply(arr[i-2][j-1], to_string(i));
        }
    }
    set<string> arr_set;
    
    for(int i = 2; i<=100; i++)
    {
        for(int j = 2; j<=100; j++)
        {
            arr_set.insert(arr[i-2][j]);
        }
    }

    cout<<arr_set.size()<<endl;

    return 0;
}
