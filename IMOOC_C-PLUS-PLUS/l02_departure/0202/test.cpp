#include <iostream>
#include <stdlib.h>

using namespace std;
typedef struc
{
    int x;
    int y;
} Coor;

int main(void)
{
    int a = 10;
    int &b = a;

    b = 20;
    cout << "a = " << a << endl;

    a = 30;
    cout << "a = " << a << endl;
    return 0;
}