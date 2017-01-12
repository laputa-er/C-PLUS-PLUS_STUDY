#include <iostream>
using namespace std;

// 交换两个整数的值（有副作用）
void swap(int *a, int *b)
{
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
}

int main(void)
{
 int x = 10, y = 20;
 swap(&x, &y);

 cout << "x = " << x << ", " << "y = " << y << endl; // x = 20, y = 10
}