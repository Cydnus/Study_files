#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string inp;
        cin>>inp;
        vector<char> start = {'.','.','#','.','.'};
        vector<string>  append = {".#..","#.#.",".#","#.#.",".#.."};
        for(int i = 0; i<5; i++)
        {
            cout<<start[i];
            for(int j = 0 ; j<inp.size();j++)
            {
                if(i==2)
                    cout<<'.'<<inp[j];
                cout<<append[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
