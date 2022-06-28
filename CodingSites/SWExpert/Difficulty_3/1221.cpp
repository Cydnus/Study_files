#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void QuickSort(vector<int> &arr, int start, int end)
{
    if( start < end)
    {
        int min = start;
        for(int i = start; i < end; i++)
        {
            if( arr[i] < arr[end])
            {
                swap(arr[i], arr[min]);
                min ++;
            }
        }
        swap(arr[min], arr[end]);
        QuickSort(arr,start,min-1);
        QuickSort(arr,min+1,end);
    }
}

int main()
{
    
    //freopen("not_input_1221.txt", "r", stdin);

    int T;
    cin>>T;
    
    vector<string> strNum;
    strNum.push_back("ZRO");
    strNum.push_back("ONE");
    strNum.push_back("TWO");
    strNum.push_back("THR");
    strNum.push_back("FOR");
    strNum.push_back("FIV");
    strNum.push_back("SIX");
    strNum.push_back("SVN");
    strNum.push_back("EGT");
    strNum.push_back("NIN");


    map<string,int> hash;
    hash["ZRO"] = 0;
    hash["ONE"] = 1;
    hash["TWO"] = 2;
    hash["THR"] = 3;
    hash["FOR"] = 4;
    hash["FIV"] = 5;
    hash["SIX"] = 6;
    hash["SVN"] = 7;
    hash["EGT"] = 8;
    hash["NIN"] = 9;


    for(int testCase = 1; testCase<=T; testCase ++)
    {
        string tc;
        int n;
        cin>>tc>>n;

        vector<int> num(n,0);

        for(int i = 0 ; i<n; i++)
        {
            string inp;
            cin>>inp;
            num[i] = hash[inp];
        }

        QuickSort(num,0,n-1);

        //sort(num.begin(),num.end());
        cout<<"#"<<testCase<<endl;
        for_each(num.begin(), num.end(), [strNum](int a){cout<<strNum[a]<<" ";});
        cout<<endl;
    }
    return 0;
}
