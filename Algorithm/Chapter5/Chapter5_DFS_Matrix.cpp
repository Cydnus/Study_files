#include <iostream>
#include <vector>
#include <string>

using namespace std;

void DFS(vector<vector<int>> matrix, vector<bool> &isVisit,int x)
{
    isVisit[x] = true;
    cout<<(char)('A'+x)<<"\t";
    for(int i = 0; i<matrix.size(); i++)
        if( matrix[x][i] == 1 && isVisit[i] == false)
            DFS(matrix,isVisit,i);

}


int main()
{
    vector<vector<int>> arr = {
        //  a   b   c   d   e   f   g   h   i   j
        {   0,  1,  1,  1,  0,  0,  0,  0,  0,  0   },  //a
        {   1,  0,  0,  0,  1,  1,  0,  0,  0,  0   },  //b
        {   1,  0,  0,  0,  0,  1,  0,  0,  0,  0   },  //c
        {   1,  0,  0,  0,  0,  0,  1,  1,  0,  0   },  //d
        {   0,  1,  0,  0,  0,  0,  0,  0,  1,  1   },  //e
        {   0,  1,  1,  0,  0,  0,  0,  0,  0,  0   },  //f
        {   0,  0,  0,  1,  0,  0,  0,  1,  0,  0   },  //g
        {   0,  0,  0,  1,  0,  0,  1,  0,  0,  0   },  //h
        {   0,  0,  0,  0,  1,  0,  0,  0,  0,  1   },  //i
        {   0,  0,  0,  0,  1,  0,  0,  0,  1,  0   }   //j
    };
    vector<bool> visit(arr.size(),false);

    DFS(arr, visit,0);


}
