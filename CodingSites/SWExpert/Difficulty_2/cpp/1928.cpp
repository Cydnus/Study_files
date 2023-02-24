#include <iostream>
#include <vector>
#include <string>

#include <map>

using namespace std;

int main()
{
    int testNo;
    cin>>testNo;

    map<char, int> decoding ={
        {'A', 0},  {'B', 1},  {'C', 2},  {'D', 3},  {'E', 4},     {'F', 5},  {'G', 6},  {'H', 7},  {'I', 8},  {'J', 9}, 
        {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14},    {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, 
        {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24},    {'Z', 25}, {'a', 26}, {'b', 27}, {'c', 28}, {'d', 29}, 
        {'e', 30}, {'f', 31}, {'g', 32}, {'h', 33}, {'i', 34},    {'j', 35}, {'k', 36}, {'l', 37}, {'m', 38}, {'n', 39}, 
        {'o', 40}, {'p', 41}, {'q', 42}, {'r', 43}, {'s', 44},    {'t', 45}, {'u', 46}, {'v', 47}, {'w', 48}, {'x', 49}, 
        {'y', 50}, {'z', 51}, {'0', 52}, {'1', 53}, {'2', 54},    {'3', 55}, {'4', 56}, {'5', 57}, {'6', 58}, {'7', 59}, 
        {'8', 60}, {'9', 61}, {'+', 62}, {'/', 63}
    };

    for (int testCase = 1; testCase <= testNo; testCase++)
    {
        string str;
        cin>>str;
        cout<<"#"<<testCase<<" ";

        for(int i = 0; i<str.size(); i+=4)
        {
            uint32_t dec = 0;
            for(int j =0; j<4;j++)
            {
                dec = dec<<6;
                dec |= decoding[str[i+j]];
            }

            string str2 = "";
            while( dec != 0x00)
            {
                str2 = (char)(dec & 0xff) + str2;
                dec = dec >> 8;
            }
            cout<<str2;
        }
        cout<<endl;
            }
}
