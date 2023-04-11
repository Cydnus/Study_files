#include <iostream>
#include <vector>
#include <string>

using namespace std;

int check[10];

void init()
{
    for (int i = 0; i < 10; i++)
        check[i] = 0;
}

void YesInCome(int inp[4], int row)
{
    for (int i = 0; i < 4; i++)
        if (check[inp[i]] != -1)
            check[inp[i]] = row;

    for (int i = 0; i < 10; i++)
        if (check[i] != row)
            check[i] = -1;
}

int indexOfNumber()
{
    for (int i = 0; i < 10; i++)
    {
        if (check[i] != -1)
            return i;
    }
    return 0;
}

int main()
{
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();

        int n;
        cin >> n;
        
        for (int run = 0; run < n; run++)
        {
            int inp[4];
            string isincl;

            for (int i = 0; i < 4; i++)
                cin >> inp[i];
            cin >> isincl;

            if (isincl == "NO" || isincl == "no" || isincl =="No")
                for (int i = 0; i < 4; i++)
                    check[inp[i]] = -1;
            else
                YesInCome(inp, run+1);

        }

        cout << "#" << testCase << " " << indexOfNumber() << endl;
    }
    return 0;
}