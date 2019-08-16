/*!
* \class DbList
*
* \brief
*
* \author 29097
* \date 六月 2017
*/
#include<iostream>
using namespace std;
#ifndef DBLIST_H
#define DBLIST_H
template<class T>
struct DblNode{
	T data;
	DblNode<T> *prev, *next;
	DblNode(DblNode<T> * left = NULL, DblNode<T> *right = NULL) :prev(left), next(right){

	}
	DblNode(T value, DblNode<T>* left = NULL, DblNode<T> * right = NULL) :prev(left), next(right), data(value){

	}
};
template<class T>
class DbList{
protected:
	DblNode<T> * first;
	//head node;
public:
	DbList(T uniqueValue);
	//value is the value of the head node;
	~DbList(){};
	int Length()const;
	//return the length without the head;
	bool isEmpty()const;
	DblNode<T> *getHead()const;
	bool setHead(DblNode<T> *ptr);
	DblNode<T>* Search(const T &x)const;
	//return the pointer of the node whose data is x;
	DblNode<T>* Locate(int i, int d)const;
	//定位序号为i的节点，d=0按前驱方向，d！=0按后继方向
	bool Insert(int i, const T& x, int d);
	//节点后插入，d=0按前驱方向，否则按后继方向
	bool Delete(int i, T &x, int d);
	//节点删除，x返回其值，d=0按前驱方向，否则按后继方向
	bool makeEmpty(int d);
	T getData(int i, int d)const;
	bool setData(int i, int d, const T &x);
	DbList<T>& operator=(const DbList<T>& L);
	bool Sort();
	bool input();
	bool output()const;
};
#endif