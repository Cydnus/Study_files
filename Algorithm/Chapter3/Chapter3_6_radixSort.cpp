#include <iostream>

#include <vector>
#include <string>
#include <fstream>


using namespace std;


void Counting_sort(vector<int> &a , int endOfValue, int adj)
{
    int size = a.size();
    vector<int> b = a;
    vector<int> count(endOfValue+1,0);


    for(int i = 0; i< size; i++)
        count[(a[i]%adj)/(adj/10)]++;

    for(int i = 1; i< endOfValue+1; i++)
        count[i] += count[i-1];

    for(int i = size-1; i>= 0 ; i--)
    {
           b[count[(a[i]%adj)/(adj/10)]-1] = a[i];
           count[(a[i]%adj)/(adj/10)] --;
    }

    a = b;
}

int power(int n, int pows)
{
    if(pows == 1)
        return n;
    return n*power(n,pows-1);
}


void RadixSort(vector<int> &a, int length)
{
    int size = a.size();


    for(int i = 0; i< length; i++)
    {
        Counting_sort(a,9,power(10,i+1));
    }
}



int main()
{

    vector<int> array;
    ifstream fin;
    fin.open("RadixSort.txt");

    if(fin.is_open())
    {
        while(!fin.eof())
        {
            string line;
            getline(fin,line);
            array.push_back(stoi(line));
        }
    }
    fin.close();

  for(int i = 0; i< array.size(); i++)
    {
        if( i!= 0 && i%30==0)
            cout<<endl;

        cout<<array[i]<<"\t";
    }

    cout<<endl;
    cout<<endl;
    cout<<"RadixSort"<<endl;
    RadixSort(array,5);
    cout<<endl;
    cout<<endl;

  for(int i = 0; i< array.size(); i++)
    {
        if( i!= 0 && i%30==0)
            cout<<endl;

        cout<<array[i]<<"\t";
    }


    return 0;
}