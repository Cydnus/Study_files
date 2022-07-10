#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int sum = 1;
    for(int i = 3; i<=1001; i+=2 )
    {
        for(int j = 0; j < 4 ; j++)
        {
            sum += i * (i-j) + j;
        }
    }
    cout<<sum<<endl;
    return 0;
}
