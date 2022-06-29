#include <iostream>
#include <vector>
#include <string>

#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string str;
        cin>>str;

        int h;
        cin>>h;

        vector<int> insertIndex(h,0);
        for(int i = 0 ; i< h; i++)
            cin>>insertIndex[i];

        sort(insertIndex.begin(),insertIndex.end(), [](int a, int b) {return a>b;});

        for(int i = 0; i<h; i++)
        {
            str.insert(str.begin()+insertIndex[i],'-');
        }
        
        cout<<"#"<<testCase<<" "<<str<<endl;
    }
    return 0;
}
