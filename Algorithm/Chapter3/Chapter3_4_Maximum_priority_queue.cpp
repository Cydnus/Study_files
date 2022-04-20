#include <iostream>

#include <vector>


using namespace std;


template <typename T>
class PriorityQueue
{
private:
    vector<T> data;
    int size;
    int isMax;


    void swap(int a, int b)
    {
        T temp = data[a];
        data[a] = data[b];
        data[b] = temp;
    }

    int getParent(int i)
    {
        return i/2 -1;
    }

    void Heapify(int ind)
    {
        int left_index= (ind*2) + 1;

        if(  left_index >=  size )
            return;

        int min_max;

        if(isMax == MAX_PRIORITY )
        {

            if( left_index+1 >= size )
                min_max = left_index;
            else
                min_max = (data[left_index] >  data[left_index+1])? left_index : left_index+1;


            if( data[ind] >= data[min_max])
                return;

        }
        else if(isMax ==  MIN_PRIORITY)
        {
            if( left_index+1 >= size )
                min_max = left_index;
            else
                min_max = (data[left_index] <  data[left_index+1])? left_index : left_index+1;


            if( data[ind] <= data[min_max])
                return;

        }

        swap(min_max,ind);

        Heapify(min_max);
    }

    void built_heap()
    {
        for(int i = size/2+1; i>=0; i--)
        {
            Heapify(i);
        }
    }


public:
    static const int MAX_PRIORITY = 1;
    static const int MIN_PRIORITY = 0;

    PriorityQueue(int Max_Min=MAX_PRIORITY)
    {
        size = 0;
        isMax = Max_Min;
    }
    PriorityQueue(vector<T> _data, int Max_Min=MAX_PRIORITY)
    {
        data = _data;
        size = data.size();
        isMax = Max_Min;

        built_heap();
    }
    ~PriorityQueue()
    {
        size= 0 ;
        data.clear();
    }


    void insert(T x)
    {
        data.push_back(x);

        int i = size;
        int p_i = getParent(i);

        size ++;

        if( isMax == MAX_PRIORITY)
            while( i > 0 && data[p_i] < data[i] )
            {
                swap(p_i, i);
                i = p_i;
            }
        else if( isMax == MIN_PRIORITY)
            while( i > 0 && data[p_i] > data[i] )
            {
                swap(p_i, i);
                i = p_i;
            }


    }

    void display()
    {
        int ind = 1, step = 1;


        for(int i = 0 ; i< size; i++)
        {
            if( i == ind)
            {
                cout<<endl;
                step *=2;
                ind += step;
            }
            cout<<data[i]<<'\t';
        }

    }

    T Extract()
    {
        if( size < 1)
        {
            return (T)NULL;
        }

        size --;

        swap(0,size);
        T outputs = data[size];
        data.pop_back();//.erase(data.begin()+size);


        Heapify(0);

        return outputs;
    }



};


int main()
{
    vector<int> temp = {4,1,3,2,16,9,10,14,8,7};

    PriorityQueue<int> *pq =new  PriorityQueue<int>(temp,PriorityQueue<int>::MAX_PRIORITY);

    pq->display();

    cout<<"\n\n\n"<<endl;

    pq->insert(12);

    pq->display();

    cout<<"\n\n\n"<<endl;
    cout<<pq->Extract()<<"\n\n"<<endl;
    pq->display();

    cout<<"\n\n\n"<<endl;

    PriorityQueue<int> *pq1 = new PriorityQueue<int>(temp, PriorityQueue<int>::MIN_PRIORITY);

    pq1->display();

    cout<<"\n\n\n"<<endl;

    pq1->insert(12);

    pq1->display();

    cout<<"\n\n\n"<<endl;
    cout<<pq1->Extract()<<"\n\n"<<endl;
    pq1->display();

    cout<<"\n\n\n"<<endl;


    return 0;

}