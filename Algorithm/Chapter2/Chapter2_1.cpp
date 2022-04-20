#include <iostream>

using namespace std;

//Recursive

// 문자열 길이 계산

int length(char* str)
{
    if( *str == '\0')
        return 0;

    return 1 + length(str +1);
}

// 문자열 프린트

void printChars(char* str)
{
    if( *str == '\0')
        return ;

    printf("%c",*str);
    printChars(str+1);
}


// 문자열 역 프린트

void printReverseChars(char* str)
{
    if( *str == '\0')
        return ;

    printReverseChars(str+1);
    printf("%c",*str);

}



// 2진수 변환

void printBin(int number)
{
    if(number < 2)
        cout<<number;
    else
    {
        printBin(number/2);
        cout << number%2;
    }
}


int main()
{
    cout <<"문자열 길이 계산 " <<endl;
    cout << length("hello") <<endl;


    cout <<"문자열 프린트 " <<endl;
    printChars("hello");
    cout<<endl;

    cout <<"문자열 역 프린트 " <<endl;
    printReverseChars("hello");
    cout<<endl;

    cout <<"이진수 변환" <<endl;
    printBin(65);



    return 0;
}