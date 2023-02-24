#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int indexOfTarget(vector<vector<double>> score, int start, int end, int target)
{
    if( start > end)
        return -1;
    int mid = start + end;
    mid /= 2;
    if(score[mid][0] == target)
        return mid;
    
    int t = indexOfTarget(score,start,mid-1,target);
    if( t == -1)
        t = indexOfTarget(score,mid+1,end,target);
    return t;
}

int main()
{

    freopen("not_input_1983.txt", "r", stdin);

    int T;
    cin>>T;
    vector<string> coutString ={"A+","A0","A-",
                                "B+","B0","B-",
                                "C+","C0","C-",
                                "D0"};
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int cnt, target;
        cin>>cnt>>target;

        vector<vector<double>> score(cnt,vector<double>(2,0));

        for(int i = 0 ; i< cnt; i++)
        {
            int mid,fin,assig;

            cin>>mid>>fin>>assig;

            score[i][0] = i+1;
            score[i][1] = ((double) mid *0.35 + fin *0.45+assig*0.2);
        }

        sort(score.begin(), score.end(),[](vector<double> a, vector<double> b){return a[1] > b[1];});

        int ind = indexOfTarget(score,0,cnt,target);
        cnt /= 10;
        cout<<"#"<<testCase<<" "<<coutString[ind/cnt]<<endl;
    }
    return 0;
}
