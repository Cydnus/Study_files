#include <iostream>

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;


class Student
{
    string name;
    int score;
public :
    Student(){}
    Student(string _name, int _score)
    {
        name = _name;
        score = _score;
    }

    Student(string str)
    {
        stringstream ss(str);             // stringstream에 str을 담는다.
        string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

        vector<string> result;

        while (getline(ss, buffer, '\t')) {
            result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
        }

        name = result[0];
        score = stoi(result[1]);
    }

    int get_score()
    {
        return score;
    }

    string get_name()
    {
        return name;
    }



};



void Counting_sort(vector<Student> &a , int endOfValue)
{
    int size = a.size();
    vector<Student> b = a;
    vector<int> count(endOfValue+1,0);

    for(int i = 0; i< size; i++)
        count[a[i].get_score()]++;

    for(int i = 1; i< endOfValue+1; i++)
        count[i] += count[i-1];
        
    for(int i = size-1; i>= 0 ; i--)
    {
           b[count[a[i].get_score()]-1] = a[i];
           count[a[i].get_score()] --;
    }

    a = b;

}




int main()
{
    vector<Student> array;
    ifstream fin;
    fin.open("counting_example.txt");

    if(fin.is_open())
    {
        while(!fin.eof())
        {
            string line;
            getline(fin,line);
            array.push_back(Student(line));
        }
    }
    fin.close();

    for(int i = 0; i< 10; i++)
    {
        cout.width(5);
        cout<<"이름";
        cout.width(4);
        cout<<"\t\t";
        cout.width(4);
        cout<<"성적";
        cout.width(4);
        cout<<"\t\t";
    }

    cout<<endl;

    for(int i = 0; i< array.size(); i++)
    {
        if( i!= 0 && i%10==0)
            cout<<endl;

        cout.width(8);
        cout<<array[i].get_name();
        cout.width(3);
        cout<<"\t";
        cout.width(3);
        cout<<array[i].get_score();
        cout.width(4);
        cout<<"\t\t";
    }

    cout<<endl;
    cout<<endl;
    cout<<"Counting_sort"<<endl;
    cout<<endl;
    cout<<endl;
    Counting_sort(array,100);



    for(int i = 0; i< 10; i++)
    {
        cout.width(5);
        cout<<"이름";
        cout.width(4);
        cout<<"\t\t";
        cout.width(4);
        cout<<"성적";
        cout.width(4);
        cout<<"\t\t";
    }

    cout<<endl;

    for(int i = 0; i< array.size(); i++)
    {
        if( i!= 0 && i%10==0)
            cout<<endl;

        cout.width(8);
        cout<<array[i].get_name();
        cout.width(3);
        cout<<"\t";
        cout.width(3);
        cout<<array[i].get_score();
        cout.width(4);
        cout<<"\t\t";
    }

   return 0;
}