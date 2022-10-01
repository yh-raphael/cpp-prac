/*
 * 파일이름: Account.h
 * 작성자: Yh Cho
 * 업데이트 정보: [2010, 01, 01] 파일버전 0.7
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

    int GetAccID() const;
    virtual void Deposit(int money);            // virtual 추가!!
    int Withdraw(int money);
    void ShowAccInfo() const;   // 값을 변경하지 않는 const 함수.
    ~Account();
};

#endif