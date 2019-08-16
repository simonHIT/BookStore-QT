/*!
* \class Book
*
* \brief
*
* \author 29097
* \date ÁùÔÂ 2017
*/
#ifndef BOOK_H
#define BOOK_H
#include<iostream>
using namespace std;
#include"AString.h"
#include"BookType.h"

class Book{
	friend ostream&operator<<(ostream&output, const Book& targetBook);
	friend istream&operator>>(istream&input, Book& targetBook);
private:
	AString bookNumber;
	AString bookName;
	BookType type;
	AString writerName;
	int currentNumber;
	int inventory;
	double itemPrice;
public:
	Book(BookType& =*new BookType("0"), const AString& = "", const AString& = "", const AString& = "", int = 0, int = 0, double = 0.0);
	bool setBookNumber(const AString bookNum);
	AString getBookNumber()const;
	bool setBookName(const AString bNmae);
	AString getBookName()const;
	bool setBookType(const BookType& typeValue);
	BookType getBookType()const;
	bool setWriterName(const AString wName);
	AString getWriterName()const;
	bool setCurrentNumber(int currentNum);
	int getCurrentNumber()const;
	bool setInventory(int inventoryNum);
	int getInventory()const;
	bool setItemPrice(double itemPriceValue);
	double getItemPrice()const;
	Book&operator=(const Book& targetBook);
};
#endif