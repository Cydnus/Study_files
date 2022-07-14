#include <iostream>
#include <vector>
#include <string>

using namespace std;

string toBinary(int i)
{
    string str ="";

    while( i > 0)
    {
        if( i & 0x01 == 1)
            str = "1" + str;
        else   
            str = "0" + str;
        i = i >> 1;
    }
    return str;

}

bool isPalindrom(string str)
{
    int end = str.size()-1;
    int begin = 0;
    while(begin < end)
    {
        if( str[begin] != str[end])
            return false;
        begin ++;
        end --;
    }
    return true;
}


int main()
{
    uint64_t sum = 0;
    for(int i = 1; i<1000000; i++)
    {
        if(isPalindrom(to_string(i)) && isPalindrom(toBinary(i)))
        {
            sum += i;
        }
    }
    cout<<sum<<endl;
    return 0;
}
