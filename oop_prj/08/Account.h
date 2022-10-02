/*
 * 파일이름: Account.h
 * 작성자: Yh Cho
 * 업데이트 정보: [2022, 10, 02] 파일버전 0.8
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
    int accID;          // 계좌번호
    int balance;        // 잔   액
    char * cusName;     // 고객이름

public:
    Account(int ID, int money, char * name);
    Account(const Account & ref);
    Account& operator = (const Account& ref);       // 대입 연산자 오버로딩 추가!

    int GetAccID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};

#endif