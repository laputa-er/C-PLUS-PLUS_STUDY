#include <iostream>
#include <stdlib.h>

class Coordinate
{
public:
    int x;
    int y;
    void printX()
    {
        cout << x << endl;
    }
    void printY()
    {
        cout << y << endl;
    }
}

int main(void)
{
    Coorinate coor;
    coor.x = 10;
    coor.y = 20;
    coor.printX();
    coor.printY();

    Coordinate *p = new Coorinate();
    if(NULL == 0)
    {
        return 1;
    }
    p -> x = 100;
    p -> y = 200;
    p -> printX();
    p -> printY();

    delete p;
    p = NULL;
    
    return 0;
}