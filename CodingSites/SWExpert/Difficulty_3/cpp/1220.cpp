#include <iostream>
#include <vector>
#include <string>

#define TABLE_SIZE  100

using namespace std;

int table[TABLE_SIZE][TABLE_SIZE];

void move_node(int x, int y)
{
    if(table[x][y] == 1)
    {
        if( x == TABLE_SIZE -1 )
            table[x][y] = 0;
        else if( table[x+1][y] == 0)
        {
            table[x+1][y] = table[x][y];
            table[x][y] = 0;
            move_node(x+1,y);
        }
        else if(table[x+1][y] == 1)
        {
            move_node(x+1,y);
            table[x+1][y] = table[x][y];
            table[x][y] = 0;
            move_node(x+1,y);
        }
    }
    else
    {
        if( x == 0 )
            table[x][y] = 0;
        else if( table[x-1][y] == 0)
        {
            table[x-1][y] = table[x][y];
            table[x][y] = 0;
            move_node(x-1,y);
        }
        else if(table[x-1][y] == 2)
        {
            move_node(x-1,y);
            table[x-1][y] = table[x][y];
            table[x][y] = 0;
            move_node(x-1,y);
        }
    }
}

void table_move()
{
    //1 : N 2:S 

    // 1은 아래로 2는 위로 올라가야됨

    
    for(int i = 0 ; i<TABLE_SIZE ; i++ )
    {
        for(int j = 0 ; j<TABLE_SIZE ; j++ )
        {  
            if( table[i][j] != 0)
            {
                move_node(i,j);
            }
        }
    }


}

int getDeadLock()
{    
    int cnt = 0;

    for(int i = 0 ; i<TABLE_SIZE-1; i++ )
    {
        for(int j = 0 ; j<TABLE_SIZE ; j++ )
        {  
            if( table[i][j] == 1 && table[i+1][j] == 2)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    freopen("not_input_1220.txt","r",stdin);
    int T=10;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int size;
        cin>>size;

        
        for(int i = 0 ; i<TABLE_SIZE ; i++ )
            for(int j = 0 ; j<TABLE_SIZE ; j++ )
                cin>>table[i][j];

        table_move();


        cout<<"#"<<testCase<<" "<<getDeadLock()<<endl;
    }
    return 0;
}
