#include <iostream>
#include "Line.h"
using namespace std;

int main(void)
{
    // Line *p = new Line(2, 3, 5, 8);
    Line * p = new Line();
    delete p;
    p = NULL;
    return 0;
}
