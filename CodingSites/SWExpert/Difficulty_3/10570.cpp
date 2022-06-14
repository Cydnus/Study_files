#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPal(double n)
{
    vector<int> split;
    int new_n = (int)n;

    if(n-new_n > 0)
        return false;

    while(new_n!=0)
    {
        split.push_back(new_n%10);
        new_n /= 10;
    }
    int size = split.size();
    for(int i = 0; i<size/2; i++)
    {
        if(split[i] != split[size-i-1])
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int a, b;
        cin>>a>>b;
        int cnt = 0;
        for(int i = a; i<=b ; i++)
        {
            if(isPal(i) && isPal(sqrt(i)))
                cnt ++;
        }

        cout<<"#"<<testCase<<" "<<cnt<<endl;
    }
    return 0;
}
