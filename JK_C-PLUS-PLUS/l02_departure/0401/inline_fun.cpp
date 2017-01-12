#include <iostream>
using namespace std;
inline int max(int a, int b, int c);

int main(void)
{
    int i = 10, j = 20, k = 30, m;
    m = max(i, j, k);
    cout << "max=" << m << endl;

    return 0;
}

inline int max(int a, int b, int c)
{
    if(b > a) a = b;
    if(c > a) a = c;
    return a;
}