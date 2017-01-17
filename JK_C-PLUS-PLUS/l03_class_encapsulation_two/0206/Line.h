#include "Coordinate.h"
class Line
{
public:
    Line(int x1=0, int y1=0, int x2=0, int y2=0);
    ~Line();
    void setA(int x, int y);
    void setB(int x, int y);
    void printInfo();
private:
    Coordinate m_coorA;
    Coordinate m_coorB;
};