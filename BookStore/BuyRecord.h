/*!
* \class buyRecord
*
* \brief
*
* \author 29097
* \date ÁùÔÂ 2017
*/
#ifndef BUYRECORD_H
#define BUYRECORD_H
#include<iostream>
using namespace std;
#include "AString.h"
#include "Date.h"

class BuyRecord{
	friend ostream& operator<<(ostream& output, const BuyRecord& record);
	friend istream& operator>>(istream& input, BuyRecord& record);
private:
    AString recordNumberinbuyrecord;
	AString customerNum;
	AString customerName;
	AString customerPhone;
	AString bookNum;
	AString bookName;
	AString writerName;
	Date buyTime;
	int buyNum;
	double itemPrice;
	double totalPrice;
	double buyPrivilage;
public:
    BuyRecord(const Date& =*new Date(""), int = 0, double = 0.0, double = 1.0,AString =*new AString("000000"), const AString& = "", const AString& = "", const AString& = "", const AString& = "", const AString& = "", const AString& = "");
	//~BuyRecord();
	bool setRecordNumber(const AString& rNum);
	AString getRecordNumber()const;

	bool setCustomerNum(const AString& CNum);
	AString getCustomerNum()const;
	bool setCustomerName(const AString& CName);
	AString getCustomerName()const;
	bool setCustomerPhone(const AString& CPhone);
	AString getCustomerPhone()const;
	bool setBookNum(const AString& BNum);
	AString getBookNum()const;
	AString getBookName()const;
	bool setBookName(const AString& BNmae);
	bool setWriterName(const AString& wName);
	AString getWriterName()const;
	bool setBuyTime(const Date& time);
	Date getBuyTime()const;
	bool setBuyNum(int number);
	int getBuyNum()const;
	bool setItemPrice(double itemPrice);
	double getItemPrice()const;
	bool setTotalPrice();
	double getTotalPrice()const;
	bool setBuyPrivilage(double privilage);
	double getBuyPrivilage()const;
	BuyRecord& operator=(const BuyRecord& record);
};
#endif
