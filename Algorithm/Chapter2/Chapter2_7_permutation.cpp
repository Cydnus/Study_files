#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Permutation
{
private:
    vector<char> data;
    int size;


    void swap(int a, int b)
    {
        char temp = data[a];
        data[a] = data[b];
        data[b] = temp;
    }

public:

    Permutation(string str)
    {
        for(char ch : str)
        {
            data.push_back(ch);
        }

        size = data.size();
    }

    vector<string> AllPermutation(int k=0)
    {
        vector<string> ret;
        if(k == size)
        {
            string temp = "";
            for(int i = 0 ; i< size ; i++)
            {
                temp += data[i];
                temp += " ";
            }
            ret.push_back(temp);

            return ret;
        }

        for(int i = k ; i < size; i ++)
        {
            swap(k,i);
            vector<string> ret1 = AllPermutation(k+1);
            swap(k,i);
            ret.insert(ret.end(),ret1.begin(), ret1.end());
        }
        return ret;


    }



};


int main()
{

    Permutation perm("abcd");

    vector<string> temp = perm.AllPermutation();

    for(string item: temp)
    {
        cout<<item<<endl;
    }

    return 0;
}