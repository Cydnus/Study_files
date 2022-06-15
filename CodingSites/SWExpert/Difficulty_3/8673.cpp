#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int k;
        cin>>k;
        int countOfPerson = 1;
        for(int i = 0; i<k; i++)
            countOfPerson *= 2;
        vector<int> person(countOfPerson, 0);
        for(int i = 0; i<countOfPerson; i++)
            cin>>person[i];

        vector<int> round_end;
        uint64_t sum=0;
        do{
            for(int i = 0; i< person.size(); i+=2)
            {
                if(  person[i] < person[i+1])
                {
                    round_end.push_back(person[i+1]);
                    sum += person[i+1] - person[i];
                }
                else
                {
                    round_end.push_back(person[i]);
                    sum += person[i] - person[i+1];
                }
            }
            person = round_end;
            round_end.clear();
        }while(person.size() != 1);

        cout<<"#"<<testCase<<" "<<sum<<endl;
    }
    return 0;
}
