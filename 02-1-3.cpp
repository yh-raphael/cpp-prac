#include <iostream>
using namespace std;

void SwapPointer(int * (&pref1), int * (&pref2))    // 참조로 바꾸긴 바꾸는데 '포인터'를 바꾼다.
{
    int * temp = pref1;
    pref1 = pref2;
    pref2 = temp;
}

int main(void)
{
    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;

    cout << *ptr1 << endl;  // 5
    cout << *ptr2 << endl;  // 10

    SwapPointer(ptr1, ptr2);

    cout << *ptr1 << endl;  // 10
    cout << *ptr2 << endl;  // 5
    return 0;
}