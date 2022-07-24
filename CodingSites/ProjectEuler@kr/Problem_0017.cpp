#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> alpha = {"",
                        "one",  "two",  "three",    "four", "five",
                        "six",  "seven",    "eight",  "nine", "ten",
                        "eleven", "twelve", "thirteen", "", "fifteen",
                        "", "", "eighteen", "" };
    vector<string> ten_alpha = {"", "teen", "twenty", "thirty", "forty", 
                                "fifty", "sixty", "seventy", "eighty", "ninety"};
    string hund = "hundred";
    string thou = "thousand";
    

    int cnt = 0;

    for(int i = 1; i<=1000; i++)
    {
        string str = "";
        
        int temp = i / 100;
        if (temp != 0)
        {
            if(temp == 10)
            {
                str += alpha[1];
                str += thou;
            }
            else
            {
                str += alpha[temp];
                str += hund;
            }
        }

        if( temp != 0 && i%100 != 0)
            str += "and";

        temp = i % 100;
        if( temp == 10 || temp == 11 || temp == 12 || temp == 13 || temp == 15 || temp == 18)
        {
            str += alpha[temp];
        }
        else
        {
            if( temp < 20)
            {
                str += alpha[temp%10];
                str += ten_alpha[temp/10];
            }
            else
            {
                str += ten_alpha[temp/10];
                str += alpha[temp%10];
            }
        }
        cnt += str.size();
        cout<< str<<endl;

    }
    cout<<cnt<<endl;

    return 0;
}
