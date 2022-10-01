/*
 * 파일이름: BankingCommonDecl.h
 * 작성자: Yh Cho
 * 업데이트 정보: [2010, 01, 01] 파일버전 0.7
 */

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>

using namespace std;        // std::cout, std::cin, std::endl 안 써도 됨.
const int NAME_LEN = 20;    // 상수는 const int로 수정 불가능하게 지정, 매크로는 안쓰나보네.

// 프로그램 사용자의 선택 메뉴
enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

// 신용등급
enum {LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};

// 계좌의 종류
enum {NORMAL=1, CREDIT=2};

#endif