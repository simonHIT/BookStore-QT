/*!
* \class Customer
*
* \brief
*
* \author 29097
* \date ÁùÔÂ 2017
*/
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "AString.h"
#include "People.h"
#include "Vip.h"

class Customer :public People{

	friend istream& operator>>(istream& input, Customer& customer);
	friend ostream& operator<<(ostream&output, const Customer& customer);
private:
	Vip vip;
public:
    Customer(int =0,const Vip& =*new Vip("0"), const AString& = "0000000000", const AString& = "0000000000", const AString& = "0000000000", const AString& = "00000000000");
	//~Customer();
	bool setVip(const Vip& vipValue);
	Vip getVip()const;
	Customer& operator=(const Customer& customer);
};
#endif
