#include<iostream>
using namespace std;
#include "BorrowRecord.h"
BorrowRecord::BorrowRecord(const Date&borrowTime, const AString& recordNum, const AString& CNum, const AString& CName, const AString& CPhone, const AString& BNum, const AString& BName, const AString&WName, int privilage, bool retrunState){
	setBookName(BName);
	setBookNum(BNum);
	setBorrowPrivilage(privilage);
	setBorrowState(retrunState);
	setBorrowTime(borrowTime);
	setCustomerName(CName);
	setCustomerNum(CNum);
	setCustomerPhone(CPhone);
	setReturnTime();
	setWriterName(WName);
	setRecordNumber(recordNum);
}
bool BorrowRecord::setRecordNumber(const AString & rnumber){
	if (rnumber.Length()<1 || rnumber.Length()>10){
		cout << "recoord number error!";
	}
	recordNumber = rnumber;
	return true;
}
AString BorrowRecord::getRecordNumber()const{
	return recordNumber;
}
bool BorrowRecord::setCustomerNum(const AString& CNum){
	customerNum = CNum;
	return true;
}
AString BorrowRecord::getCustomerNum()const{
	return customerNum;
}
bool BorrowRecord::setCustomerName(const AString& CName){
	customerName = CName;
	return true;
}
AString BorrowRecord::getCustomerName()const{
	return customerName;
}
bool BorrowRecord::setCustomerPhone(const AString& CPhone){
	customerPhone = CPhone;
	return true;
}
AString BorrowRecord::getCustomerPhone()const{
	return customerPhone;
}
bool BorrowRecord::setBookNum(const AString& BNum){
	bookNum = BNum;
	return true;
}
AString BorrowRecord::getBookNum()const{
	return bookNum;
}
bool BorrowRecord::setBookName(const AString& BName){
	bookName = BName;
	return true;
}
AString BorrowRecord::getBookName()const{
	return bookName;
}
bool BorrowRecord::setWriterName(const AString& WName){
	writerName = WName;
	return true;
}
AString BorrowRecord::getWriterName()const{
	return writerName;
}
bool BorrowRecord::setBorrowPrivilage(int privilage){
	borrowPrivilage = privilage;
	return true;
}
int BorrowRecord::getBorrowPrivilage()const{
	return borrowPrivilage;
}
bool BorrowRecord::setBorrowTime(const Date& dateValue){
	borrowTime = dateValue;
	return true;
}
Date BorrowRecord::getBorrowTime()const{
	return borrowTime;
}
bool BorrowRecord::setReturnTime(){
	returnTime = (borrowTime + getBorrowPrivilage());
	return true;
}
Date BorrowRecord::getReturnTime()const{
	return returnTime;
}
bool BorrowRecord::setBorrowState(bool state){
	returnState = state;
	return true;
}
bool BorrowRecord::getBorrowState()const{
	return returnState;
}
BorrowRecord& BorrowRecord::operator=(const BorrowRecord& record){
	customerNum = record.getCustomerNum();
	customerName = record.getCustomerName();
	customerPhone = record.getCustomerPhone();
	bookNum = record.getBookNum();
	bookName = record.getBookName();
	writerName = record.getWriterName();
	borrowPrivilage = record.getBorrowPrivilage();
	borrowTime = record.getBorrowTime();
	returnTime = record.getReturnTime();
	returnState = record.getBorrowState();
    recordNumber=record.getRecordNumber();
	return *this;
}
ostream& operator<<(ostream& output, const BorrowRecord& record){
	cout << "output the borrowRecord:" << endl;
	cout << "ouput the recordNumber of the record:" << endl;
	output << record.getRecordNumber();
	cout << "ouput the customerNumber of the record:" << endl;
	output << record.getCustomerNum();
	cout << "ouput the customerName of the record:" << endl;
	output << record.getCustomerName();
	cout << "ouput the customerPhone of the record:" << endl;
	output << record.getCustomerPhone();
	cout << "ouput the bookNumber of the record:" << endl;
	output << record.getBookNum();
	cout << "ouput the bookName of the record:" << endl;
	output << record.getBookName();
	cout << "ouput the writerName of the record:" << endl;
	output << record.getWriterName();
	cout << "ouput the borrowTime of the record:" << endl;
	output << record.getBorrowTime();
	cout << "ouput the returnTime of the record:" << endl;
	output << record.getReturnTime();
	cout << "ouput the returnState of the record:" << endl;
	if (record.getBorrowState())
		cout << "returned!" << endl;
	else
		cout << "returnning!" << endl;
	cout << "ouput the borrowPrivilage of the record:" << endl;
	output << record.getBorrowPrivilage();
	return output;
}
istream& operator>>(istream& input, BorrowRecord& record){
	cout << "input the borrowRecord:" << endl;
	cout << "input the customerNumber of the record:" << endl;
	AString number;
	input >> number;
	record.setCustomerNum(number);
	cout << "input the customerName of the record:" << endl;
	AString name;
	input >> name;
	record.setCustomerName(name);
	cout << "input the writerName of the record:" << endl;
	AString rname;
	input >> rname;
	record.setWriterName(rname);
	cout << "input the customerPhone of the record:" << endl;
	AString phone;
	input >> phone;
	record.setCustomerPhone(phone);
	cout << "input the bookNumber of the record:" << endl;
	AString bnumber;
	input >> bnumber;
	record.setBookNum(bnumber);
	cout << "input the bookName of the record:" << endl;
	AString bname;
	input >> bname;
	record.setBookName(bname);
	cout << "input the borrowTime of the record:" << endl;
	Date date;
	input >> date;
	record.setBorrowTime(date);
	record.setBorrowState(false);
	cout << "input the borrowPrivilage of the record:" << endl;
	input >> record.borrowPrivilage;
	record.setReturnTime();
	return input;
}
