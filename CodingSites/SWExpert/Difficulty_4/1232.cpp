#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> split(string str)
{
    vector<int> arr(2,0);
    int ind = 0;

    for(int i = 2; i<str.size(); i++)
    {
        if(str[i] == ' ')
            ind ++;
        else
        {
            arr[ind] *= 10;
            arr[ind] += str[i]-'0';
        }
    }
    return arr;
}

double calculate(vector<string> str, int node=0)
{
    if(str[node][0] == '-')
    {
        vector<int> arr = split(str[node]);
        int a = calculate(str,arr[0]-1);
        int b= calculate(str,arr[1]-1);
        return a - b;
    }
    else if(str[node][0] == '+')
    {
        vector<int> arr = split(str[node]);
        int a = calculate(str,arr[0]-1);
        int b= calculate(str,arr[1]-1);
        return a + b;
        
    }
    else if(str[node][0] == '/')
    {
        vector<int> arr = split(str[node]);
        int a = calculate(str,arr[0]-1);
        int b= calculate(str,arr[1]-1);
        return (double)((double)a/b);
        
    }
    else if(str[node][0] == '*')
    {
        vector<int> arr = split(str[node]);
        int a = calculate(str,arr[0]-1);
        int b= calculate(str,arr[1]-1);
        return a * b;        
    }
    else
        return stoi(str[node]);
}


int main()
{
    int T=10;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;

        vector<string> inputString(n,"");

        for(int i =0  ; i<n;i++)
        {
            int node;
            cin>>node;
            char garbage;
            cin.get(garbage);
            getline(cin, inputString[i]);
        }
        int temp = calculate(inputString);


        cout<<"#"<<testCase<<" "<<temp<<endl;
    }
    return 0;
}
