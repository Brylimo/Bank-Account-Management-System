#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int accID, int balance, String name)
    :accID(accID), balance(balance)
{	
    //cusName = new char[strlen(name) + 1];
    //strcpy(cusName, name);
    cusName = name;
}

int Account::GetAccID() const
{
    return accID;
}

int Account::GetBalance() const
{
    return balance;
}

void Account::Deposit(int money)
{
    if (money<0)
	throw MinusException(money);

    balance += money;
}

int Account::Withdraw(int money)
{
    if (money<0)
	throw MinusException(money);

    if (balance < money)
	throw InsuffException(balance, money);

    balance -= money;
    return money;
}

void Account::ShowAccInfo() const
{
    cout << "계좌ID: "<<accID<<endl;
    cout << "이 름: "<<cusName<<endl;
    cout << "잔 액: "<<balance<<endl;	
}
