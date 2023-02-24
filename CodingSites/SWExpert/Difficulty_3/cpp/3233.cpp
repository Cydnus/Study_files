#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        uint64_t a, b;
        cin>>a>>b;

        double area;
        area = a/b*a/b;
        //both  * 1/4 * tan(60deg) 
        //but, div a/b => removed *1/4 * tan(60deg) 
        
        cout<<"#"<<testCase<<" "<<(uint64_t)area<<endl;
    }
    return 0;
}
