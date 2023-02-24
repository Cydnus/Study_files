#include <iostream>
#include <vector>
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
        int p = start;
        for(int i = start; i<end; i++)
        {
            if( arr[i] > arr[end])
            {
                swap(arr[i],arr[p]);
                p ++;
            }
        }    
        swap(arr[p],arr[end]);

        QuickSort(arr, start, p-1);
        QuickSort(arr, p+1, end);

    }
}


int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int k, n;
        cin>>n>>k;

        vector<int> score(n,0);
        for(int i = 0; i<n;i++)
        {
            cin>>score[i];
        }
        //sort(score.begin(),score.end(),[](int a, int b){return a > b;});
        QuickSort(score,0,n-1);
        int sum = 0;
        for(int i = 0; i<k; i++)
        {   
            sum+=score[i];
        }

        cout<<"#"<<testCase<<" "<<sum<<endl;
    }
    return 0;
}
