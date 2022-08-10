#include <iostream>
#include <map>
#include <string>

#define     MAX_CRYP_SIZE   8
#define     MAX_HASH_STRING_SIZE    7

using namespace std;


map<string,int> hashmap = {
    {"0001101", 0},  {"0011001", 1},  {"0010011", 2},  {"0111101", 3},  {"0100011", 4},
    {"0110001", 5},  {"0101111", 6},  {"0111011", 7},  {"0110111", 8},  {"0001011", 9}
    };

int checksum(int num[])
{
    int sum = 0;
    for(int i = 0 ; i<MAX_CRYP_SIZE; i++)
    {
        if( i%2 == 0)
            sum += num[i]*3;
        else
            sum+= num[i];
    }
    int ret = 0;
    if(sum %10 == 0)
    {
        for(int i = 0; i<MAX_CRYP_SIZE; i++)
            ret += num[i];
    }
    return ret;
}

int encrypt(string str)
{
    string cryp[MAX_CRYP_SIZE]={"",};
    int cryp_num[MAX_CRYP_SIZE]={0,};

    bool check_one = false;

    for(int i = str.size()-1; i>=0 ; i--)
    {
        if( str[i] == '1')
        {
            check_one = true;
            for(int j = MAX_CRYP_SIZE-1; j>=0; j--)
            {
                for(int k = 0; k<MAX_HASH_STRING_SIZE; k++)
                {
                    cryp[j] = str[i]+cryp[j];
                    i--;
                }
            }
            break;
        }
    }

    for(int i = 0 ; i<MAX_CRYP_SIZE && check_one; i++)
    {
        cryp_num[i] = hashmap[cryp[i]];
    }

    if( check_one)
        return checksum(cryp_num);
    else
        return 0;
}



int main()
{
    freopen("not_input_1240.txt","r",stdin);
    int T;
    cin>>T;
    

    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n,m;
        cin>>n>>m;

        int num = 0;
        int i = 0;
        for( i = 0 ; i<n && num == 0; i++)
        {
            string str;
            cin>>str;
            num = encrypt(str);
        }

        cout<<"#"<<testCase<<" "<<num<<endl;

        string temp ="";
        while(i < n)   
        {
            cin>>temp;
            i++;
        }
            

    }
    return 0;
}
