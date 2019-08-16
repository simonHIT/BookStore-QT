#include<iostream>
using namespace std;
#include"BuyRecord.h"
BuyRecord::BuyRecord(const Date& buyTimeValue, int buyNumber, double itemPriceValue, double privilage, AString  recordNum,const AString& WName, const AString& CNumber, const AString& CName, const AString&CPhone, const AString& BNum, const AString& BName){
	setBookName(BName);
    recordNumberinbuyrecord=recordNum;
	setBookNum(BNum);
	setWriterName(WName);
	setBuyNum(buyNumber);
	setBuyPrivilage(privilage);
	setBuyTime(buyTimeValue);
	setCustomerName(CName);
	setCustomerNum(CNumber);
	setCustomerPhone(CPhone);
	setItemPrice(itemPriceValue);
	setTotalPrice();
}
bool BuyRecord::setRecordNumber(const AString& rNum){

    recordNumberinbuyrecord = rNum;
	return true;
}
AString BuyRecord::getRecordNumber()const{
    return recordNumberinbuyrecord;
}
bool BuyRecord::setCustomerNum(const AString& CNum){
	customerNum = CNum;
	return true;
}
AString BuyRecord::getCustomerNum()const{
	return customerNum;
}
bool BuyRecord::setCustomerName(const AString& CName){
	customerName = CName;
	return true;
}
AString BuyRecord::getCustomerName()const{
	return customerName;
}
bool BuyRecord::setCustomerPhone(const AString& CPhone){
	customerPhone = CPhone;
	return true;
}
AString BuyRecord::getCustomerPhone()const{
	return customerPhone;
}
bool BuyRecord::setBookNum(const AString& BNum){
	bookNum = BNum;
	return true;
}
AString BuyRecord::getBookNum()const{
	return bookNum;
}
AString BuyRecord::getBookName()const{
	return bookName;
}
bool BuyRecord::setBookName(const AString& BNmae){
	bookName = BNmae;
	return true;
}
bool BuyRecord::setBuyTime(const Date& time){
	buyTime = time;
	return true;
}
Date BuyRecord::getBuyTime()const{
	return buyTime;
}
bool BuyRecord::setBuyNum(int number){
	buyNum = number;
	return true;
}
int BuyRecord::getBuyNum()const{
	return buyNum;
}
bool BuyRecord::setItemPrice(double itemPriceValue){
	itemPrice = itemPriceValue;
	return true;
}
double BuyRecord::getItemPrice()const{
	return itemPrice;
}
bool BuyRecord::setTotalPrice(){
	totalPrice = buyNum*itemPrice*buyPrivilage;
	return true;
}
double BuyRecord::getTotalPrice()const{
	return totalPrice;
}
bool BuyRecord::setBuyPrivilage(double privilage){
	buyPrivilage = privilage;
	return true;
}
double BuyRecord::getBuyPrivilage()const{
	return buyPrivilage;
}

bool BuyRecord::setWriterName(const AString& wName){
	writerName = wName;
	return true;
}
AString BuyRecord::getWriterName()const{
	return writerName;
}
BuyRecord& BuyRecord::operator=(const BuyRecord& record){
	customerNum = record.customerNum;
	customerName = record.customerName;
	customerPhone = record.customerPhone;
	bookNum = record.bookNum;
	bookName = record.bookName;
	writerName = record.writerName;
	buyTime = record.buyTime;
	buyNum = record.buyNum;
	itemPrice = record.itemPrice;
	totalPrice = record.totalPrice;
	buyPrivilage = record.buyPrivilage;
    recordNumberinbuyrecord=record.getRecordNumber();
	return *this;
}
ostream& operator<<(ostream& output, const BuyRecord& record){
	cout << "ouput the BuyRecord:" << endl;
	cout << "output the record number of the record:" << endl;
	output << record.getRecordNumber();
	cout << "output the customer number of the record:" << endl;
	output << record.getCustomerNum();
	cout << "output the customer name of the record:" << endl;
	output << record.getCustomerName();
	cout << "output the customer phone of the record:" << endl;
	output << record.getCustomerPhone();
	cout << "output the bookNum of the record:" << endl;
	output << record.getBookNum();
	cout << "output the book name of the record:" << endl;
	output << record.getBookName();
	cout << "output the writer of the record:" << endl;
	output << record.getWriterName();
	cout << "output the time of the record:" << endl;
	output << record.getBuyTime();
	cout << "output the buy number of the record:" << endl;
	output << record.getBuyNum();
	cout << "output the itemPrice of the record:" << endl;
	output << record.getItemPrice();
	cout << "output the totalprice of the record:" << endl;
	output << record.getTotalPrice();
	cout << "output the buy privilage of the record:" << endl;
	output << record.getBuyPrivilage();
	return output;
}
istream& operator>>(istream& input, BuyRecord& record){
	cout << "input the buy record:" << endl;
	cout << "input the record number of the record:" << endl;
	AString rnumber;
	input >> rnumber;
	record.setRecordNumber(rnumber);
	cout << "input the customer number of the record:" << endl;
	AString cnumber;
	input >> cnumber;
	record.setCustomerNum(cnumber);
	cout << "input the customer name of the record:" << endl;
	AString cname;
	input >> cname;
	record.setCustomerName(cname);
	cout << "input the customer phone of the record:" << endl;
	AString cphone;
	input >> cphone;
	record.setCustomerPhone(cphone);
	cout << "input the bookNum of the record:" << endl;
	AString bnumber;
	input >> bnumber;
	record.setBookNum(bnumber);
	cout << "input the book name of the record:" << endl;
	AString bname;
	input >> bname;
	record.setBookName(bname);
	cout << "input the writer of the record:" << endl;
	AString writer;
	input >> writer;
	record.setWriterName(writer);
	cout << "input the time of the record:" << endl;
	Date date;
	input >> date;
	record.setBuyTime(date);
	cout << "input the buy number of the record:" << endl;
	input >> record.buyNum;
	cout << "input the itemPrice of the record:" << endl;
	input >> record.itemPrice;
	
	cout << "input the buy privilage of the record:" << endl;
	input >> record.buyPrivilage;
	record.setTotalPrice();
	return input;
}
