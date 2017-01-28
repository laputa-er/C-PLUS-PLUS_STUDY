#include <iostream>
#include "Line.h"
using namespace std;

int main(void)
{
    Line * p = new Line(1, 2, 3, 4);
    delete p;
    p = NULL;
    return 0;
}
