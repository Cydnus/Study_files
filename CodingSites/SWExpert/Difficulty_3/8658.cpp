#include <iostream>

using namespace std;

int split(int n)
{
    if( n == 0)
        return 0;
    return n%10 + split(n/10);
}


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int max = 0;
        int min = 100;
        for(int i = 0 ; i< 10; i++)
        {
            int inp;
            cin>>inp;
            inp = split(inp);
            if(inp > max)
                max = inp;
            if(inp < min)
                min = inp;
        }
        cout<<"#"<<testCase<<" "<<max<<" "<<min<<endl;
    }
    return 0;
}
