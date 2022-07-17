#include <iostream>
#include <vector>
#include <set>
#include <windows.h>

using namespace std;

int main()
{
    set<uint64_t> tri;
    set<uint64_t> penta;
    set<uint64_t> hexa;

    int isCheck = 0;
    uint64_t i = 1; 
    while(isCheck < 3)
    {
        uint64_t t = i * ( i + 1 ) / 2;
        uint64_t p = i * ( 3 * i - 1) / 2;
        uint64_t h = i * ( 2 * i -1);

        cout<< i << "\t" <<t<<"\t"<<p<<"\t"<<h<<endl;
        tri.insert(t);
        penta.insert(p);
        hexa.insert(h);

        if( penta.find(t) != penta.end() && hexa.find(t) != hexa.end() )
        {
            isCheck ++ ;
            cout<<t<<endl;
            Sleep(1000);
        }
        i++;
    }

    return 0;
}
