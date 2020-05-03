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

class Account
{
private:
    int accID;	    // 계좌번호
    int balance;    // 잔액
    char* cusName;  // 고객이름

public:
    Account(int accID, int balance, char* name)
    :accID(accID), balance(balance)
    {	
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
    }
    
    Account(const Account &ref)
    :accID(ref.accID), balance(ref.balance)
    {
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
    }
    int GetAccID() const
    {
	return accID;
    }

    int GetBalance() const
    {
	return balance;
    }

    char* GetCusName() const
    {
	return cusName;
    }

    void Deposit(int money)
    {
	balance += money;
    }

    int Withdraw(int money)
    {
	if (balance < money)
	    return 0;
	else
	    balance -= money;
	    return money;
    }

    void ShowAccInfo() const
    {
	cout << "계좌ID: "<<accID<<endl;
	cout << "이 름: "<<cusName<<endl;
	cout << "잔 액: "<<balance<<endl;	
    }

    ~Account()
    {
	delete []cusName;
    }
};

Account* accArr[100];	// Account 저장을 위한 배열
int accNum = 0;		//저장된 Account 수

int main(void)
{
    int choice;

    while(true)
    {
	ShowMenu();
	cout << "선택: "; cin >> choice;
	cout << endl;

	switch(choice)
	{
	    case MAKE:
		MakeAccount();
		break;

	    case DEPOSIT:
		DepositMoney();
		break;

	    case WITHDRAW:
		WithdrawMoney();
		break;

	    case INQUIRE:
		ShowAllAccInfo();
		break;

	    case EXIT:
		for (int i = 0; i < accNum; i++)
		    delete accArr[i];
		return 0;

	    default:
		cout << "Illegal Selection.." << endl;
	}	    
    }


    return 0;
}

void ShowMenu(void)
{
    cout << "-----Menu------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;  
}

void MakeAccount(void)
{
    int id, balance;
    char name[NAME_LEN];

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";	cin >> id;
    cout << "이 름: ";	cin >> name;
    cout << "입금액: ";	cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void)
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

void WithdrawMoney(void)
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

void ShowAllAccInfo(void)
{
   for (int i = 0; i < accNum; i++)
   {
   	accArr[i]->ShowAccInfo();
	cout<<endl;
   }
}


