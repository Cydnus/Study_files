#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int angle;
        cin>>angle;

        int hour = angle/30;
        int min = (angle%30)*2;
        cout<<"#"<<testCase<<" "<<hour<<" "<<min<<endl;
    }
    return 0;
}
