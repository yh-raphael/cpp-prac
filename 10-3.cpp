#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    friend ostream& operator << (ostream& os, const Point& pos);
    friend istream& operator >> (istream& os, Point& pos);
};

ostream& operator << (ostream& os, const Point & pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

istream& operator >> (istream& is, Point & pos)
{
    is >> pos.xpos >> pos.ypos;
    return is;
}

int main(void)
{
    Point pos1;
    cout << "x, y 좌표 순으로 입력: ";
    cin >> pos1;
    cout << pos1;

    Point pos2;
    Point pos3;
    cout << "x, y 좌표 순으로 입력: ";
    cin >> pos2 >> pos3;
    cout << pos2 << pos3;

    return 0;
}