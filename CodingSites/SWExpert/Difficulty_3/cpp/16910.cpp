#include <iostream>
#include <vector>
#include <string>

using namespace std;


int CountPoint(int r)
{
    int p = 0, end = r-1;
    int rcube = r*r, endCube = end * end;
    int i = 1;
    while( end > 0 && i < r)
    {
        if( endCube + (i*i) > rcube )
        {
            end --;
            endCube = end*end;
        }
        else
        {
            p += end;
            i++;
        }
    }
    return p;
}


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int r;
        cin>>r;

        int cnt = r*4+1;

        int hnh = CountPoint(r);
        cnt += hnh *4;
        cout<<"#"<<testCase<<" "<<cnt <<endl;
    }
    return 0;
}