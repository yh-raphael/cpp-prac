/*
 * 파일이름: AccountArray.h
 * 작성자: Yh Cho
 * 업데이트 정보: [2022, 10, 02] 파일버전 0.1
 */

#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"
typedef Account * ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
    ACCOUNT_PTR * arr;
    int arrlen;

    BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) { }
    BoundCheckAccountPtrArray& operator = (const BoundCheckAccountPtrArray& arr) { }

public:
    BoundCheckAccountPtrArray(int len = 100);
    ACCOUNT_PTR& operator[] (int idx);
    ACCOUNT_PTR operator[] (int idx) const;
    
    int GetArrLen() const;
    ~BoundCheckAccountPtrArray();
};

#endif