#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int testCase = 1 ; testCase <= T; testCase++)
    {
        uint64_t p,q,r,s,w;
        cin>>p>>q>>r>>s>>w;

        uint64_t a = p * w;
        uint64_t b = q;
        if(w > r)
        {
            b += (w-r) * s;
        }

        cout<<"#" <<testCase<<" ";

        if( a > b)
            cout<<b<<endl;
        else
            cout<<a<<endl;

    }

}
