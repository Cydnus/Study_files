#include <iostream>
#include <vector>
#include <string>

#define     B_LENGTH(a, p)  ((((p)*(p))-( 2 * (p) * (a))) / ((2 * (p)) - (2 *(a)) ))
#define     RIGHT_TRI(a,b,c)    ((((a)*(a))+((b)*(b))) == ((c)*(c)))

using namespace std;

bool isDigit(double n)
{
    if( n <= 0)
    return false;
    int temp = (int) n;
    if( n == temp)
        return true;
    return false;
}

int cntOfTri(int n)
{
    int cnt = 0;
    for (int a = 1; a < n; a++)
    {
        double b = B_LENGTH(a,n);
        if( isDigit(b) && RIGHT_TRI(a,b,n-a-b))
        {
            cout<<"\t"<<a<<"\t"<<b<<"\t"<<n-a-b<<endl;
            cnt ++;
        }
    }
    return cnt/2;
}


int main()
{
    int max = 0;
    int max_ind = 0;

    for(int i = 1; i<1001; i++)
    {    
        cout<<i<<endl;
        int temp = cntOfTri(i);
        if( temp > max)
        {
            max = temp;
            max_ind = i;
        }
    }
    cout<<max<<"\t"<<max_ind<<endl;
    return 0;
}
