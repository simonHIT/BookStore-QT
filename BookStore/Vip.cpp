#include<iostream>
using namespace std;
#include"Vip.h"
Vip::Vip(const AString& typeValue){
	type = typeValue;
	setVip(type);
}
bool Vip::setVip(const AString& typeValue){
	const AString vip1("1");
	const AString vip2("2");
	const AString vip3("3");
	const AString vip0("0");
	if (typeValue == vip0){
		AString name("Vip0");
		typeName = name;
		borrowPrivilage = 0;
		buyPrivilage = 0.98;
		money = 0.00;
	}
	else if (typeValue == vip1){
		AString name("Vip1");
		typeName = name;
		borrowPrivilage = 15;
		buyPrivilage = 0.95;
		money = 50.00;
	}
	else if (typeValue == vip2){
		AString name("Vip2");
		typeName = name;
		borrowPrivilage = 25;
		buyPrivilage = 0.90;
		money = 100.00;
	}
	else if (typeValue == vip3){
		AString name("Vip3");
		typeName = name;
		borrowPrivilage = 30;
		buyPrivilage = 0.85;
		money = 150.00;
	}
	else{
		return false;
		cerr << "Vip Error!" << endl;
		exit(1);
	}
	return true;
}
AString Vip::getType()const{
	return type;
}
AString Vip::getTypeName()const{
	return typeName;
}
int Vip::getBorrowPrivilage()const{
	return borrowPrivilage;
}
double Vip::getBuyPrivilage()const{
	return buyPrivilage;
}
double Vip::getMoney()const{
	return money;
}
Vip& Vip::operator=(const Vip& vip){
	type = vip.getType();
	setVip(type);
	return *this;
}
istream& operator>>(istream& input, Vip& vip){
	cout << "input the vip:" << endl;
	cout << "input the type of the vip:" << endl;
	input >> vip.type;
	vip.setVip(vip.getType());
	return input;
}
ostream& operator<<(ostream& output, const Vip& vip){
	cout << "output the vip:" << endl;
	cout << "output the type of the vip:" << endl;
	output << vip.type;
	cout << "output the type name of the vip:" << endl;
	output << vip.typeName;
	cout << "output the borrow privilage of the vip:" << endl;
	output << vip.borrowPrivilage;
	cout << "output the buy privilage of the vip:" << endl;
	output << vip.buyPrivilage;
	cout << "output the Vip Money of the vip:" << endl;
	output << vip.getMoney();
	return output;
}