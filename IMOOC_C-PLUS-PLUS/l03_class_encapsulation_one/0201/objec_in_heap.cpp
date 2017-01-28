#include <iostream>
using namespace std;

class TV
{
public:
    char name[20];
    int type;

    void changeVol;
    void power();
}

int main(void)
{
    TV *p = new TV();
    TV *q = new TV[20];

    p -> type = 0;
    p -> changeVol();
    delete p;
    delete []q;
    p = NULL;
    q = NULL;
    
    return 0;
}