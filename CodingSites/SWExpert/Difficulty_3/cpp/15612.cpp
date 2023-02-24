#include <iostream>
#include <set>
#include <string>

#define BOARD_SIZE  8
#define ROCK_COUNT  8

using namespace std;

int LocateOfRock(string board, set<uint8_t> &locate)
{
    int cnt = 0;
    for(int i = 0; i<BOARD_SIZE; i++)
    {
        if( board[i] == 'O')
        {
            cnt ++;
            if(locate.find(i) == locate.end())
            {
                locate.insert(i);
            }
        }
    }
    return cnt;
}



int main()
{
    int T;
    cin>>T;
    
    set<uint8_t> locate;
    string board;
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        locate.clear();
        bool isFail = false;

        for(int i = 0 ; i<BOARD_SIZE; i++)
        {
            cin>>board;
            if(!isFail && LocateOfRock(board, locate) != 1)
            {
                isFail = true;
            }
        }

        cout<<"#"<<testCase<<" ";
        if( isFail || locate.size() != ROCK_COUNT )
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    return 0;
}
