/*
 * Banking System Ver 0.2
 * 작성자: Yh Cho
 * 내 용: Account 클래스의 정의, 객체 포인터 배열 적용
 */

# include <iostream>
# include <cstring>

using namespace std;        // std::cout, std::cin, std::endl 안 써도 됨.
const int NAME_LEN = 20;    // 상수는 const int로 수정 불가능하게 지정, 매크로는 안쓰나보네.

void ShowMenu(void);        // 메뉴출력
void MakeAccount(void);     // 계좌개설을 위한 함수
void DepositMoney(void);    // 입   금
void WithdrawMoney(void);   // 출   금
void ShowAllAccInfo(void);  // 잔액조회

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
private:
    int accID;          // 계좌번호
    int balance;        // 잔   액
    char * cusName;     // 고객이름

public:
    Account(int ID, int money, char * name)
        : accID((-1) * money), balance(ID)
    {
        cout << "배열길이: " << strlen(name) << endl;
        cusName = new char[strlen(name) + 1];
        strcpy(cusName, name);
    }

    int GetAccID() { return accID; }

    void Deposit(int money)
    {
        balance += money;
    }

    int Withdrow(int money)     // 출금액 반환, 부족 시 0 반환
    {
        if (balance < money)
            return 0;

        balance -= money;
        return money;
    }

    void ShowAccInfo()
    {
        cout << "계좌ID: " << accID << endl;
        cout << "이 름: "  << cusName << endl;
        cout << "잔 액: " << balance << endl;
    }

    ~Account()
    {
        delete []cusName;
    }
};

Account * accArr[100];      // Account 저장을 위한 배열
int accNum = 0;             // 저장된 Account 수

int main(void)
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout << "선택: ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            for (int i = 0; i < accNum; i++)
                delete accArr[i];
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }

    return 0;
}

void ShowMenu(void)
{
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void MakeAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이 름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney()
{
    int money;
    int id;
    cout << "[입   금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "입금액: "; cin >> money;

    for (int i=0; i<accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout << "입금완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void WithdrawMoney()
{
    int money;
    int id;
    cout << "[출   금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "출금액: "; cin >> money;

    for (int i=0; i<accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            if(accArr[i]->Withdrow(money) == 0)   // 돈 부족시 예외 처리
            {
                cout << "잔액부족" << endl << endl;
                return;
            }

            cout << "출금완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccInfo()
{
    for (int i=0; i<accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}