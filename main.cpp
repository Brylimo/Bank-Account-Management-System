#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN=20;

void ShowMenu(void);	    // 메뉴출력
void MakeAccount(void);	    // 계좌개설을 위한 함수
void DepositMoney(void);    // 입금
void WithdrawMoney(void);   // 출금
void ShowAllAccInfo(void);  // 잔액조회

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

enum {LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};

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

    Account::Account(int accID, int balance, char* name)
    :accID(accID), balance(balance)
    {	
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
    }
    
    Account::Account(const Account &ref)
    :accID(ref.accID), balance(ref.balance)
    {
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
    }

    int Account::GetAccID() const
    {
	return accID;
    }

    int Account::GetBalance() const
    {
	return balance;
    }

    char* Account::GetCusName() const
    {
	return cusName;
    }

    void Account::Deposit(int money)
    {
	balance += money;
    }

    int Account::Withdraw(int money)
    {
	if (balance < money)
	    return 0;
	else
	    balance -= money;
	    return money;
    }

    void Account::ShowAccInfo() const
    {
	cout << "계좌ID: "<<accID<<endl;
	cout << "이 름: "<<cusName<<endl;
	cout << "잔 액: "<<balance<<endl;	
    }

    Account::~Account()
    {
	delete []cusName;
    }

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

class HighCreditAccount : public NormalAccount
{
    private:
	int specialRate;

    public:
	HighCreditAccount(int accID, int balance, char* name, int rate, int special)
	    :NormalAccount(accID, balance, name, rate), specialRate(special)
	{ } 
	
	virtual void Deposit(int money)
	{
	    NormalAccount::Deposit(money);
	    Account::Deposit(money*(specialRate / 100.0));
	}

};

class AccountHandler
{
private:
    Account* accArr[100]; // Account 저장을 위한 배열
    int accNum;	  //저장된 Account 수

public:
   AccountHandler();

   void ShowMenu() const;
   void MakeAccount();
   void DepositMoney();
   void WithdrawMoney();
   void ShowAllAccInfo() const;
   ~AccountHandler();        

protected:
   void MakeNormalAccount(void);
   void MakeCreditAccount(void);
};

AccountHandler::AccountHandler():accNum(0) {}
    
void AccountHandler::ShowMenu(void) const
{
    cout << "-----Menu------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;  
}

void AccountHandler::MakeAccount(void)
{    
    int choice;
    cout << "[계좌종류선택]" << endl;
    cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
    cout << "선택: "; cin >> choice;
    
    switch(choice)
    {
	case 1:
	    MakeNormalAccount();
	    break;
	
	case 2:
	    MakeCreditAccount();
	    break;
    }	
}

void AccountHandler::DepositMoney(void)
{
    int money, id;

    cout << "[입    금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "입금액: "; cin >> money;

    for (int i; i < accNum; i++)
    {
	if (accArr[i]->GetAccID() == id)
	{
	    accArr[i]->Deposit(money);
	    cout << "입금완료" <<endl<<endl;
	    return;
	}
    }
    cout << "유효하지 않은 ID 입니다." << endl<<endl;
}

void AccountHandler::WithdrawMoney(void)
{   
    int money, id;

    cout << "[출    금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "출금액: "; cin >> money;

    for (int i; i < accNum; i++)
    {
	if (accArr[i]->GetAccID() == id)
	{
	    if (accArr[i]->Withdraw(money) == 0)
	    {
		cout<<"잔액부족"<<endl<<endl;
		return;
	    }

	    cout << "출금완료" <<endl<<endl;
	    return;
	}
    }
    cout << "유효하지 않은 ID 입니다." << endl<<endl;
}

void AccountHandler::ShowAllAccInfo(void) const
{
   for (int i = 0; i < accNum; i++)
   {
   	accArr[i]->ShowAccInfo();
	cout<<endl;
   }
}

AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accNum; i++)
	delete accArr[i];
}

void AccountHandler::MakeNormalAccount(void)
{
    int id, balance, rate;
    char name[NAME_LEN];

    cout << "[보통예금계좌 개설]" << endl;
    cout << "계좌ID: ";	cin >> id;
    cout << "이 름: ";	cin >> name;
    cout << "입금액: ";	cin >> balance;
    cout << "이자율: ";	cin >> rate;
    cout << endl;

    accArr[accNum++] = new NormalAccount(id, balance, name, rate);
}

void AccountHandler::MakeCreditAccount(void)
{
    int id, balance, rate, creditLevel;
    char name[NAME_LEN];

    cout << "[신용신뢰계좌 개설]" << endl;
    cout << "계좌ID: ";	cin >> id;
    cout << "이 름: ";	cin >> name;
    cout << "입금액: ";	cin >> balance;
    cout << "이자율: ";	cin >> rate;
    cout << "신용등급(1toA, 2toB, 3toC): "; cin >> creditLevel;
    cout << endl;

    switch(creditLevel)
    {
	case 1:
	    accArr[accNum++] = new HighCreditAccount(id, balance, name, rate, LEVEL_A);
	    break;
	case 2:
	    accArr[accNum++] = new HighCreditAccount(id, balance, name, rate, LEVEL_B);
	    break;
	case 3:
	    accArr[accNum++] = new HighCreditAccount(id, balance, name, rate, LEVEL_C);
	    break;
    }

}

int main(void)
{
    int choice;
    AccountHandler manager;

    while(true)
    {
	manager.ShowMenu();
	cout << "선택: "; cin >> choice;
	cout << endl;

	switch(choice)
	{
	    case MAKE:
		manager.MakeAccount();
		break;

	    case DEPOSIT:
		manager.DepositMoney();
		break;

	    case WITHDRAW:
		manager.WithdrawMoney();
		break;

	    case INQUIRE:
		manager.ShowAllAccInfo();
		break;

	    case EXIT:
		return 0;

	    default:
		cout << "Illegal Selection.." << endl;
	}	    
    }


    return 0;
}
