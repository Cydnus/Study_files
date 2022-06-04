#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> Rotate90(vector<vector<int>> src, int n)
{
    vector<vector<int>> ret(n,vector<int>(n,0));

    for(int i =0 ; i< n; i++)
    {
        for(int j = 0; j< n; j++)
        {            
            ret[j][i] = src[n-i-1][j];
        }
    }
    return ret;    
}

int main()
{
    int T;
    cin>>T;

    for(int testCase = 1; testCase <= T; testCase++)
    {
        int n;
        cin>>n;
        vector<vector<int>> array(n,vector<int>(n,0));

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                int inp;
                cin>>inp;
                array[i][j] = inp;
            }
        }

        cout<<"#"<<testCase<<endl;
        
        vector<vector<vector<int>>> rotates(3);
        rotates[0] = Rotate90(array, n);
        rotates[1] = Rotate90(rotates[0], n);
        rotates[2] = Rotate90(rotates[1], n);

        for(int i = 0; i< n; i++)
        {
            for(int k = 0 ; k<3; k++)
            {
                for(int j = 0 ; j<n; j++)
                {
                    cout<<rotates[k][i][j];
                }
                cout<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
