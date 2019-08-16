#include<iostream>
using namespace std;
#include "People.h"
People::People(int stateValue,const AString& numberValue, const AString& nameValue, const AString& passwordValue, const AString& phoneNumber){
	setName(nameValue);
	setNumber(numberValue);
	setPassword(passwordValue);
	setPhoneNumber(phoneNumber);
    setState(stateValue);
}
bool People::setState(int stateValue){
    state=stateValue;
    return true;
}

int People::getState()const{
    return state;
}
bool People::setName(const AString& nameValue){
	if (nameValue.Length() > 0 && nameValue.Length() <= 12){
		name = nameValue;
		return true;
	}
	else{
		cerr << "name error!" << endl;
		return false;
	}
}
AString People::getName()const{
	return name;
}
bool People::setNumber(const AString& numberValue){
    if (numberValue.Length()<10){
		number = numberValue;
		return true;
	}
	else{
		cerr << "number error!" << endl;
		return false;
	}
}
AString People::getNumber()const{
	return number;
}
bool People::setPassword(const AString& passwordValue){
	if (passwordValue.Length() >= 6 && passwordValue.Length() <= 16){
		password = passwordValue;
		return true;
	}
	else{
		cerr << "password error!" << endl;
		return false;
	}
}
AString People::getPassword()const{
	return password;
}
bool People::setPhoneNumber(const AString& phoneValue){
	if (phoneValue.Length() == 11){
		phoneNumber = phoneValue;
		return true;
	}
	else{
		return false;
		cerr << "phone number error!" << endl;
	}
}
AString People::getPhoneNumber()const{
	return phoneNumber;
}
