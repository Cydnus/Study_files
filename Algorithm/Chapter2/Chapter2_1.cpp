#include <iostream>

using namespace std;

//Recursive

// ���ڿ� ���� ���

int length(char* str)
{
    if( *str == '\0')
        return 0;

    return 1 + length(str +1);
}

// ���ڿ� ����Ʈ

void printChars(char* str)
{
    if( *str == '\0')
        return ;

    printf("%c",*str);
    printChars(str+1);
}


// ���ڿ� �� ����Ʈ

void printReverseChars(char* str)
{
    if( *str == '\0')
        return ;

    printReverseChars(str+1);
    printf("%c",*str);

}



// 2���� ��ȯ

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
    cout <<"���ڿ� ���� ��� " <<endl;
    cout << length("hello") <<endl;


    cout <<"���ڿ� ����Ʈ " <<endl;
    printChars("hello");
    cout<<endl;

    cout <<"���ڿ� �� ����Ʈ " <<endl;
    printReverseChars("hello");
    cout<<endl;

    cout <<"������ ��ȯ" <<endl;
    printBin(65);



    return 0;
}