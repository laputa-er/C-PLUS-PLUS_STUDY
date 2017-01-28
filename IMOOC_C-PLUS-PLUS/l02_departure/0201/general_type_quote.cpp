#include <iostream>
using namespace std;

int main(void) {
    int a = 3;
    int &b = a; // 引用声明时必须初始化(类似 const)

    b = 10;
    cout << a << endl; // 10
    return 0;
}