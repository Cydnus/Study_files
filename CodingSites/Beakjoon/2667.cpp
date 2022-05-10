#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CountOfBlob(vector<string> &map, int i, int j, int ho)
{
    if(i < 0 || i >= map.size() || j < 0 || j >= map.size() )
        return 0;

    if(map[j][i] != '1')
        return 0;

    map[j][i] = ho+'0';

    int top = CountOfBlob(map,i,j-1,ho);
    int bot = CountOfBlob(map,i,j+1,ho);
    int left = CountOfBlob(map,i-1,j,ho);
    int right = CountOfBlob(map,i+1,j,ho);

    return 1+top+bot+left+right;
}


int main()
{
    int cnt = 0;
    cin >> cnt;
    vector<string> map;
    
    for(int i = 0 ; i< cnt ; i++)
    {
        string temp;
        cin>>temp;
        map.push_back(temp);
    }

    vector<int> cob;
    for(int i = 0; i < cnt; i++)
    {
        for(int j = 0; j< cnt;j++)
        {
            int c = CountOfBlob(map,j,i,cob.size()+2);
            if( c != 0 )
            {
                cob.push_back(c);
            }
        }
    }
    cout<<cob.size()<<endl;
    sort(cob.begin(),cob.end());
    for(int i : cob)
        cout<<i<<endl;
}