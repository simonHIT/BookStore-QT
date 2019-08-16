#include<iostream>
using namespace std;
#include"DbList.h"
template<class T>
DbList<T>::DbList(T uniqueValue){
	first = new DblNode<T>(uniqueValue);
	if (first == NULL){
		cerr << "´æ´¢·ÖÅä´íÎó£¡" << endl;
		exit(1);
	}
	first->next = first->prev = first;
}
template<class T>
int DbList<T>::Length()const{
	DblNode<T>*current = first->next;
	int count = 0;
	while (current != first){
		current = current->next;
		count++;
	}
	return count;
}
template<class T>
bool DbList<T>::isEmpty()const{
	return first->next == first;
}
template<class T>
DblNode<T> *DbList<T>::getHead()const{
	return first;
}
template<class T>
bool DbList<T>::setHead(DblNode<T> *ptr){
	first = ptr;
    return true;
}

template<class T>
DblNode<T>* DbList<T>::Search(const T &x)const{
	DblNode<T>*current = first->next;
	while (current != first&&current->data != x)
	{
		current = current->next;
	}
	if (current != first)
		return current;
	else
		return NULL;
}
template<class T>
DblNode<T>* DbList<T>::Locate(int i, int d)const{
	if (first->next == first&&i == 0)
		return first;
	DblNode<T> *current;
	if (d == 0)
		current = first->prev;
	else
		current = first->next;
	for (int j = 1; j < i; j++){
		if (current == first) break;
		else if (d == 0)
			current = current->prev;
		else current = current->next;
	}
	if (current != first)
		return current;
	else return NULL;

}
template<class T>
bool DbList<T>::Insert(int i, const T&x, int d){
	DblNode<T> *current = Locate(i, d);
	if (current == NULL)
		return false;
	DblNode<T> *newNode = new DblNode<T>(x);
	if (newNode == NULL){
		cerr << "´æ´¢·ÖÅä´íÎó!" << endl;
		return false;
		exit(1);
	}
	if (d == 0){
		newNode->prev = current->prev;
		current->prev = newNode;
		newNode->prev->next = newNode;
		newNode->next = current;
	}
	else{
		newNode->next = current->next;
		current->next = newNode;
		newNode->next->prev = newNode;
		newNode->prev = current;
	}
	return true;
}
template<class T>
bool DbList<T>::Delete(int i, T & x, int d){
	DblNode<T> *current = Locate(i, d);
	if (current == NULL) return false;
	x = current->data;
	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete current;
	return true;
}
template<class T>
bool DbList<T>::makeEmpty(int d){
	T x;
	for (int i = 1; i <= Length(); i++){
		Delete(i, x, d);
	}
	return true;
}
template<class T>
T DbList<T>::getData(int i, int d)const{
	DblNode<T> *current = Locate(i, d);
	if (current == NULL)
		return NULL;
	return current->data;
}
template<class T>
bool DbList<T>::setData(int i, int d, const T&x){
	DblNode<T> *current = Locate(i, d);
	if (current == NULL)
		return NULL;
	else{
		current->data = x;
		return true;
	}
}
template<class T>
DbList<T>& DbList<T>::operator=(const DbList<T>&L){
	T value;
	DblNode<T> *srcptr = L.getHead();
	first = new DblNode<T>;
	first->next = first->prev = first;
	DblNode<T>* destptr = first;
	while (srcptr->next != L.getHead()){
		value = srcptr->next->data;
		DblNode<T> *newNode = new DblNode<T>(value);
		newNode->next = destptr->next;
		destptr->next = newNode;
		newNode->next->prev = newNode;
		newNode->prev = destptr;
		destptr = destptr->next;
		srcptr = srcptr->next;
	}
	return *this;
}
template<class T>
bool DbList<T>::Sort(){
	return true;
}
template<class T>
bool DbList<T>::input(){
	DblNode<T>* current = first;
	if (first == NULL){
		cerr << "´æ´¢·ÖÅä´íÎó£¡" << endl;
		return false;
		exit(0);
	}
	T endValue;
	cout << "Input the endValue:" << endl;
	cin >> endValue;
	cout << "Input the values of the linkednodes:" << endl;
	T value;
	cin >> value;
	while (value != endValue){
		DblNode<T> *newNode = new DblNode<T>(value);
		if (newNode == NULL){
			cerr << "´æ´¢·ÖÅä´íÎó£¡" << endl;
			return false;
			exit(0);
		}
		newNode->next = current->next;
		current->next = newNode;
		newNode->next->prev = newNode;
		newNode->prev = current;
		current = current->next;
		cin >> value;
	}
	return true;
}
template<class T>
bool DbList<T>::output()const{
	DblNode<T> *current = first->next;
	while (current != first){
		cout << current->data << endl;
		current = current->next;
	}
	return true;
}
