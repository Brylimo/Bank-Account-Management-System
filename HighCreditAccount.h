#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount
{
private:
    int specialRate;

public:
    HighCreditAccount(int accID, int balance, String name, int rate, int special)
	:NormalAccount(accID, balance, name, rate), specialRate(special)
    { } 
	
    virtual void Deposit(int money)
    {
	if (money < 0)
	    throw MinusException(money);

	NormalAccount::Deposit(money);
	Account::Deposit(money*(specialRate / 100.0));
    }
};
#endif

