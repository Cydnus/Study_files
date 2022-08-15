#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("not_input_7088.txt","r",stdin);
    freopen("not_output_7088.txt","w",stdout);

    int T;
    scanf("%d", &T);
    
    //int cow[100000][3];

    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int n, q;
        scanf("%d %d", &n, &q);
        vector<vector<int>> cow(n+1,vector<int>(3,0));
        for(int i =1 ; i<=n; i++)
        {
            cow[i][0] = cow[i-1][0];
            cow[i][1] = cow[i-1][1];
            cow[i][2] = cow[i-1][2];
            int a ;
            scanf("%d",&a);
            cow[i][a-1]++;
        }

        printf("#%d\n", testCase);
        for(int i = 0 ; i<q; i++)
        {
            int s,e;
            scanf("%d %d", &s, &e);
            int cnt[3]={0,};
            cnt[0] = cow[e][0] - cow[s][0];
            cnt[1] = cow[e][1] - cow[s][1];
            cnt[2] = cow[e][2] - cow[s][2];

            printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);
        }

    }
    
    return 0;
}
