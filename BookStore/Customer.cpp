#include<iostream>
using namespace std;
#include"Customer.h"
Customer::Customer(int stateValue,const Vip& vipValue, const AString& numberValue, const AString& nameValue, const AString& passwordValue, const AString& phoneValue) :People(stateValue,numberValue, nameValue, passwordValue, phoneValue){
	setVip(vipValue);
}
bool Customer::setVip(const Vip& vipValue){
	vip = vipValue;
	return true;
}
Vip Customer::getVip()const{
	return vip;
}
Customer& Customer::operator=(const Customer& customer){
	this->number = customer.getNumber();
	this->name = customer.getName();
	this->password = customer.getPassword();
	this->phoneNumber = customer.getPhoneNumber();
	this->vip = customer.getVip();
    this->state=customer.getState();
	return *this;
}
istream& operator>>(istream& input, Customer& customer){
	cout << "input the customer:" << endl;
	cout << "input the number of the customer:" << endl;
	AString number;
	input >> number;
	customer.setNumber(number);
	cout << "input the name of the customer:" << endl;
	AString name;
	input >> name;
	customer.setName(name);
	cout << "input the password of the customer:" << endl;
	AString password;
	input >> password;
	customer.setPassword(password);
	cout << "input the phone number of the customer:" << endl;
	AString phomenumber;
	input >> phomenumber;
	customer.setPhoneNumber(phomenumber);
	cout << "input the type of the customer:" << endl;
	Vip type;
	input >> type;
	customer.setVip(type);
    cout<<"input the state of the customer:"<<endl;
    int stateValue;
    cin>>stateValue;
    customer.setState(stateValue);
	return input;
}
ostream& operator<<(ostream&output, const Customer& customer){
	cout << "output the customer:" << endl;
	cout << "output the number of the customer:" << endl;
	output << customer.getNumber();
	cout << "output the name of the customer:" << endl;
	output << customer.getName();
	cout << "output the password of the customer:" << endl;
	output << customer.getPassword();
	cout << "output the phone number of the customer:" << endl;
	output << customer.getPhoneNumber();
	cout << "output the viptype of the customer:" << endl;
	output << customer.getVip();
    output<<customer.getState();
	return output;
}
