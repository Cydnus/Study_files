#include <iostream>
#include <vector>
#include <cmath>

#define CUBE(x)     ((x)*(x))

using namespace std;

int solution(int p, int x, int y)
{
    x -= 50;
    y -= 50;

    if( CUBE(x) + CUBE(y) > CUBE(50))
    {
        return 0;
    }

    double angle = ((double)p/100) * 360;

    // 90도 회전(시계방향)
    // x = x * cos(-90) - y * sin(-90) / y= y * cons(-90) +x*sin(-90)
    // sin(-90) = -1 , cos(-90) = 0
    // x 축 기준으로 반전
    int temp = x;
    x = y;
    y = temp;
    double result = atan2( y,x) *180.0 / 3.14159265;
    if( result < 0)
        result += 360;
    if( result < angle)
        return 1;
    return 0;
}




int main()
{
    int T;
    cin>>T;
    
    for(int testCase = 1; testCase<=T; testCase ++)
    {
        int p, x,y;
        cin>>p>>x>>y;

        cout<<"#"<<testCase<<" "<<solution(p,x,y)<<endl;

    }
    return 0;
}
