#include <iostream>
#include <vector>
#include <string>

using namespace std;

int rotate(int n)
{
    int last = n%10;
    //n = n/10;
    int size = 1000000;
    while( n < size)
    {
        size /= 10;
    }
    n = last * size + (n/10);
    return n;
}

bool isCirculPrime(vector<bool> check, int n)
{
    int temp = rotate(n);
    while( n != temp)
    {
        if( !check[temp] )
            return false;
        temp = rotate(temp);
    }

    return true;
}


int main()
{
    vector<bool> check( 1000001, true);
    check[0] = false;
    check[1] = false;
    for(int i = 4; i<1000001 ; i+=2)
        check[i] = false;
    for(int i = 3; i<1000001; i+=2)
    {
        if(check[i] == true)
        {
            for(int j = i+i ; j< 1000001; j+=i)
            {
                check[j] = false;
            }
        } 
    }
    int cnt = 0;
    for(int i = 0 ; i<1000001; i++)
    {
        if( check[i] && isCirculPrime(check, i))
        {   
            cnt ++;
            cout<< i<<endl;  
        }
    }

    cout<<cnt<<endl;
    

    return 0;
}
