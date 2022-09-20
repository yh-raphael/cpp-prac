#include <iostream>
using namespace std;

void incrementOne(int & ptr);
void changeSign(int & ptr);

int main(void)
{
    int num = 5;
    incrementOne(num);
    cout << num << endl;            // 6
    changeSign(num);
    cout << num << endl;            // -6
    return 0;
}

void incrementOne(int & ptr)
{
    ptr = ptr + 1;
}

void changeSign(int & ptr)
{
    ptr = (-1) * (ptr);
}