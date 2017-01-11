#include <stdlib.h>
#include <iostream>

namespace A
{
    int x = 1;
    void fun()
    {
        std::cout << "A" << std::endl;
    }
}

namespace B
{
    int x = 2;
    void fun()
    {
        std::cout << "B" << std::endl;
    }
    void fun2()
    {
        std::cout << "BB" << std::endl;
    }
}

int main(void)
{
    std::cout << A::x << std::endl;
    B::fun();
    B::fun2();
    return 0;
}