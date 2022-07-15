#include <iostream>
#include <vector>
#include <string>

using namespace std;


int wordValue(string str)
{
    int num = 0;
    for(char c : str)
        num += c-'A'+1;
    return  num;
}

bool isTriNum(int target, int size)
{
    int begin = size;
    int end = size *26;
    target *=2;

    for(begin = size; begin <= end ; begin ++)
    {
        if( begin * (begin+1) == target)
            return true;
    }
    return false;
}

int main()
{
    freopen("not_input_42.txt","r",stdin);

    int cnt = 0;
    string str;

    while(cin>>str)
    {
        cout<<str<<"\t\t";
        int num = wordValue(str);
        cout<< num <<"\t";
        if(isTriNum(num,str.size()))
        {
            cnt ++;
            cout<<"yes"<<endl;
        }
        else
            cout<<"no"<<endl;

    }
    cout<<cnt<<endl;

    return 0;
}
