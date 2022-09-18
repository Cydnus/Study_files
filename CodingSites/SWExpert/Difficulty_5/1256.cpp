#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
    int T;
    cin>>T;
    

    for(int testCase = 1; testCase<=T; testCase ++)
    {
        
        int n;
        cin>> n;

        string str;
        cin>>str;

        vector<string> array;

        for(int i = 0; i<str.size(); i++)
        {
            array.push_back(str.substr(i));
        }
        
        sort(array.begin(), array.end());


        cout<<"#"<<testCase<<" ";
        if( n-1 < array.size())
            cout<<array[n-1]<<endl;
        else
            cout<<"none"<<endl;
    }
    return 0;
}
