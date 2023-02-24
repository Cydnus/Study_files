#include <iostream>
#include <vector>
#include <string>

#define MATRIX_SIZE 8

using namespace std;

bool isPalindromeHor(vector<string> matrix, int i, int j, int n)
{
    for(int k = 0; k < n/2; k++)
        if(matrix[i][j+k] != matrix[i][j+n-k-1])
            return false;
    return true;
}
bool isPalindromeVer(vector<string> matrix, int i, int j, int n)
{
    for(int k = 0; k < n/2; k++)
        if(matrix[i+k][j] != matrix[i+n-k-1][j])
            return false;
    return true;
}


int main()
{
    int T=10;

    for(int testCase = 1; testCase <= T; testCase ++)
    {
        int n;
        cin>>n;
        vector<string> matrix(MATRIX_SIZE,"");

        for(int i = 0; i<MATRIX_SIZE; i++)
            cin>>matrix[i];

        int cnt = 0;

        for(int i = 0; i<MATRIX_SIZE; i ++)
        {
            for(int j = 0; j<MATRIX_SIZE-n+1; j++)
            {
                if( isPalindromeHor(matrix,i,j,n))
                    cnt ++;
                if( isPalindromeVer(matrix,j,i,n))
                    cnt++;

            }
        }

        cout<<"#"<<testCase<<" "<<cnt<<endl;
    }
    return 0;
}
