# include <iostream>

int main(void)
{
    int n1, n2, n3, n4, n5;

    std::cout << "1번째 정수 입력: ";
    std::cin >> n1;

    std::cout << "2번째 정수 입력: ";
    std::cin >> n2;

    std::cout << "3번째 정수 입력: ";
    std::cin >> n3;

    std::cout << "4번째 정수 입력: ";
    std::cin >> n4;

    std::cout << "5번째 정수 입력: ";
    std::cin >> n5;

    std::cout << "합계: " << n1+n2+n3+n4+n5 << std::endl;
}