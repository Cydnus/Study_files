#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int numOfHorn, numOfAnimal;
        cin>> numOfHorn>>numOfAnimal;
        int twin = numOfHorn - numOfAnimal;
        int uni = numOfAnimal - twin;
        cout<<"#"<<testCase<<" "<<uni<<" "<<twin<<endl;
    }
    return 0;
}
