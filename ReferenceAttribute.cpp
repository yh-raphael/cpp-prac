#include <iostream>
using namespace std;

class First
{
public:
    void FirstFunc()
    {
        cout << "FirstFunc()" << endl;
    }
    void SimpleFunc()
    {
        cout << "First's SimpleFunc()" << endl;
    }
};

class Second : public First         // inherit!
{
public:
    void SecondFunc()
    {
        cout << "SecondFunc()" << endl;
    }
    void SimpleFunc()
    {
        cout << "Second's SimpleFunc()" << endl;
    }
};

class Third : public Second         // inherit!
{
public:
    void ThirdFunc()
    {
        cout << "ThirdFunc()" << endl;
    }
    void SimpleFunc()
    {
        cout << "Third's SimpleFunc()" << endl;
    }
};

int main(void)
{
    Third obj;
    obj.FirstFunc();
    obj.SecondFunc();
    obj.ThirdFunc();
    obj.SimpleFunc();

    Second & sref = obj;
    sref.FirstFunc();
    sref.SecondFunc();
    sref.SimpleFunc();

    First & fref = obj;
    fref.FirstFunc();
    fref.SimpleFunc();

    return 0;
}