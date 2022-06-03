#include <iostream>
#include <string>

using namespace std;

int CountOfTarget(string str, string target)
{
    int strSize = str.size();
    int tarSize = target.size();
    int count = 0;
    for(int i =0 ; i< strSize - tarSize+1; i++)
    {
        string slice="";
        for(int j = 0; j<tarSize; j++)
        {
            slice += str[i+j];
        }
        if( slice == target)
            count ++;
    }
    return count;
}


int main()
{
    for(int testCase = 0; testCase < 10; testCase++)
    {
        int testNo;
        cin>>testNo;
        cout<<"#" << testNo <<" ";

        string strTarget, strFull;

        cin >> strTarget;
        cin >> strFull;

        cout<<CountOfTarget(strFull, strTarget)<<endl;

    }
    return 0;
}
