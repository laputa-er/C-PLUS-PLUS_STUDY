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
    TV tv;
    tv.type = 0;
    tv.changeVol();
    TV tv[20];

    return 0;
}