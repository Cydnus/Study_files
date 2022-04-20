#include <iostream>
#include <vector>

#define BACKGROUND_COLOR    0
#define IMAGE_COLOR         1
#define ALREADY_COUNTED    2


using namespace std;


class Bin_Image
{
private :
    vector<vector<int>> image;

public :
    Bin_Image(vector<vector<int>> image)
    {
        this->image = image;
    }

    void printImage()
    {
        for(vector<int> row : image )
        {
            for(int cell : row)
            {
                if(cell == BACKGROUND_COLOR)
                {
                    cout<<"  ";
                }
                else if(cell == IMAGE_COLOR)
                {
                    cout<<"■"<<" ";
                }
                else if(cell == ALREADY_COUNTED)
                {
                    cout<<"□"<<" ";
                }
            }
            cout<<endl;
        }
    }

    int countingCellsInBlob(int x, int y)
    {
        if(x < 0 || y < 0 || x > image[0].size()-1 || y > image.size()-1)
            return 0;
        if(image[y][x] != IMAGE_COLOR)
            return 0;

        image[y][x] = ALREADY_COUNTED;
        return 1 + countingCellsInBlob(x,y-1) + countingCellsInBlob(x+1,y-1)
                 + countingCellsInBlob(x+1,y) + countingCellsInBlob(x+1,y+1)
                 + countingCellsInBlob(x,y+1) + countingCellsInBlob(x-1,y+1)
                 + countingCellsInBlob(x-1,y) + countingCellsInBlob(x-1,y-1) ;
    }



};




int main()
{
    vector<vector<int>> binimg = {
        {1,0,0,0, 0,0,0,1},
        {0,1,1,0, 0,1,0,0},
        {1,1,0,0, 1,0,1,0},
        {0,0,0,0, 0,1,0,0},

        {0,1,0,1, 0,1,0,0},
        {0,1,0,1, 0,1,0,0},
        {1,0,0,0, 1,0,0,1},
        {0,1,1,0, 0,1,1,1}
    };

    Bin_Image biMap(binimg);

    biMap.printImage();
    int x = 5, y= 3;
    cout<<endl;
    cout<<endl;
    cout<<"x = "<<x<<" y = "<<y<<endl;
    cout<<"size : "<<biMap.countingCellsInBlob(x,y);
    cout<<endl;
    cout<<endl;
    biMap.printImage();

    return 0;
}