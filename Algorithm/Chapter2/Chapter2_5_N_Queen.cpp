#include <iostream>

#include <vector>

using namespace std;


class Queen
{
private:

    vector<int> cols;
    int size;

public:
    Queen(int _size)
    {
        size = _size;
        for(int i = 0; i<size+1; i++)
        {
            cols.push_back(-1);
        }
    }

    void printMap()
    {
        for(int i = 1 ; i < size+1; i++ )
        {
            for(int j = 1 ; j<size+1; j++)
            {
                if( j == cols[i])
                        cout<<"♣ ";
                else
                    if(((i%2) + j) %2 == 0)
                        cout<<"□ ";
                    else
                        cout<<"■ ";
            }
            cout<<endl;
        }
    }

    bool checkQueen(int level=0)
    {
        if( !promissing(level))
            return false;

        if(level == size)
            return true;

        for(int i = 1; i< size+1; i++)
        {
            cols[level+1] = i;

            if(checkQueen(level+1))
                return true;
        }

        return false;
    }

    bool promissing(int level)
    {
        for(int i = 1 ; i < level; i++)
        {
            if( cols[i] == cols[level] )
                return false;
            if( (level - i) == abs(cols[level] - cols[i]))
                return false;
        }
        return true;
    }

};



int main()
{
    Queen queen(4);

    queen.printMap();

    cout<<endl;
    cout<<endl;

    if(queen.checkQueen())
    {
        cout<<"성공"<<endl;
        cout<<endl;
        queen.printMap();
    }
    else
        cout<<"실패"<<endl;

    cout<<endl;
    cout<<endl;

     Queen queen1(8);

    queen1.printMap();

    cout<<endl;
    cout<<endl;

    if(queen1.checkQueen())
    {
        cout<<"성공"<<endl;
        cout<<endl;
        queen1.printMap();
    }
    else
        cout<<"실패"<<endl;




    return 0;
}