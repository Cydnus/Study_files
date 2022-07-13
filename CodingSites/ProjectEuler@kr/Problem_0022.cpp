#include <iostream>
#include <vector>
#include <string>

using namespace std;


void swap(string &a, string &b)
{
    string temp = a;
    a= b;
    b = temp;
}

void QuickSort(vector<string> &arr, int begin, int end)
{
    if( begin < end)
    {
        int min = begin;
        for(int i = begin; i < end; i++)
        {
            if(arr[i] < arr[end])
            {
                swap(arr[i],arr[min]);
                min++;
            }
        }
        swap(arr[end],arr[min]);

        QuickSort(arr,begin, min-1);
        QuickSort(arr, min+1, end);
    }
}

uint64_t sumOfCharictor(string str)
{
    uint64_t inp = 0;
    for(char c: str)
        inp += c-'A'+1;
    return inp;
}


int main()
{
    freopen("not_input_22.txt","r",stdin);

    string str;
    vector<string> arr;
    while(cin>>str)
    {
        arr.push_back(str);
    }

    QuickSort(arr, 0, arr.size()-1);
    uint64_t sum = 0;
    for(int i = 0 ; i<arr.size(); i++)
    {
        sum += sumOfCharictor(arr[i]) *(i+1);
    }
    cout<<sum<<endl;


    return 0;
}
