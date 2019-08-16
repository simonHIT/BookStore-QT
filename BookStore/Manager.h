/*!
* \class Manager
*
* \brief
*
* \author 29097
* \date ÁùÔÂ 2017
*/
#ifndef MANAGER_H
#define MANAGER_H
#include "AString.h"
#include"People.h"
class Manager :public People
{
	friend istream& operator>>(istream& input, Manager& manager);
	friend ostream& operator<<(ostream& output, const Manager& manager);
public:
    Manager(int = 0,const AString& = "", const AString& = "", const AString& = "", const AString& = "", const AString& = "");
	//~Manager();
	bool setType(const AString& typeValue);
	AString getType()const;

	Manager& operator=(const Manager& manager);
private:
	AString type;

};

#endif
