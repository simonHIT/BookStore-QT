/*!
* \class SeqList
*
* \ingroup GroupName
*
* \brief
*
* TODO: long description
*
* \note
*
* \author 29097
*
* \version 1.0
*
* \date 六月 2017
*
* Contact: user@company.com
*
*/
#ifndef SEQLIST_H
#define SEQLIST_H
#include<iostream>
using namespace std;
//#include"LinearList.h"
#define defaultSize  100;
template<class T>

class SeqList {
protected:
	T *data;
	int maxSize;
	int last;
	//the downsign of the last data;
	bool reSize(int newSize);
public:
	SeqList(int = 100);

	//create a empty list whose maxsize is size;
	SeqList(SeqList<T>& L);
	//create the list from L;
	~SeqList()
	{
		delete[] data;
	}
	int Size()const{
		//return the maxsize of the list;
		return maxSize;
	}
	int Length()const{
		//return the length of the list;
		return last + 1;
	}
	int Search(T &x)const;
	//return the location of the data x in the list;
	int Locate(int i)const;
	//return the location of the i data int list(i=return);
	T getData(int i)const{
		//return the adress of the i data;
		if (i > 0 && i <= last + 1)
			return data[i - 1];
		else
			exit(1);
	}
	bool setData(int i, T&x){
		//set the i data with value x;
		if (i > 0 && i <= last + 1){
			data[i - 1] = x;
			return true;
		}
		return false;
	}
	bool Insert(int i, T&x);
	//insert the data to the location i;
	bool Delete(int i, T& x);
	//delete the i data;
	bool isEmpty()const{
		return (last == -1) ? true : false;
	}
	bool isFull()const{
		return (last == maxSize - 1) ? true : false;
	}
	bool input();
	bool output()const;
	SeqList<T>operator=(SeqList<T>&L);
	T operator[](int i)const;
};
template<class T>
T SeqList<T>::operator[](int i)const{
	if (i > 0 && i <= last + 1)
		return data[i - 1];
	else{
		cout << "error!" << emdl;
		exit(1);
	}
		
}
template<class T>
SeqList<T>::SeqList(int size){
	if (size > 0){
		maxSize = size;
		last = -1;
		data = new T[maxSize];
		if (data == NULL){
			cout << "存储分配错误！" << endl;
			exit(1);
		}
	}
	else{
		cerr << "Allocation error!" << endl;
		exit(1);
	}
}
template<class T>
SeqList<T>::SeqList(SeqList<T>&L){
	maxSize = L.Size();
	last = L.Length() - 1;
	data = new T[maxSize];
	if (data == NULL){
		cout << "存储分配错误！" << endl;
		exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
		data[i - 1] = *(L.getData(i));
}
template<class T>
bool SeqList<T>::reSize(int newSize){
	if (newSize <= 0){
		cout << "无效的数组大小！" << endl;
		return false;
	}
	if (newSize != maxSize){
		T * newArray = new T[newSize];
		if (newSize == NULL){
			cout << "存储分配错误！" << endl;
			exit(1);
		}
		int n = last + 1;
		T* srcPtr = data;
		T* destPtr = newArray;
		while (n--)
			*(destPtr++) = *(srcPtr++)
			delete[] data;
		data = newArray;
		maxSize = newSize;
	}
	return true;
}
template <class T>
int SeqList<T>::Search(T& x)const{
	for (int i = 0; i <= last; i++){
		if (data[i] == x)
			return i + 1;
		return 0;
	}
}
template<class T>
int SeqList<T>::Locate(int i)const{
	if (i >= 1 && i <= last + 1)
		return i;
	else
		return 0;
}
template<class T>
bool SeqList<T>::Insert(int i, T& x){
	if (last == maxSize - 1)
		return false;
	if (i<0 || i>last + 1)
		return false;
	int j;
	for (j = last; j >= i; j--)
		data[j + 1] = data[j];
	data[i] = x;
	last++;
	return true;
}
template<class T>
bool SeqList<T>::Delete(int i, T&x){
	if (last == -1)
		return false;
	if (i<1 || i>last + 1)
		return false;
	x = data[i - 1];
	for (int j = i; j <= last; j++)
		data[j - 1] = data[j];
	last--;
	return true;
}
template<class T>
bool SeqList<T>::input(){
	cout << "开始建立顺序表，请输入表中元素个数：" << endl;
	while (1){
		int num;
		cin >> num;
		last = num - 1;
		if (last <= maxSize - 1) break;
		cout << "表元素个数输入有误，范围不能超过" << maxSize << ";" << endl;
	}
	for (int i = 0; i <= last; i++){
		cin >> data[i];
	}
	return true;
}
template<class T>
bool SeqList<T>::output()const{
	cout << "顺序表的元素个数为:" << last + 1 << endl;
	for (int i = 0; i <= last; i++){
		cout << "#" << i + 1 << ":" << data[i] << endl;
	}
	return true;
}
template<class T>
SeqList<T> SeqList<T>::operator=(SeqList<T> &L){
	maxSize = L.Size();
	last = L.Length() - 1;
	data = new T[maxSize];
	if (data == NULL){
		cout << "存储分配错误！" << endl;
		exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
		data[i - 1] = *(L.getData(i));
	return *this;
}
#endif