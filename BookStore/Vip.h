/*!
* \class Vip
*
* \brief
*
* \author 29097
* \date ÁùÔÂ 2017
*/
#ifndef VIP_H
#define VIP_H
#include<iostream>
using namespace std;
#include "AString.h"
class Vip{
	friend istream& operator>>(istream& input, Vip& vip);
	friend ostream& operator<<(ostream& output, const Vip& vip);
private:

	AString type;
	AString typeName;
	double money;
	int borrowPrivilage;
	double buyPrivilage;
public:
	Vip(const AString& = "0");
	//~Vip();
	bool setVip(const AString& typeValue);
	AString getType()const;
	AString getTypeName()const;
	int getBorrowPrivilage()const;
	double getBuyPrivilage()const;
	double getMoney()const;
	Vip& operator=(const Vip& vip);
};
#endif