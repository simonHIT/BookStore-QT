#include<iostream>
using namespace std;
using std::string;
#include"Book.h"
Book::Book(BookType& typeValue, const AString& bookNum, const AString& bName, const AString& writer, int currentNum, int inventoryValue, double price){
	setBookType(typeValue);
	setBookName(bName);
	setBookNumber(bookNum);
	setWriterName(writer);
	setCurrentNumber(currentNum);
	setInventory(inventoryValue);
	setItemPrice(price);
}
ostream&operator<<(ostream&output, const Book& targetBook){
	cout << "output the book:" << endl;
	cout << "the bookNumber is:" << endl;
	output << targetBook.getBookNumber();
	cout << "the name of the book is:" << endl;
	output << targetBook.getBookName() << endl;
	cout << "the type of the book is:" << endl;
	output << targetBook.getBookType() << endl;
	cout << "the writer of the book is:" << endl;
	output << targetBook.getWriterName() << endl;
	cout << "the current number of the book is :" << endl;
	output << targetBook.getCurrentNumber() << endl;
	cout << "the inventory of the book is:" << endl;
	output << targetBook.getInventory() << endl;
	cout << "the itemPrice of the book is:" << endl;
	output << targetBook.getItemPrice() << endl;
	return output;
}
istream&operator>>(istream&input, Book&targetBook){
	cout << "input the book:" << endl;
	cout << "input the number of the book:" << endl;
	AString number;
	input >> number;
	targetBook.setBookNumber(number);
	cout << "input the name of the book:" << endl;
	AString name;
	input >> name;
	targetBook.setBookName(name);
	cout << "input the type of the book:" << endl;
	BookType type;
	input >> type;
	targetBook.setBookType(type);
	cout << "input the writer of the book:" << endl;
	AString writerName;
	input >> writerName;
	targetBook.setWriterName(writerName);
	cout << "input the current number of the book:" << endl;
	input >> targetBook.currentNumber;
	cout << "input the inventory of the book:" << endl;
	input >> targetBook.inventory;
	cout << "input the itemPrice of the book:" << endl;
	input >> targetBook.itemPrice;
	return input;
}
bool Book::setBookNumber(const AString bookNum){
	bookNumber = bookNum;
	return true;
}
AString Book::getBookNumber()const{
	return bookNumber;
}
bool Book::setBookName(const AString bNmae){
	bookName = bNmae;
	return true;
}
AString Book::getBookName()const{
	return bookName;
}
bool Book::setBookType(const BookType& typeValue){
	type = typeValue;
	return true;
}
BookType Book::getBookType()const{
	return type;
}
bool Book::setWriterName(const AString wName){
	writerName = wName;
	return true;
}
AString Book::getWriterName()const{
	return writerName;
}
bool Book::setCurrentNumber(int currentNum){
	currentNumber = currentNum;
	return true;
}
int Book::getCurrentNumber()const{
	return currentNumber;
}
bool Book::setInventory(int inventoryNum){
	inventory = inventoryNum;
	return true;
}
int Book::getInventory()const{
	return inventory;
}
bool Book::setItemPrice(double itemPriceValue){
	itemPrice = itemPriceValue;
	return true;
}
double Book::getItemPrice()const{
	return itemPrice;
}
Book&Book::operator=(const Book& targetBook){
	bookNumber = targetBook.getBookNumber();
	bookName = targetBook.getBookName();
	type = targetBook.getBookType();
	writerName = targetBook.getWriterName();
	currentNumber = targetBook.getCurrentNumber();
	inventory = targetBook.getInventory();
	itemPrice = targetBook.getItemPrice();
	return *this;
}