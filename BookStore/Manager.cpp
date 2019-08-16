#include<iostream>
using namespace std;
#include"Manager.h"
Manager::Manager(int stateValue,const AString& numberValue, const AString& nameValue, const AString& passwordValue, const AString& phoneValue, const AString& typeValue) :People(stateValue,numberValue, nameValue, passwordValue, phoneValue){
	setType(typeValue);

}
bool Manager::setType(const AString& typeValue){
	type = typeValue;
	return true;
}
AString Manager::getType()const{
	return type;
}

Manager& Manager::operator=(const Manager& manager){
	this->number = manager.getNumber();
	this->name = manager.getName();
	this->password = manager.getPassword();
	this->phoneNumber = manager.getPhoneNumber();
	this->type = manager.getType();
    this->state = manager.getState();
	return *this;
}
istream& operator>>(istream& input, Manager& manager){
	cout << "input the manager:" << endl;
	cout << "input the number of the manager:" << endl;
	AString number;
	input >> number;
	cout << number.Length() << endl;
	manager.setNumber(number);
	cout << "input the name of the manager:" << endl;
	AString name;
	input >> name;
	manager.setName(name);
	cout << "input the password of the manager:" << endl;
	AString password;
	input >> password;
	manager.setPassword(password);
	cout << "input the phone number of the manager:" << endl;
	AString phomenumber;
	input >> phomenumber;
	manager.setPhoneNumber(phomenumber);
	cout << "input the type of the manager:" << endl;
	AString type;
	input >> type;
	manager.setType(type);
    cout<<"input the state of the manager:"<<endl;
    int stateValue;
    cin>>stateValue;
    manager.setState(stateValue);
	return input;
}
ostream& operator<<(ostream& output, const Manager& manager){
	cout << "output the manager:" << endl;
	cout << "output the number of the manager:" << endl;
	output << manager.getNumber();
	cout << "output the name of the manager:" << endl;
	output << manager.getName();
	cout << "output the password of the manager:" << endl;
	output << manager.getPassword();
	cout << "output the phone number of the manager:" << endl;
	output << manager.getPhoneNumber();
	cout << "output the type of the manager:" << endl;
	output << manager.getType();
    cout<<"output the state of the manager:"<<endl;
    output<<manager.getState();
	return output;
}
