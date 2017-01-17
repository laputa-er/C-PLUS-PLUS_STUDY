class Coordinate
{
public:
    Coordinate(int x=0, int y=0);
    ~Coordinate();
    void setX(int x);
    int getX() const;
    int getX();
    void setY(int y);
    int getY() const;
    int getY();
private:
    int m_iX;
    int m_iY;
};