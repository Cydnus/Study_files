#include <iostream>

#include <vector>

using namespace std;

#define PATHWAY     0
#define WALL        1
#define DEADEND     2
#define PATH        3


template <typename T>
class Maze
{
private:
    vector<vector<T>> maze ;
    int d_x;
    int d_y;

public:
    Maze<T>(vector<vector<T>> map)
    {
        maze = map;
    }

    void setDesination(int x, int y)
    {
        d_x = x;
        d_y = y;
    }

    void printMaze()
    {
        for(vector<T> temp : maze)
        {
            for(T tmp :temp)
            {
                cout<<tmp<<" ";
            }
            cout<<endl;
        }
    }

    bool findPath(int x, int y)
    {
        if( x < 0 || y < 0 || x >= maze[0].size() || y>=maze.size())    //맵 범위 초과
            return false;
        if( maze[y][x] != PATHWAY)  // 방문한적 있는 곳이나 벽
            return false;

        if( x == d_x && y == d_y ){   //목적지 도착
            maze[y][x] = PATH;
            return true;
        }

        maze[y][x] = PATH;
        if(findPath(x+1,y) || findPath(x,y+1) || findPath(x-1,y) || findPath(x,y-1))
        {
            return true;
        }

        maze[y][x] = DEADEND;
        return false;
    }

};


int main()
{
    vector<vector<int>> map = {
      {0,0,0,0, 0,0,0,1},   //1
      {0,1,1,0, 1,1,0,1},   //2
      {0,0,0,1, 0,0,0,1},   //3
      {0,1,0,0, 1,1,0,0},   //4
      {0,1,1,1, 0,0,1,1},   //5
      {0,1,0,0, 0,1,0,1},   //6
      {0,0,0,1, 0,0,0,1},   //7
      {0,1,1,1, 0,0,0,0}    //8
    };





    Maze<int> maze(map);

    maze.setDesination(7,7);
    maze.printMaze();

    cout<<endl;
    cout<<endl;

    bool isfind = maze.findPath(0,0);
    maze.printMaze();

    cout<<endl;
    cout<<endl;

    if( isfind )
        cout<<"성공!"<<endl;
    else
        cout<<"실패!"<<endl;


    cout<<endl;
    cout<<endl;

    Maze<int> maze1(map);

    maze1.setDesination(7,7);
    maze1.printMaze();

    cout<<endl;
    cout<<endl;

    isfind = maze1.findPath(6,1);
    maze1.printMaze();

    cout<<endl;
    cout<<endl;

    if( isfind )
        cout<<"성공!"<<endl;
    else
        cout<<"실패!"<<endl;




    return 0;
}