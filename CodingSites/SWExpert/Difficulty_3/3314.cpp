#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int avg = 0;
        for(int i = 0; i<5; i++)
        {
            int score;
            cin>>score;

            if( score < 40)
                score = 40;
            avg += score;
        }
        avg /= 5;
        cout<<"#"<<testCase<<" "<<avg<<endl;
    }
    return 0;
}
