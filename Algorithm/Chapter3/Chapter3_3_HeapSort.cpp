#include <iostream>

#include <vector>


using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


void Max_Heapify(vector<int> &data, int ind, int adj=0)
{

    int left_index= (ind*2) + 1;
    int size = data.size() - adj;
    if(  left_index >=  size )
        return;

    int max;

    if( left_index+1 >= size )
        max = left_index;
    else
        max = (data[left_index] >  data[left_index+1])? left_index : left_index+1;




    if( data[ind] >= data[max])
        return;

    swap(data[ind], data[max]);

    Max_Heapify(data, max, adj);
}


void Build_Max_heap(vector<int> &data)
{
    int size = data.size();

    for( int i = size/2 + 1 ; i >= 0; i-- )
    {
        Max_Heapify(data, i);
    }
}


void Heap_sort(vector<int> &data)
{
    Build_Max_heap(data);
    int heap_size = data.size();
    for( int i = 1 ; i < heap_size ; i++)
    {
        swap(data[0], data[heap_size-i]);
        Max_Heapify(data, 0, i);
    }
}




int main()
{
    vector<int> temp = {4,1,3,2,16,9,10,14,8,7};//{16,4,10,14,7,9,3,2,8,1};

    for(int i = 0 ; i< temp.size(); i++)
        cout<<temp[i] << " ";
    cout<<endl;

    Heap_sort(temp);

    for(int i = 0 ; i< temp.size(); i++)
        cout<<temp[i] << " ";
    cout<<endl;
    return 0;

}