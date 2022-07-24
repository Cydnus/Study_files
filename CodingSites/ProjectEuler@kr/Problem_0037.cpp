#include <iostream>
#include <vector>
#include <string>

#define     MAX_NUM     1000000

using namespace std;

bool LeftCheck( vector<bool> prime, int i)
{
    int mod = 10;
    int temp = i % mod;
    while(temp != i)
    {
        if(prime[temp] == false)
            return false;
        mod = mod*10;
        temp = i % mod;
    }
    return true;
}

bool RightCheck( vector<bool> prime, int i)
{
    int temp = i/10;
    while(temp > 0)
    {
        if(prime[temp] == false)
            return false;
        temp = temp / 10;
    }
    return true;
}


int main()
{
    vector<bool> prime( MAX_NUM, true);

    prime[0] = false;
    prime[1] = false;

    for (int i = 4; i < MAX_NUM; i+=2)
        prime[i] = false;
    
    for(int i =3 ; i<MAX_NUM; i+=2)
        if(prime[i])
            for(int j = i+i; j < MAX_NUM ; j+=i)
                prime[j] = false;

    int sum = 0;

    for(int i = 11; i<MAX_NUM; i+=2)
    {
        if(prime[i] &&( LeftCheck(prime,i) && RightCheck(prime,i)))
        {
            sum += i;
            cout<<i<<"\t"<<sum<<endl;
        }
    }

    


    return 0;
}
