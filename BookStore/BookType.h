/*!
* \class BookType
*
* \brief
*
* \author 29097
* \date ÁùÔÂ 2017
*/
#ifndef BOOKTYPE_H
#define BOOKTYPE_H
#include<iostream>
using namespace std;
#include"AString.h"

class BookType{
	friend istream& operator>>(istream& input, BookType& bookType);
	friend ostream& operator<<(ostream& output, const BookType& bookType);
private:
	AString type;
	AString typeName;
public:
	BookType(const AString& = "");
	bool setType(const AString& typeValue);
	AString getType()const;

	AString getTypeName()const;
	BookType& operator=(const BookType& bookType);
};
#endif
