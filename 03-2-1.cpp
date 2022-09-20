#include <iostream>

using namespace std;

class Calculator
{
private:
    int add_count;
    int sub_count;
    int mul_count;
    int div_count;

public:
    void Init();
    double Add(double, double);
    double Sub(double numA, double numB);
    double Mul(double, double);
    double Div(double, double);
    void ShowOpCount();
};

void Calculator::Init()
{
    add_count = 0;
    sub_count = 0;
    mul_count = 0;
    div_count = 0;
}

double Calculator::Add(double numA, double numB)
{
    add_count ++;
    return numA + numB;
}

double Calculator::Sub(double numA, double numB)
{
    sub_count ++;
    return numA - numB;
}

double Calculator::Mul(double numA, double numB)
{
    mul_count ++;
    return numA * numB;
}

double Calculator::Div(double numA, double numB)
{
    div_count ++;
    return numA / numB;
}

void Calculator::ShowOpCount()
{
    cout << "덧셈: " << add_count << " 뺄셈: " << sub_count << " 곱셈: " << mul_count << " 나눗셈: " << div_count << endl;
}

int main(void)
{
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Sub(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();
    return 0;
}