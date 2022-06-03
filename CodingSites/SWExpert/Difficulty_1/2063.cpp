#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int inp;
    cin>> inp;

    vector<int> array;

    for(int i = 0; i < inp; i++)
    {
        int num;
        cin>>num;

        array.push_back(num);
    }
    sort(array.begin(), array.end());
    cout<<array[inp/2]<<endl;

}