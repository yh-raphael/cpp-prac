/*
 * Banking System Ver 0.5
 * 작성자: Yh Cho
 * 내 용: AccountHandler 라는 이름의 컨트롤 클래스 정의
 */

# include <iostream>
# include <cstring>

using namespace std;        // std::cout, std::cin, std::endl 안 써도 됨.
const int NAME_LEN = 20;    // 상수는 const int로 수정 불가능하게 지정, 매크로는 안쓰나보네.

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};


/*
 * 클래스 이름: Account
 * 클래스 유형: Entity
 * 
 */

class Account
{
private:
    int accID;          // 계좌번호
    int balance;        // 잔   액
    char * cusName;     // 고객이름

public:
    Account(int ID, int money, char * name);
    Account(const Account & ref);

    int GetAccID() const;
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;   // 값을 변경하지 않는 const 함수.
    ~Account();
};

    Account::Account(int ID, int money, char * name)
        : accID(ID), balance(money)
    {
        // cout << "배열길이: " << strlen(name) << endl;
        cout << "일반 생성자 호출" << endl;
        cusName = new char[strlen(name) + 1];
        strcpy(cusName, name);
    }

    Account::Account(const Account & ref)
        : accID(ref.accID), balance(ref.balance)
    {
        cout << "복사 생성자 호출" << endl;
        cusName = new char[strlen(ref.cusName) + 1];
        strcpy(cusName, ref.cusName);
    }

    int Account::GetAccID() const { return accID; }

    void Account::Deposit(int money)
    {
        balance += money;
    }

    int Account::Withdraw(int money)     // 출금액 반환, 부족 시 0 반환
    {
        if (balance < money)
            return 0;

        balance -= money;
        return money;
    }

    void Account::ShowAccInfo() const
    {
        cout << "계좌ID: " << accID << endl;
        cout << "이 름: "  << cusName << endl;
        cout << "잔 액: " << balance << endl;
    }

    Account::~Account()
    {
        delete []cusName;
    }


/*
 * 클래스 이름: AccountHandler
 * 클래스 유형: 컨트롤(Control) 클래스
 */

class AccountHandler
{
private:
    Account * accArr[100];      // Account 저장을 위한 배열
    int accNum;             // 저장된 Account 수
public:
    AccountHandler();
    void ShowMenu(void) const;          // 메뉴출력
    void MakeAccount(void);             // 계좌개설을 위한 함수
    void DepositMoney(void);            // 입   금
    void WithdrawMoney(void);           // 출   금
    void ShowAllAccInfo(void) const;    // 잔액조회
    ~AccountHandler();
};

AccountHandler::AccountHandler() : accNum(0)
{

}

void AccountHandler::ShowMenu(void) const
{
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount()
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

void AccountHandler::DepositMoney()
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

void AccountHandler::WithdrawMoney()
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
            if(accArr[i]->Withdraw(money) == 0)   // 돈 부족시 예외 처리
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

void AccountHandler::ShowAllAccInfo() const
{
    for (int i=0; i<accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accNum; i++)
        delete accArr[i];
};


/*
 * 컨트롤 클래스 AccountHandler 중심으로 변경된 main 함수
 */

int main(void)
{
    AccountHandler manager;     // 핸들러 객체 추가.
    int choice;

    while(1)
    {
        manager.ShowMenu();
        cout << "선택: ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrawMoney();
            break;
        case INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}
