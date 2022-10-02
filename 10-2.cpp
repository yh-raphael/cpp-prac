#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point (int x, int y) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point operator - ()
    {
        Point pos(-xpos, -ypos);
        return pos;
    }
    friend Point operator ~ (const Point &);
};

Point operator ~ (const Point &ref)
{
    Point pos(ref.ypos, ref.xpos);
    return pos;
}

int main(void)
{
    Point pos1(9, -7);
    pos1.ShowPosition();        // [9, -7]
    Point pos2 = -pos1;
    pos2.ShowPosition();        // [-9 ,7]  그대로
    (~pos2).ShowPosition();     // [7, -9]
    pos2.ShowPosition();        // [-9, 7]  그대로

    Point pos3 = ~pos2;
    pos3.ShowPosition();        // [7, -9]
    return 0;
}