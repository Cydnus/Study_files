#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    for(int test_count = 1; test_count <= 10; test_count++)
    {
        vector<int> build;
        int inp_cnt;
        cin>>inp_cnt;
        for(int i = 0; i<inp_cnt; i++)
        {
            int inp_b ;
            cin>>inp_b;
            build.push_back(inp_b);
        }
        int cnt = 0;
        for(int i =2; i<inp_cnt-2; i++)
        {
            int max =  build[i-2];
            if( max < build[i-1])
                max = build[i-1];;
            if( max < build[i+1])
                max = build[i+1];;
            if( max < build[i+2])
                max = build[i+2];

            if( build[i] > max)
                cnt += build[i] - max;
        }
        cout<<"#"<<test_count<<" "<<cnt<<endl;

    }
}
