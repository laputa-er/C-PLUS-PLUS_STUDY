#include <iostream>
#include <stdlib.h>

using namespace std;
int main(void)
{
    int *p = new int[1000];
    if(NULL == p)
    {
        return 1;
    }
    p[0] = 10;
    p[1] = 20;
    cout << p[0] << ", " << p[1] <<endl;
    
    delete []p; // 如果漏掉了 []， 只会释放内存块的第一个单元，导致内存泄漏
    p = NULL;

    return 0;
}