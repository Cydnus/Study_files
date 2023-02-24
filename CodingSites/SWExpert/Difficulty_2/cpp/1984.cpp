#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;

    cin>>T;

    for(int testCase = 1; testCase <= T; testCase++)
    {
        int max = 0;
        int min = 10001;
        int sum = 0;

        for(int i =0 ; i< 10; i++)
        {
            int n;
            cin>>n;
            
            if( n> max )
            {
                sum+=max;
                max = n;
            }
            else if( n < min )
            {
                if(min != 10001)
                    sum+= min;
                min = n;
            }
            else
            {
                sum += n;
            }
        }
        sum += 4;
        sum /= 8;
        cout<<"#"<<testCase<<" "<<sum<<endl;

    }


    return 0;
}
