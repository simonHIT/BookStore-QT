/*!
* \class AString
*
* \brief
*
* \author 29097
* \date ÁùÔÂ 2017
*/
#include<iostream>
using namespace std;
#include<cstring>
#define DefaultSize 128
#ifndef ASTRING_H
#define ASTRING_H
class AString{
	friend ostream& operator<<(ostream& output, const AString& string);
	friend istream& operator>>(istream& input, AString& string);
private:
	char *ch;
	int currentLength;
	int maxSize;
public:
	AString(int = 64);
	AString(const char *init);
	AString(const AString& ob);
	~AString();
	int Length()const;
	AString& operator()(int pos, int len)const;
	bool operator==(const AString &ob)const;
	bool operator!=(const AString & ob)const;
	bool operator!()const;
	AString & operator=(const AString &ob);
	AString & operator+=(const AString & ob);
	char operator[](int i)const;
	int  Find(const AString& pat, int pos, int next[])const;
	bool getNext(int next[])const;
	int AStringToInt()const;
	bool ALLisNum()const;
	char* AStringToString()const;
};
#endif 
