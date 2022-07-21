#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<char> num = {
        '0','1','2','3','4',
        '5','6','7','8','9'
    };

    vector<int> fect(10,1);
    for(int i = 1; i < 10; i++)
    {
        fect[i] = fect[i-1] *i;
    }
    string str ="";
    int p = 0, q = p;

    for(int i = 0 ; i< 10; i++)
    {
        int ind = -1;
        while( p < 1000000)
        {
            q = p;
            ind ++;
            p += fect[9-i];
        }        
        p = q;

        cout<<p+1<<"\t"<<ind<<"\t"<<num[ind]<<endl;

        str += num[ind];
        num.erase(num.begin()+ ind);

    }
    cout<<str<<endl;


    return 0;
}
