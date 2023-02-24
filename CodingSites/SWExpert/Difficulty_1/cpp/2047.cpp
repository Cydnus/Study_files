#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    string input;
    cin>>input;
    for(char c : input)
        cout<<(char)toupper(c);
    cout<<endl;
}
