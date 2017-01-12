#include <iostream>
using namespace std;

// 坐标
typedef struct
{
    int x;
    int y;
} Coor;

int main(void)
{
    Coor c1;
    // 声明引用
    Coor &c = c1;

    // 通过引用操作结构体实例
    c.x = 10;
    c.y = 20;

    // 直接访问结构体本身实例
    cout << c1.x << ", " << c1.y << endl; // 10, 20

    return 0;
}