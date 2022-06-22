#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin>>T;
    
    vector<int> days = {0, 31, 60, 91, 121, 152,
                        182, 213, 244, 274, 305, 335};

    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int m,d;
        cin>>m>>d;
        m --;
        int day = days[m] + d +3;
        day %= 7;
        
        cout<<"#"<<testCase<<" "<<day<<endl;
    }
    return 0;
}
