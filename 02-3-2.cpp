# include <iostream>

using std::cout; using std::cin;
using std::endl;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point* const p1, const Point* const p2)
{
    Point* CC = new Point;
    CC->xpos = p1->xpos + p2->xpos;
    CC->ypos = p1->ypos + p2->ypos;
    return *CC;
}

int main(void)
{
    Point* A = new Point;
    Point* B = new Point;

    A->xpos = 1, A->ypos = 2;
    B->xpos = 3, B->ypos = 4;

    Point& C = PntAdder(A, B);

    cout << "[" << C.xpos << ", " << C.ypos << ']' << endl;

    delete A;
    delete B;
    delete &C;

    return 0;
}