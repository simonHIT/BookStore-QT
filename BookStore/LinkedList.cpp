#include<iostream>
using namespace std;
#include"LinkedList.h"

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> &L){
	T value;
	LinkedNode<T> *srcptr = L.getHead();
	first = new LinkedNode<T>;
	LinkedNode<T> *destptr = first;
	while (srcptr->link != NULL){
		value = srcptr->link->data;
		destptr->link = new LinkedNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
}
template<class T>
bool LinkedList<T>::makeEmpty(){
	LinkedNode<T> *q;
	while (first->link != NULL){
		q = first->link;
		first->link = q->link;
		delete q;
	}
	return true;
}
template <class T>
int LinkedList<T>::Length()const{
	LinkedNode<T> *p = first->link;
	int count = 0;
	while (p != NULL){
		p = p->link;
		count++;
	}
	return  count;
}
template<class T>
LinkedNode<T> *LinkedList<T>::Search(T x)const{
	LinkedNode<T> *current = first->link;
	while (current != NULL)
	{
		if (current->data == x) break;
		else current = current->link;
	}
	return current;
}
template<class T>
LinkedNode<T> *LinkedList<T>::Locate(int i)const{
	if (i < 0) return NULL;
	LinkedNode<T> *current = first;
	int k = 0;
	while (current != NULL&&k < i){
		current = current->link;
		k++;
	}
	return current;
}
template<class T>
T LinkedList<T>::getData(int i)const{
	if (i < 0) return 0;
	LinkedNode<T> *current = Locate(i);
	if (current == NULL)
		return NULL;
	else
		return current->data;
}
//Insert new node after the target node;
template<class T>
bool LinkedList<T>::Insert(int i, const T&x){
	LinkedNode<T> *current = Locate(i);
	if (current == NULL) return false;
	LinkedNode<T> *newNode = new LinkedNode<T>(x);
	if (newNode == NULL){
		cerr << "´æ´¢·ÖÅä´íÎó£¡" << endl;
		exit(1);
	}
	newNode->link = current->link;
	current->link = newNode;
	return true;
}
template<class T>
bool LinkedList<T>::Delete(int i, T&x){
	LinkedNode<T> *current = Locate(i - 1);
	if (current == NULL || current->link == NULL)
		return false;
	LinkedNode<T> *del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
	return true;
}
template<class T>
bool LinkedList<T>::output()const{

	LinkedNode<T> *current = first->link;
	while (current != NULL){
		cout << current->data << endl;
		current = current->link;
	}
	return true;
}
template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& L){
	T value;
	LinkedNode<T> *srcptr = L.getHead();
	first = new LinkedNode<T>;
	LinkedNode<T> *destptr = first;
	while (srcptr->link != NULL){
		value = srcptr->link->data;
		destptr->link = new LinkedNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
	return *this;
}
template<class T>
bool LinkedList<T>::input(){

	LinkedNode<T>* current = first;
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
		LinkedNode<T> *newNode = new LinkedNode<T>(value);
		if (newNode == NULL){
			cerr << "´æ´¢·ÖÅä´íÎó£¡" << endl;
			return false;
			exit(0);
		}
		newNode->link = first->link;
		first->link = newNode;
		cin >> value;
	}
	return true;
}
template<class T>
bool LinkedList<T>::setData(int i, const T &x){
	if (i < 0) return false;
	LinkedNode<T>*current = Locate(i);
	if (current == NULL) return false;
	else current->data = x;
	return true;
}
template<class T>
bool LinkedList<T>::Sort(){
	return true;
}
