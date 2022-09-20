#include <iostream>

int main(void)
{
    int n = 0;
    while (1)
    {
        std::cout << "판매 금액을 만 원 단위로 입력 (-1 to end): ";
        std::cin >> n;

        if (n == -1){
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;
        }

        std:: cout << "이번 달 급여: ";
        std:: cout << 50 + n*0.12 << std::endl;
    }
    return 0;
}