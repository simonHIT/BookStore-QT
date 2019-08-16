/*!
* \class People
*
* \brief
*
* \author 29097
* \date ÁùÔÂ 2017
*/
#ifndef PEOPLE_H
#define PEOPLE_H
#include<iostream>
using namespace std;
#include "AString.h"

class People{
protected:
	AString name;
	AString number;
	AString password;
	AString phoneNumber;
    int state;
public:
    People(int =0,const AString& = "000000000000", const AString& ="0000000000", const AString& = "12345678", const AString& = "00000000000");
	//~People();
	bool setName(const AString& nameValue);
	AString getName()const;
	bool setNumber(const AString& numberValue);
	AString getNumber()const;
	bool setPassword(const AString& passwordValue);
	AString getPassword()const;
	bool setPhoneNumber(const AString& phoneValue);
	AString getPhoneNumber()const;
    bool setState(int stateValue);
    int getState()const;
};
#endif
