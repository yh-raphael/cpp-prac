#include <iostream>
#include <cstring>

using namespace std;

class Printer
{
private:
    char* in_str;
    // char in_str[100];

public:
    void SetString(char* );
    void ShowString();
};

void Printer::SetString(char* str)
{
    in_str = str;
    // strcpy(in_str, str);
}

void Printer::ShowString()
{
    cout << in_str << endl;
}

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}