#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxs(int a, int b, int c)
{
    if(a < b)
        a = b;
    if(a < c)
        a = c;
    return a;
}


int main()
{
    int t ;
    cin>>t;
    for(int testcase = 1; testcase<=t; testcase ++)
    {
        int n;
        cin>>n;
        vector<vector<int>> graph(n,vector<int>(n,0));
        vector<string> str;
        for(int i =0; i<n;i ++)
        {
            string s;
            cin>>s;
            str.push_back(s);
        }
        int x=0,y=0;

        for(int i = 0; i<n; i++)
        {
            for(int j = 0 ; j< n; j++)
            {
                if( str[i][j] == '#')
                {                    
                    if(i == 0 && j == 0)
                        graph[i][j] = 1;
                    else if(i == 0)
                    {
                        if(str[i][j-1] == '#' )
                            graph[i][j] =graph[i][j-1] + 1;
                        else
                            graph[i][j] = 1;
                    }
                    else if (j == 0)
                    {
                        if(str[i-1][j] == '#')
                            graph[i][j] = graph[i-1][j] + 1;
                        else
                            graph[i][j] = 1;
                    }
                    else
                    {
                        if(str[i-1][j-1] == '#' && str[i][j-1] == '#' && str[i-1][j] == '#')
                        {
                            if(graph[i-1][j-1] == graph[i][j-1] && graph[i-1][j-1]== graph[i-1][j])
                                graph[i][j] = maxs(graph[i-1][j-1], graph[i][j-1], graph[i-1][j]) + 1;
                            else
                                graph[i][j] = graph[i-1][j-1]+1;
                        }
                        else
                            graph[i][j] = 1;
                    }

                    if( graph[i][j]  >= graph[x][y])
                    {
                        x = i;
                        y = j;
                    }
                }
            }
        }
        
        vector<string> str2(str);
        cout<<x<<"\t"<<y<<"\t"<<graph[x][y]<<endl;
        
        for(int i = 0; i< n; i++)
        {
            for(int j = 0 ; j< n; j++)
            {
                cout<<graph[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<"#"<<testcase<<" ";

        bool check = true;

        for(int i = 0; i< graph[x][y] && check; i++)
        {
            for(int j = 0 ; j< graph[x][y]; j++)
            {
                if( x-i < 0 || y-j <0)
                {
                    check = false;
                    break;
                }
                if(str2[x-i][y-j] == '#')
                {
                    str2[x-i][y-j] = '.';
                } 
                else
                {
                    check = false;
                    break;
                }
            }
        }
        for(int i = 0; check && i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(str2[i][j] == '#')
                {
                    check = false;
                    break;
                }
            }
        }
        if(check)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        
    }

    return 0;
}
