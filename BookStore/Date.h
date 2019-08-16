/*!
* \class Date
*
* \brief
*
* \author 29097
* \date ÁùÔÂ 2017
*/
#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
#include<time.h>
#include "AString.h"
class Date{
	friend ostream& operator<<(ostream& output, const Date& date);
	friend istream& operator>>(istream& input, Date&date);
private:
	AString dateValue;
public:
	Date();
    Date(const AString& );
	//~Date();
	AString getDateValue()const;
	bool setDateValue(const AString& value);
	int operator-(const Date& targetDate)const;
	Date operator+(const int days)const;
	bool operator=(const Date& targetDate);
};
#endif
