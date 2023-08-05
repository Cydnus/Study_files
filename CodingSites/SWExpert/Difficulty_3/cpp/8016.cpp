#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    /*                              갯수    누적
        1                           1       1   = 1^2
        3   5   7                   3       4   = 2^2
        9   11  13  15  17          5       9   = 3^2
        ...

        * n번쨰 줄 까지의 수 : n^2
        * 각 줄의 끝 숫자 : 2(n^2) -1
        * 각 줄의 시작 숫자 : 2((n-1)^2) -1

        * n^2 - 2n - 1 = (n-1)^2
        ? 곱셈이 더 많은 연산 시간 차지하여 (n-1)^2 을 풀어서 계산
    */

    for (int testCase = 1; testCase <= T; testCase++)
    {
        uint64_t n;
        cin >> n;

        uint64_t nCube = n * n;
        uint64_t n_1Cube = nCube - (n + n - 1);

        uint64_t end = nCube * 2 - 1;
        uint64_t start = n_1Cube * 2 + 1;

        cout << "#" << testCase << " " << start << " " << end << endl;
    }
    return 0;
}