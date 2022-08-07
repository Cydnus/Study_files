#include <iostream>
#include <vector>
#include <string>

#define     MAX_SIZE    100

using namespace std;


bool isPalindromeHor(string matrix[], int i, int j, int n)
{
    int left = j;
    int right = j+n;
    if( right >= MAX_SIZE)
        return false;
    while(left < right)
    {
        if(matrix[i][left] != matrix[i][right])
            return false;
        left ++;
        right--;
    }
    /*
    for(int k = 0; k < n/2; k++)
        if(matrix[i][j+k] != matrix[i][j+n-k-1])
            return false;
            */
    return true;
}

bool isPalindromeVer(string matrix[], int i, int j, int n)
{
    int top = i;
    int bot = i+n;
    if( bot >= MAX_SIZE)
        return false;
    while(top < bot)
    {
        if(matrix[top][j] != matrix[bot][j])
            return false;
        top ++;
        bot--;
    }
    /*
    for(int k = 0; k < n/2; k++)
        if(matrix[i+k][j] != matrix[i+n-k-1][j])
            return false;
            */
    return true;
}


bool findPalindrome(string strs[], int size)
{
    for(int i = 0; i<MAX_SIZE; i++)
    {
        for(int j = 0; j+size <MAX_SIZE; j++)
        {
            if(isPalindromeHor(strs,i,j, size) || isPalindromeVer(strs,j,i, size))
                return true;
        }
    }
    return false;
}



int main()
{
    freopen("not_input_1216.txt", "r", stdin);
    freopen("not_output_1216.txt", "w", stdout);
    int T=10;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;

        string strs[MAX_SIZE];
        for(int i = 0 ; i < MAX_SIZE; i++)
            cin>>strs[i];

        for(int i = MAX_SIZE; i>0; i--)
        {
            if( findPalindrome(strs,i))
            {
                cout<<"#"<<testCase<<" "<<i+1<<endl;
                break;
            }
        }

    }
    return 0;
}
