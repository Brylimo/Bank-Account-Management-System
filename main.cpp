#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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
		return 0;
	}	    
    }


    return 0;
}
