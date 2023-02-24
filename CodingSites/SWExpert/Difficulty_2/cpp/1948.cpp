#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;

    cin>>T;

    vector<int> dateOfMonth = { 
        0,  31,     59,     90,     120, 
        151,    181,    212,    243, 
        273,    304,    334,    365 
    };

    for(int testCase = 1; testCase <= T; testCase++)
    {
        int sm, sd, em,ed;
        cin>>sm>>sd>>em>>ed;

        sm --;
        em --;

        int smd = dateOfMonth[sm];
        int emd = dateOfMonth[em];

        smd += sd;
        emd+=ed;
        
        cout<<"#"<<testCase<<" "<<emd-smd+1<<endl;


    }
    return 0;
}