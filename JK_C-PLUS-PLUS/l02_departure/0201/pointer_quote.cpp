#include <iostream>
using namespace std;

int main(void)
{
    int a = 10;
    int *p = &a; // 声明指针
    int *&q = p; // 声明引用 q
    *q = 20;     // 通过引用修改 a 的值(用法和普通指针相同)

    cout << a << endl; // 20

    return 0;
}