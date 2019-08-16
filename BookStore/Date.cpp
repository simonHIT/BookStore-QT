#include<iostream>
#include "Date.h"
#include<time.h>
Date::Date(){
	time_t nowtime = time(NULL);
	struct tm *local;
	local = localtime(&nowtime);
	char buf[12];
	strftime(buf, 12, "%Y%m%d", local);

	AString temp(buf);

	dateValue = temp;
}
Date::Date(const AString& date){
    dateValue=date;
}

int Date::operator-(const Date& targetDate)const{
	int dest = dateValue.AStringToInt();
	int src = targetDate.dateValue.AStringToInt();
	int destday = dest % 100;
	int destmonth = (dest % 10000) / 100;
	int destyear = dest / 10000;
	int srcday = src % 100;
	int srcmonth = src % 10000 / 100;
	int srcyear = src / 10000;
	return ((destyear - srcyear) * 365 + (destmonth - srcmonth) * 30 + (destday - srcday));
}
ostream& operator<<(ostream& output, const Date& date){
	output << date.dateValue[1] << date.dateValue[2] << date.dateValue[3] << date.dateValue[4] << "-" << date.dateValue[5] << date.dateValue[6] << "-" << date.dateValue[7] << date.dateValue[8] << endl;
	return output;
}
istream& operator>>(istream& input, Date&date){
	input >> date.dateValue;
	return input;
}
bool Date::setDateValue(const AString& value){
	dateValue = value;
	return true;
}
AString Date::getDateValue()const{
	return dateValue;
}
Date Date::operator+(const int days)const{
	int src = getDateValue().AStringToInt();
	int srcday = src % 100;
	int srcmonth = src % 10000 / 100;
	int srcyear = src / 10000;

	int temp, monthIncrement;
	int dest, destday, destmonth, destyear;
	temp = srcday + days;
	if (temp == 60){
		monthIncrement = 1;
		destday = 30;
		destmonth = srcmonth + monthIncrement;
		destyear = srcyear;
	}
	else if (temp > 30 && temp<60){
		monthIncrement = temp / 30;
		destday = temp % 30;
		destmonth = srcmonth + monthIncrement;
		destyear = srcyear;
	}
	else{
		monthIncrement = 0;
		destday = temp;
		destmonth = srcmonth;
		destyear = srcyear;
	}
	dest = destyear * 10000 + destmonth * 100 + destday;
	char buf[12];
	_itoa(dest, buf, 10);
	AString destDateValue(buf);
    Date destDate;
	destDate.setDateValue(destDateValue);
	return destDate;
}
bool Date::operator=(const Date& targetDate){
	dateValue = targetDate.getDateValue();
	return true;
}
