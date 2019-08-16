#include<iostream>
using namespace std;
#include"BookType.h"
BookType::BookType(const AString& typeValue){
	type = typeValue;
	setType(type);
	//setTypeName(typeNameValue);
}
AString BookType::getType()const{
	return type;
}
AString BookType::getTypeName()const{
	return typeName;
}
bool BookType::setType(const AString& typeValue){
	const AString type1("1");
	const AString type2("2");
	const AString type3("3");
	const AString type4("4");
	const AString type5("5");
	const AString type6("6");
	const AString type7("7");
	const AString type8("8");
	const AString type9("9");
	const AString type10("10");
	const AString type11("11");
	const AString type12("12");
	const AString type13("13");
	if (typeValue == type1){
        AString name("literature");
		typeName = name;
	}
	else if (typeValue == type2){
        AString name("economy");
		typeName = name;
	}
	else if (typeValue == type3){
        AString name("technology");
		typeName = name;
	}
	else if (typeValue == type4){
        AString name("education");
		typeName = name;
	}
	else if (typeValue == type5){
        AString name("PE");
		typeName = name;
	}
	else if (typeValue == type6){
        AString name("life");
		typeName = name;
	}
	else if (typeValue == type7){
        AString name("mind");
		typeName = name;
	}
	else if (typeValue == type8){
        AString name("popular");
		typeName = name;
	}
	else if (typeValue == type9){
        AString name("history");
		typeName = name;
	}
	else if (typeValue == type10){
        AString name("politic");
		typeName = name;
	}
	else if (typeValue == type11){
        AString name("law");
		typeName = name;
	}
	else if (typeValue == type12){
        AString name("medical");
		typeName = name;
	}
	else if (typeValue == type13){
        AString name("eduAssistance");
		typeName = name;
	}
	else {
		cerr << "Type Error!" << endl;
	}
	return true;
}
BookType& BookType::operator=(const BookType& bookType){
	type = bookType.getType();
	setType(type);
	return *this;
}
istream& operator>>(istream& input, BookType& bookType){
	cout << "input the bookType:" << endl;
	cout << "input the type:" << endl;

	input >> bookType.type;

	bookType.setType(bookType.getType());

	return input;

}
ostream& operator<<(ostream& output, const BookType& bookType){
	cout << "output the bookType:" << endl;
	cout << "output the type :" << endl;
	output << bookType.getType();
	cout << "output the typeName:" << endl;
	output << bookType.getTypeName();
	return output;
}
