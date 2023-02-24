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
        int length ;
        cin>>length;
        string cor, wri;
        cin>>cor>>wri;

        int cnt = 0 ;

        for(int i = 0 ; i<length; i++)
            if(cor[i] == wri[i])
                cnt++;
        cout<<"#"<<testCase<<" "<<cnt<<endl;
    }
    return 0;
}
