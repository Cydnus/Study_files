#include <iostream>
#include <string>

#define     MAX_SIZE    1000000

using namespace std;

int main()
{
    string d=" ";
    int num = 1;
    while(d.size() <= MAX_SIZE)
    {
        d += to_string(num);
        num++;
    }
    cout<<d[1]<<endl;
    cout<<d[10]<<endl;
    cout<<d[100]<<endl;
    cout<<d[1000]<<endl;
    cout<<d[10000]<<endl;
    cout<<d[100000]<<endl;
    cout<<d[MAX_SIZE]<<endl;

    int mul = 1;
    for(int i = 1; i <= MAX_SIZE; i = i*10)
    {
        cout<<d[i]-'0'<<endl;
        mul *= (int)(d[i]-'0');
    }

    cout<<"\n\n"<<mul<<endl;
    
    return 0;
}
