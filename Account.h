#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
    int accID;	    // 계좌번호
    int balance;    // 잔액
    char* cusName;  // 고객이름

public:
    Account(int accID, int balance, char* name);    
    Account(const Account &ref);

    int GetAccID() const;
    int GetBalance() const;
    char* GetCusName() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};
#endif
