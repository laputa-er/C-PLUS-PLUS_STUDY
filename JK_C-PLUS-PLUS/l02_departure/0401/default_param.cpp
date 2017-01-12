#include <iostream>
using namespace std;
void fun(int i, int j = 0, int k = 0);

int main(void)
{
    fun(20); // 20, 0, 0
    fun(20, 30); // 20, 30, 0
    fun(20, 30, 40); // 20, 30, 40

    return 0;
}

void fun(int i, int j, int k)
{
    cout << i <<", " << j << ", " << k << endl;
}