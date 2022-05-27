#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int testNo;
    
    while(cin>>testNo){
        queue<int> que;
        for(int i = 0; i<8; i++)
        {
            int num ;
            cin>>num;
            que.push(num);
        }
        int dec = 1;
        while(true)
        {
            int front = que.front();
            que.pop();
            if( front - dec <= 0)
            {
                que.push(0);
                cout<<"#" << testNo<<" ";
                while(!que.empty())
                {
                    cout<<que.front()<<" ";
                    que.pop();
                }
                cout<<endl;
                break;
            }
            else               
                que.push(front-dec);
            dec = (dec)%5 +1;
        }

    }
}
