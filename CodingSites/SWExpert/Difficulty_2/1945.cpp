#include <iostream>
#include <vector>
#include <string>

using namespace std;

int log(int &num, int bot)
{
    int cnt = 0;
    while(num % bot == 0)
    {
        cnt ++;
        num /= bot;
    }
    return cnt;
}


int main()
{    
    int T;
    cin>>T;

    for(int testCase = 1; testCase <= T; testCase++)
    {
        int N;
        cin>>N;
        
        cout<<"#"<<testCase<<" ";
        cout<<log(N,2)<<" ";
        cout<<log(N,3)<<" ";
        cout<<log(N,5)<<" ";
        cout<<log(N,7)<<" ";
        cout<<log(N,11)<<endl;
        
    }
    return 0;
}
