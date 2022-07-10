#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    map<char,int> alpha ={
        {'A', 1}, {'B', 2}, {'C', 0}, {'D', 1}, {'E', 0}, 
        {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0}, 
        {'K', 0}, {'L', 0}, {'M', 0}, {'N', 0}, {'O', 1}, 
        {'P', 1}, {'Q', 1}, {'R', 1}, {'S', 0}, {'T', 0}, 
        {'U', 0}, {'V', 0}, {'W', 0}, {'X', 0}, {'Y', 0}, 
        {'Z', 0}};

    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string a, b;
        cin>>a>>b;
        
        bool check = true;

        if( a.size() != b.size())
            check =false;

        vector<int> a_b;
        vector<int> b_b;
        for(int i =0 ; i<a.size() &&check == true; i++)
        {
            if( alpha[a[i]] != alpha[b[i]])
                check = false;
        }

        
        cout<<"#"<<testCase<<" ";
        if(check == true)
            cout<<"SAME"<<endl;
        else
            cout<<"DIFF"<<endl;
    }
    return 0;
}
