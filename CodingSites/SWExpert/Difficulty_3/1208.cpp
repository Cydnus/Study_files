#include <iostream>
#include <vector>

#define MAX_WIDTH   100

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a= b;
    b= temp;
}

void QuickSort(vector<int> &arr, int start, int end)
{
    if( start < end)
    {
        int mid = start;
        for(int i = start; i<end;i++)
        {
            if(arr[i] > arr[end])
            {
                swap(arr[mid],arr[i]);
                mid++;
            }
        }
        swap(arr[mid], arr[end]);

        QuickSort(arr,start,mid-1);
        QuickSort(arr,mid+1,end);
    }
}


int main()
{
    int T=10;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int cntOfDump;
        cin>>cntOfDump;

        vector<int> floor(MAX_WIDTH,0);
        for(int i = 0 ; i<MAX_WIDTH; i++)
            cin>>floor[i];

        QuickSort(floor,0,MAX_WIDTH-1);

        for(int i = 0 ; i<cntOfDump; i++)
        {
            floor[0]--;
            floor[MAX_WIDTH-1]++;

            int max = 0;
            int min = MAX_WIDTH-1;
            while( floor[max] < floor[max+1])
            {
                swap(floor[max],floor[max+1]);
                max++;
            }
            while( floor[min] > floor[min-1])
            {
                swap(floor[min],floor[min-1]);
                min--;
            }
        }
        

        cout<<"#"<<testCase<<" " <<floor[0]- floor[MAX_WIDTH-1]<<endl;
    }
    return 0;
}
