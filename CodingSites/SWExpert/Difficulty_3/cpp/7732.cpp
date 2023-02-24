#include <iostream>
#include <string>

#define     OUTPUT_SET_WIDTH            cout.width(2); cout.fill('0');
using namespace std;

uint64_t    toSec(string str)
{
    int stime[3] = {0,};
    int ind = 0;
    for(char c: str)
    {
        if( c == ':')
            ind ++;
        else
        {
            stime[ind] *= 10;
            stime[ind] += c- '0';
        }
    }
    ind = 0;
    for(int i = 0 ; i<3; i++)
    {
        ind *= 60;
        ind += stime[i];
    }
    return ind;
} 

int main()
{
    int T;12!
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string st, et;
        cin>>st>>et;
        uint64_t uist, uiet;
        uist = toSec(st);
        uiet = toSec(et);
        if(uist > uiet)
            uiet += 86400;
        uiet = uiet - uist;
        int times[3] = {0,};
        for(int i = 0; i<3; i++)
        {
            times[2-i] = uiet % 60;
            uiet /= 60;
        }
        
        cout<<"#"<<testCase<<" ";
        OUTPUT_SET_WIDTH
        cout<<times[0]<<":";
        OUTPUT_SET_WIDTH
        cout<<times[1]<<":";
        OUTPUT_SET_WIDTH
        cout<<times[2]<<endl;
    }
    return 0;
}
