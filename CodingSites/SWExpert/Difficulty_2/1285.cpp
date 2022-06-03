#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;

    for(int testCase = 1; testCase <= T; testCase++)
    {
        int n;
        cin>>n;

        int min = 100000;
        int min_cnt = 0;

        for(int i = 0; i<n; i++)
        {
            int dist;
            cin>>dist;
            dist = abs(dist);

            if( min == dist)
                min_cnt ++;
            else if( min > dist)
            {
                min_cnt = 1;
                min = dist;
            }

        }
        cout<<"#"<<testCase<<" "<<min<<" "<<min_cnt<<endl;

    }

    return 0;
}
