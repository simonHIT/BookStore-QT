#ifndef BORROWRECORD_H
#define BORROWRECORD_H
#include<iostream>
using namespace std;
#include"AString.h"
#include"Date.h"

class BorrowRecord{
	friend ostream& operator<<(ostream& output, const BorrowRecord& record);
	friend istream& operator>>(istream& input, BorrowRecord& record);
private:
	AString recordNumber;
	AString customerNum;
	AString customerName;
	AString customerPhone;
	AString bookNum;
	AString bookName;
	AString writerName;
	int borrowPrivilage;
	Date borrowTime;
	Date returnTime;
	bool returnState;
public:
	BorrowRecord(const Date& =*new Date(), const AString& = "", const AString& = "", const AString& = "", const AString& = "", const AString& = "", const AString& = "", const AString& = "", int = 0, bool retrunState = false);
	//~BorrowRecord();
	bool setRecordNumber(const AString & rnumber);
	AString getRecordNumber()const;
	bool setCustomerNum(const AString& CNum);
	AString getCustomerNum()const;
	bool setCustomerName(const AString& CName);
	AString getCustomerName()const;
	bool setCustomerPhone(const AString& CPhone);
	AString getCustomerPhone()const;
	bool setBookNum(const AString& BNum);
	AString getBookNum()const;
	bool setBookName(const AString& BName);
	AString getBookName()const;
	bool setWriterName(const AString& WName);
	AString getWriterName()const;
	bool setBorrowPrivilage(int privilage);
	int getBorrowPrivilage()const;
	bool setBorrowTime(const Date& dateValue);
	Date getBorrowTime()const;
	bool setReturnTime();
	Date getReturnTime()const;
	bool setBorrowState(bool state);
	bool getBorrowState()const;
	BorrowRecord& operator=(const BorrowRecord& record);
};
#endif