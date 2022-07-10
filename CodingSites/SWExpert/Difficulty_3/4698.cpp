#include <iostream>
#include <vector>
#include <string>

#define MAX_SIZE    1000000

using namespace std;

int main()
{
    
    int T;
    cin>>T;

    
    bool check[MAX_SIZE+1] ={ false, };

    check[0] = true;
    check[1] = true;

    for(int i = 2 ; i<=MAX_SIZE; i++)
        if( !check[i] )
            for(int j = i+i; j<=MAX_SIZE; j+=i)
                check[j] = true;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        //int d;
        string d;
        int a, b;

        cin>>d>>a>>b;

        
        int n = 0;

        for(int i = a; i<=b; i++)
        {
            if( !check[i])
            {
                string tmp = to_string(i);
                if(tmp.find(d) != string::npos)
                    n++;
            }
        }        
        cout<<"#"<<testCase<<" "<<n<<endl;
    }
    return 0;
}
