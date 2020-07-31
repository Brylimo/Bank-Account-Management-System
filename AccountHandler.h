#ifndef __ACCOUN_HANDLER_H__
#define __ACCOUN_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
    BoundCheckAccountPtrArray accArr; // Account 저장을 위한 배열
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
#endif
