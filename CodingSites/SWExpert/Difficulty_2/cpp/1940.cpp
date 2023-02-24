#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{    
    int T;
    cin>>T;

    for(int testCase = 1; testCase <= T; testCase++)
    {
        int N;
        cin>>N;

        int nowPosition = 0;
        int nowSpeed = 0;

        for(int i = 0 ; i<N; i++)
        {
            int oper, opcode;
            cin>>oper;

            if(oper != 0)
            {
                cin>>opcode;
                if(oper == 1)
                    nowSpeed+=opcode;
                else if(oper == 2)
                {
                    nowSpeed -= opcode;
                    if(nowSpeed < 0)
                        nowSpeed = 0;
                }
            }

            nowPosition+=nowSpeed;
        }
        cout<<"#"<<testCase<<" "<<nowPosition<<endl;


    }
    return 0;
}
