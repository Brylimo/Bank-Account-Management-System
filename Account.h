#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account
{
private:
    int accID;	    // 계좌번호
    int balance;    // 잔액
    String cusName;  // 고객이름

public:
    Account(int accID, int balance, String name);    
    // Account(const Account &ref);
    // Account& operator=(const Account& ref); #깊은 복사가 필요없음.

    int GetAccID() const;
    int GetBalance() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    // ~Account();
};
#endif
