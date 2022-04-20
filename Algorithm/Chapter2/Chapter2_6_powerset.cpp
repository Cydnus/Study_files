#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Powerset
{
private:
    vector<bool> include;
    vector<char> datas;
    int size;
public:

    Powerset(vector<char> data)
    {
        datas = data;
        size = datas.size();
        include = vector<bool>(size,true) ;
    }
    Powerset(string data)
    {
        for(char ch : data)
        {
            datas.push_back(ch);
        }
        size = datas.size();
        include = vector<bool>(size,true) ;
    }

    vector<string> CalculatePowerSet(int k=0)
    {
        if( k == size)
        {
            vector<string> ret_vec;
            string ret_str="";//"{";

            for(int i = 0; i< size; i++)
            {
                if(include[i])
                {
                   ret_str += ", ";
                    ret_str += datas[i];
                }
            }

            if(ret_str.size() == 0)
                ret_str+="{ }";
            else{
                ret_str[0] = '{';
                ret_str += " }";
            }

            ret_vec.push_back(ret_str);
            return ret_vec;
        }

        include[k] = false;
        vector<string> r1 = CalculatePowerSet(k+1);
        include[k] = true;
        vector<string> r2 = CalculatePowerSet(k+1);

        r1.insert(r1.end(), r2.begin(), r2.end());
        return r1;
    }

/*
    void CalculatePowerSet(int k=0)
    {
        if( k == size)
        {
            for(int i = 0; i< size; i++)
                cout<<include[i]<<"\t";
            cout<<endl;
            for(int i = 0; i< size; i++)
                if(include[i]==1)
                    cout<< datas[i]<<" ";
            cout<<endl;
            return;
        }

        include[k] = false;
        CalculatePowerSet(k+1);
        include[k] = true;
        CalculatePowerSet(k+1);

    }
    */

    void display()
    {
         for(char str : datas)
         {
             cout<<str<<"\t";
         }
         cout<<endl;

        vector<string> cal = CalculatePowerSet();
         for(string str : cal)
         {
             cout<<str<<endl;
         }

        /*

        CalculatePowerSet();

        */
    }

};




int main()
{

    Powerset ps("abcd");

    ps.display();
    
    cout<<endl;
    cout<<endl;
    
    ps = Powerset("abcdefghijklmnop");
    ps.display();
    
    

    return 0;
}