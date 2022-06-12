#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;
        int up,down,pre;
        up = 0;
        down = 0;
        cin>> pre;
        for(int i = 1; i<n;i++)
        {
            int inp;
            cin>>inp;

            int gap = inp - pre;
            if( gap > 0 && gap > up)
                up = gap;
            else if(gap<0 && (gap*-1) > down)
                down = -1 * gap;
            pre = inp;
        }
        cout<<"#"<<testCase<<" "<<up<<" "<<down<<endl;
    }
    return 0;
}
