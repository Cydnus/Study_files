#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int testCase = 1; testCase <= T; testCase++ )
    {
        string str;
        cin>> str;

        int win_cnt = 0;
        for(char c : str)
            if( c == 'o')
                win_cnt ++;
        win_cnt += 15-str.size();
        cout <<"#"<<testCase<<" ";
        if( win_cnt >= 8)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }

    return 0;
}
