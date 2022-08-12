#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool same(string a, string b)
{
    if( a.size() != b.size())
        return false;

    int a_num[10] ={0,};
    int b_num[10] ={0,};

    for(int i = 0 ; i< a.size(); i++)
    {
        a_num[a[i]-'0'] ++;
        b_num[b[i]-'0'] ++;
    }
    for(int i = 0; i<10; i++)
    {
        if( a_num[i] != b_num[i] )
            return false;
    }
    return true;    
}


string solution(int n)
{
    string nstr = to_string(n);

    for(int i = 2 ; i < 10; i++)
    {
        if( same(nstr,to_string(n*i)) )
            return "possible";
    }
    return "impossible";

}

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n;
        cin>>n;

        cout<<"#"<<testCase<<" "<<solution(n)<<endl;
    }
    return 0;
}
