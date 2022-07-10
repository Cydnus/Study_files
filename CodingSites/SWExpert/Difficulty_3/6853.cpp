#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;

        int n;
        cin>>n;

        int inner = 0, online = 0, out = 0;
        for(int i = 0 ; i<n;i++)
        {
            int x,y;
            cin>>x>>y;

            if( ( x == x1 && y >= y1 && y<=y2 ) ||
                ( x == x2 && y >= y1 && y<=y2 ) ||
                ( y == y1 && x >= x1 && x<=x2 ) ||
                ( y == y2 && x >= x1 && x<=x2 ) )
                online++;
            else if( x> x1 && x<x2 && y1< y && y < y2 )
                inner ++;
            else
                out ++;
        }

        cout<<"#"<<testCase<<" "<<inner<<" "<<online<<" "<<out<<endl;
    }
    return 0;
}
