#include<iostream>
using namespace std;
#include"AString.h"
char* AString::AStringToString()const{
	return ch;
}
AString::AString(int size){
	maxSize = size;
	ch = new char[maxSize];
	if (ch == NULL){
		cerr << "Allocation Error!" << endl;
		exit(1);
	}
	currentLength = 0;
	ch[0] = '\0';
}
AString::AString(const char *init){
	int length = strlen(init);
	maxSize = (length > DefaultSize) ? length : DefaultSize;
	ch = new char[maxSize + 1];
	if (ch == NULL){
		cerr << "Allocation Error!" << endl;
		exit(1);
	}
	currentLength = length;
	strcpy(ch, init);
}
AString::AString(const AString &ob){
	maxSize = ob.maxSize;
	ch = new char[maxSize + 1];
	if (ch == NULL){
		cerr << "Allocation Error!" << endl;
		exit(1);
	}
	currentLength = ob.currentLength;
	strcpy(ch, ob.ch);
}
AString::~AString(){
	delete[] ch;
}
int AString::Length()const{
	return currentLength;
}
AString& AString::operator()(int pos, int len)const{
	AString temp;
	if (pos < 0 || pos + len - 1 >= maxSize || len < 0){
		temp.currentLength = 0;
		temp.ch[0] = '\0';
	}
	else{
		if (pos + len - 1>currentLength)
			len = currentLength - pos;
		temp.currentLength = len;
		for (int i = 0, j = pos; i < len; i++, j++){
			temp.ch[i] = ch[j];
		}
		temp.ch[len] = '\0';
	}
	return temp;
}
bool AString::operator==(const AString&ob)const{
	return strcmp(ch, ob.ch) == 0;
}
bool AString::operator!=(const AString&ob)const{
	return strcmp(ch, ob.ch) != 0;
}
bool AString::operator!()const{
	//if ch is empty,return 1
	return currentLength == 0;
}
AString& AString::operator=(const AString &ob){
	if (ob != *this){
		delete[] ch;
		ch = new char[maxSize + 1];
		if (ch == NULL){
			cerr << "Allocation Error!" << endl;
			exit(1);
		}
		currentLength = ob.currentLength;
		strcpy(ch, ob.ch);
	}
	else{
		cout << "The AString can't copy itself!" << endl;
	}
	return *this;
}
AString & AString::operator+=(const AString &ob){
	char *temp = ch;
	int n = currentLength + ob.currentLength;
	int m = (maxSize >= n) ? maxSize : n;
	ch = new char[m + 1];
	if (ch == NULL){
		cerr << "Allocation Error!" << endl;
		exit(1);
	}
	maxSize = m;
	currentLength = n;
	strcpy(ch, temp);
	strcat(ch, ob.ch);
	delete[] temp;
	return *this;
}
char AString::operator[](int i)const{
	if (i<1 || i>currentLength){
		cout << "Location of the char Error!" << endl;

		exit(1);
	}
	else{
		return ch[i - 1];
	}
}
int AString::Find(const AString& pat, int pos, int next[])const{
	//return the downSign of the beginning of the target char,else return -1;
	int posP = 0;
	int posT = pos;
	int lengthP = pat.currentLength;
	int lengthT = currentLength;
	while (posP < lengthP && posT < lengthT){
		if (posP == -1 || pat.ch[posP] == ch[posT]){
			posP++;
			posT++;
		}
		else posP = next[posP];
	}
	if (posP < lengthP)
		return -1;
	else
		return posT - lengthP;
}
bool AString::getNext(int next[])const{
	int j = 0, k = -1, lengthP = currentLength;
	next[0] = -1;
	while (j < lengthP){
		if (k == -1 || ch[j] == ch[k]){
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
	return true;
}
ostream& operator<<(ostream& output, const AString& string){
	output << string.ch << endl;
	return output;
}
istream& operator>>(istream& input, AString& string){
	input >> string.ch;
	string.currentLength = strlen(string.ch);
	return input;
}
int AString::AStringToInt()const{
	if (strlen(ch) <= 10){
		int temp;
		temp = atoi(ch);
		return temp;
	}
	else{
		cerr << " string is too long!" << endl;
		exit(1);
	}
}
bool AString::ALLisNum()const{
	for (int i = 0; i < Length(); i++){
		int temp = (int)ch[i];
		if (temp >= 48 && temp <= 57){
			continue;
		}
		else{
			return false;
		}
	}
	return true;
}
