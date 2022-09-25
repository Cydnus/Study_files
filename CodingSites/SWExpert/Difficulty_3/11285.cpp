#include <iostream>

#define DIST(x,y)   ( ((x)*(x)) + ((y)*(y)) )

using namespace std;

int circle_dist[]={400,1600,3600,6400,10000,14400,19600,25600,32400,40000};

int scores[] = {10,9,8,7,6,5,4,3,2,1};

int getScore()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int dist = DIST(x,y);
    
    for(int j =0 ; j<10; j++)
    {
        if(dist <= circle_dist[j])
        {
            return scores[j];
        }
    }
    return 0;

}


int main()
{
    int T;
    scanf("%d", &T);
    

    for(int testCase = 1; testCase<=T; testCase ++)
    {
        //Write Your Code
        // r = 20 * (11-p)
        // r/20 = 11-p
        // p = 11-r/20

        int n;
        scanf("%d", &n);

        int score = 0;

        for(int i = 0 ; i<n ; i++)
        {
            score+=getScore();
        }
        printf("#%d %d\n", testCase, score);
    }
    return 0;
}
                                            