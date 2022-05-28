#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int testCase = 1; testCase <= T; testCase++)
    {
        int cnt;
        cin>>cnt;
        
        cout<<"#"<<testCase<<endl;
        int linecnt = 0;
        for(int i =0; i<cnt;i++)
        {
            char c;
            int k;
            cin>>c>>k;

            for(int i = 0 ; i< k; i++)
            {
                if( linecnt == 10)
                {
                    linecnt = 0;
                    cout<<endl;
                }
                cout<<c;
                linecnt++;
            }
        }
        cout<<endl;
    }
    return 0;
}
