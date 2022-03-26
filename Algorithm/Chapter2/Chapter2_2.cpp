#include <iostream>

using namespace std;

//타겟값

//순차 정방향

int search1(int data[], int begin, int end, int target)
{
    if(begin > end)
        return -1;
    if( data[begin] == target)
        return begin;
    return search1(data, begin+1, end, target);
}

int search2(int data[], int begin, int end, int target)
{
    if(begin > end)
        return -1;
    if( data[end] == target)
        return end;
    return search2(data, begin, end-1, target);
}


int search3(int data[], int begin, int end, int target)
{
    if(begin > end)
        return -1;

    int middle = (begin + end) /2;

    if( data[middle] == target)
        return middle;
    int index = search3(data, begin, middle-1, target);
    if(index != -1 )
        return index;
    return search3(data, middle+1, end, target);
}



//최대값

//정방향
int findMax1(int data[], int begin, int end)
{
    if(begin == end)
        return data[begin];
    int find = findMax1(data,begin+1, end);
    return (data[begin] > find) ? data[begin]:find;
}

//역방향
int findMax2(int data[], int begin, int end)
{
    if(begin == end)
        return data[begin];
    int find = findMax2(data,begin, end-1);
    return (data[end] > find) ? data[end]:find;
}


// 중간부터
int findMax3(int data[], int begin, int end)
{
    if(begin == end)
        return data[begin];
    int middle = (begin + end) /2;
    int max1 = findMax3(data,begin,middle);
    int max2 = findMax3(data,middle+1, end);

    return (max1 >max2)? max1:max2;
}


//이진탐색

int binarySearch(int data[], int begin, int end, int target)
{
    if( begin > end)
        return -1;

    int middle = (begin+end)/2;

    if( data[middle] == target)
        return middle;

    else if( data[middle] > target)
        return binarySearch(data,begin,middle-1, target);
    else
        return binarySearch(data,middle+1, end, target);
}



int main()
{
    int data[] = {1,2,4,5,3};
    cout<< "정방향 탐색"<<endl;
    cout<< search1(data,0,4,3 )<<endl;

    cout<< "역방향 탐색"<<endl;
    cout<< search2(data, 0, 4,3 ) <<endl;

    cout<< "중간부터 탐색"<<endl;
    cout<< search3(data, 0, 4, 3 )<<endl;
    cout<<endl;


    cout<< "정방향 최댓값"<<endl;
    cout<< findMax1(data,0,4 )<<endl;

    cout<< "역방향 최댓값"<<endl;
    cout<< findMax2(data, 0, 4 ) <<endl;

    cout<< "중간부터 최댓값"<<endl;
    cout<< findMax3(data, 0, 4 )<<endl;
    cout<<endl;

    int data2[] = {1,2,3,4,5,6,7,8,9};
    cout<<"이진 탐색"<<endl;
    cout<<binarySearch(data2,0,8, 7);


    return 0;
}