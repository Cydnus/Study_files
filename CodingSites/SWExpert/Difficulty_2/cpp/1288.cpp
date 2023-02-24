#include <iostream>
#include <set>

using namespace std;

int main()
{
    int T;
    cin>>T;

    for(int testCase = 1; testCase <= T; testCase++ )
    {
        int n;
        cin>>n;
        set<int> cnt;
        int sheep = 0;
        while(cnt.size() < 10)
        {
            sheep += n;

            int temp_sheep = sheep;

            while(temp_sheep > 0)
            {
                cnt.insert(temp_sheep % 10);
                temp_sheep/=10;
            }
        }
        
        cout<<"#"<<testCase<<" "<<sheep<<endl;
    }
    return 0;
}
