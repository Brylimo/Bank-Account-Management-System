#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"
#include "AccountException.h"

class NormalAccount : public Account
{
private:
    int interRate;

public:
    NormalAccount(int accID, int balance, String name, int rate)
	:Account(accID, balance, name), interRate(rate)
    { }

    virtual void Deposit(int money)
    {
	if (money < 0)
	    throw MinusException(money);

	Account::Deposit(money);
	Account::Deposit(money * (interRate/100.0));	
    }
};
#endif
