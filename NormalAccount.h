#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

class NormalAccount : public Account
{
private:
    int interRate;

public:
    NormalAccount(int accID, int balance, char* name, int rate)
	:Account(accID, balance, name), interRate(rate)
    { }

    virtual void Deposit(int money)
    {
	Account::Deposit(money);
	Account::Deposit(money * (interRate/100.0));	
    }
};
#endif
