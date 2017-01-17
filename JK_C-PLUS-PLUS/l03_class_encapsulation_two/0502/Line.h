#include "Coordinate.h"
class Line
{
public:
    Line(int x1=0, int y1=0, int x2=0, int y2=0);
    ~Line();
    void printInfo();
    void printInfo() const;
private:
    const Coordinate m_coorA;
    const Coordinate m_coorB;
};