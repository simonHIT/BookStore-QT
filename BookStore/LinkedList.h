/*!
* \class LinkedList
*
* \brief
*
* \author 29097
* \date ÁùÔÂ 2017
*/
#include<iostream>
using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
struct LinkedNode{
	T data;
	LinkedNode<T> * link;
	LinkedNode(LinkedNode<T> *ptr = NULL){
		link = ptr;
	}
	LinkedNode(const T& item, LinkedNode<T> *ptr = NULL){
		data = item;
		link = ptr;
	}

};
template<class T>
class LinkedList {
protected:
	LinkedNode<T> *first;
	//the head node;
public:
	LinkedList(){
		// create the head pointer;
		first = new LinkedNode<T>;
	}
	LinkedList(const T&x){
		//create the head node;
		first = new LinkedNode<T>(x);
	}
	LinkedList(LinkedList<T> & L);
	//create the linkedList from L;
	~LinkedList(){
		//destoy the linkeList;
		makeEmpty();
	}
	int Length()const;
	// length without the head node;
	bool makeEmpty();
	LinkedNode<T> *getHead()const{
		//return the pointer of the head;
		return first;
	}
	bool setHead(LinkedNode<T> *p){
		// set the head node with p;
		first = p;
        return true;
	}
	LinkedNode<T> *Search(T x)const;
	// return the pointer of the node whose data is x;
	LinkedNode<T> *Locate(int i)const;
	// return the pointer of the i node;
	T getData(int i)const;
	// return the data of the i node;
	bool setData(int i, const T & x);
	// set the data of the i node;
	bool Insert(int i, const T & x);
	//insert the newnode after the i node;
	bool Delete(int i, T & x);
	//delete the i node;
	bool isEmpty()const{
		// judge the list empty;
		return (first->link == NULL ? true : false);
	}
	bool isFull()const{
		return false;
	}
	virtual bool Sort();
	bool input();
	//input the list without the head
	bool output()const;
	//output the list without the head;
	LinkedList<T>& operator=(LinkedList<T>& L);
};
#endif
