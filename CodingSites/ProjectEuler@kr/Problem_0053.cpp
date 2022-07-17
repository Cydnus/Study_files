#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int cnt = 0;
    for(int n =1; n<=100; n++)
    {
        for(int r = 1; r<=n; r++)
        {        
            double ncr = 1;

            for(int i = 0; i<r; i++)
            {
                ncr *= (double)(n-i) / (r-i);
            }
            if(ncr >= 1000000)
                cnt ++;

        }
    }
    cout<<cnt<<endl;


    return 0;
}
