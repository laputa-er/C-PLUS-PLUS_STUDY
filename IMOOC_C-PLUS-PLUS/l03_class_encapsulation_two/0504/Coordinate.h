class Coordinate
{
public:
    Coordinate(int x=0, int y=0);
    ~Coordinate();
    int getX();
    int getY();
    void printInfo() const;
private:
    int m_iX;
    int m_iY;
};