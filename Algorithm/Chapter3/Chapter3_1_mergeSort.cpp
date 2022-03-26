#include <iostream>

#include <vector>


#include <random>

using namespace std;

template <typename T>
void merge(vector<T> &data, int begin, int middle, int end)
{
    int i = begin, j = middle+1;
    vector<T> tmp;

    cout<<begin<<"\t"<<end<<endl;

    while(i <= middle && j <= end)
    {
        if(data[i] < data[j])
            tmp.push_back(data[i++]);
        else
            tmp.push_back(data[j++]);
    }

    while(i <= middle)
        tmp.push_back(data[i++]);
    while(j <= end)
        tmp.push_back(data[j++]);

    for(int k = begin; k <= end; k++)
    {
        data[k] = tmp[k-begin];
    }

}



template <typename T>
void merge_sort(vector<T> &data, int begin, int end)
{
    if( begin < end)
    {
        int middle = (begin + end) /2;
        merge_sort(data, begin, middle);
        merge_sort(data, middle+1, end);
        merge<T>(data, begin, middle, end);
    }
}



template <typename T>
T Random(T begin, T end)
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<T> dis(begin, end);

    return dis(gen);
}


int main()
{
    /*
    vector<int> temp = {5,7,2,9,3,15,23,45,6,1,30};

    for(int i = 0; i< temp.size();i++)
        cout<<temp[i] <<" ";
    cout<<endl;

    merge_sort<int>(temp,0,temp.size()-1);

    for(int i = 0; i< temp.size();i++)
        cout<<temp[i] <<" ";

    cout<<endl;
*/

    vector<int> temp;


    for(int i = 0; i< 2000;i++)
    {
        if( i!= 0 && i % 20 == 0)
            cout<<endl;
        temp.push_back(Random<int>(1,100000));

        cout<<temp[i] <<"\t";
    }
    cout<<endl;


    merge_sort<int>(temp,0,temp.size()-1);

    for(int i = 0; i< temp.size();i++)
    {
        if( i!= 0 && i % 20 == 0)
            cout<<endl;
        cout<<temp[i] <<"\t";
    }

    cout<<endl;

    return 0;
}