/*
 * 파일이름: Account.h
 * 작성자: Yh Cho
 * 업데이트 정보: [2022, 10, 10] 파일버전 0.9
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account
{
private:
    int accID;          // 계좌번호
    int balance;        // 잔   액
    String cusName;     // 고객이름

public:
    Account(int ID, int money, String name);

    int GetAccID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
};

#endif