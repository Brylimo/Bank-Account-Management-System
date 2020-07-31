#include "BankingCommonDec1.h"
#include "AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len=100) :arrlen(len)
{
    arr = new Account[arrlen];        
}

BoundCheckAccountPtrArray::ACCOUNT_PTR& operator[] (int idx)
{
    if(idx<0 || idx>=arrlen)
    {
	cout<<"Array index out of bound exception"<<endl;
	exit(1);
    }
    return arr[idx];
}

ACCOUNT_PTR operator[] (int idx) const
{
    if(idx<0 || idx>=arrlen)
    {
	cout<<"Array index out of bound exception"<<endl;
	exit(1);
    }
    return arr[idx];
}

int GetArrLen() const
{
    return arrlen;
}

~BoundCheckAccountPtrArray()
{
    delete []arr;
}
