#include <iostream>
#include <stdlib.h>
using namespace std;

// 通过声明 const 引用，明确限制对原数据的修改
void fun(const int &a, const int &b);

int main(void)
{
    int x = 3;
    int y = 5;

    /* 指针本身为只读 */
    int * const p = &x;
    *p = 10;
    cout << x << ", " << y << endl; // 10, 5
    // p = &y;(错误)
    
    /* 引用只读 */
    int const &z = y;
    // z = 10;(错误)

    /* 在函数中的应用 */
    fun(x, y);
    
    return 0;
}

void fun(const int &a, const int &b)
{
    // a = 10;(错误)
    // b = 20;(错误)
}
