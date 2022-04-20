#include <iostream>

#include <vector>
#include <random>

using namespace std;


template <typename T>
T Random(T begin, T end)
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<T> dis(begin, end);

    return dis(gen);
}


template <typename T>
void swapAB(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
int Partition(vector<T> &data, int begin, int end)
{
    int pivot, min_index = begin -1, max_index = begin;

    //end와 pivot 위치 변경

    pivot = Random<int>(begin, end);

    cout<<begin<<"\t"<<end<<"\t"<<pivot<<endl;

    swapAB(data[end], data[pivot]);


    for(max_index = begin; max_index < end; max_index++)
    {
        if( data[max_index] < data[end])
        {
            min_index ++;
            swapAB(data[min_index], data[max_index]);
        }
    }

    min_index ++;

    swapAB(data[min_index], data[end]);

    return min_index;
}

template <typename T>
void QuickSort(vector<T> &data, int begin, int end)
{
    if(begin < end)
    {
        int mid = Partition(data, begin, end);
        QuickSort(data, begin, mid-1);
        QuickSort(data, mid+1, end);
    }
}





int main()
{
    /*
    vector<int> temp = {5,7,2,9,3,15,23,45,6,1,30};


    for(int i = 0; i< temp.size();i++)
    {
        cout<<temp[i] <<" ";
        if( i!= 0 && i % 80 == 0)
            cout<<endl;
    }
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


    QuickSort<int>(temp,0,temp.size()-1);

    for(int i = 0; i< temp.size();i++)
    {
        if( i!= 0 && i % 20 == 0)
            cout<<endl;
        cout<<temp[i] <<"\t";
    }

    cout<<endl;

}