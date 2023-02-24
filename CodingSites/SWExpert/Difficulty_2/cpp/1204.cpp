#include <iostream>
#include <vector>

#define MAX_STUDENT 1000

using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int i = 0 ; i<test; i++)
    {
        int no;
        cin>>no;
        int max = 0;
        vector<int> score(101, 0);

        for(int j = 0; j<MAX_STUDENT; j++)
        {
            int inp;
            cin>>inp;

            vector[inp] ++;

            if( score[max] < score[inp])
                max = inp;
            else if( score[max] == score[inp] && inp > max)
                max = inp;
        }

        cout<<"#"<<no<<" "<<max<<endl;
    }



}
