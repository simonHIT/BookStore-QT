#include<iostream>
using namespace std;
#ifndef BBSTREE_H
#define BBSTREE_H
template<class T, class E>
struct Data{
	T value;
	E key;
	Data(T valueNum = NULL, E keyNum = NULL){
		value = valueNum;
		key = keyNum;
	}
	~Data();
};
template<class T, class E>
struct BBSTNode{
	Data<T, E> *data;
	int bf;
	struct BBSTNode *lchild, *rchild;
	BBSTNode(T valueNum, E keyNum, BBSTNode<T, E> * left = NULL, BBSTNode<T, E>* right = NULL, int bfValue = 0){
		data = new Data<T, E>(valueNum, keyNum);
		lchild = left;
		rchild = right;
		bf = bfValue;
	}
    BBSTNode<T,E> & operator =(BBSTNode<T,E> targetNode){
        data=targetNode.data;
        bf=targetNode.bf;
        lchild=targetNode.lchild;
        rchild=targetNode.rchild;
    }

	~BBSTNode(){}
};
template<class T, class E>
class BBSTree{
private:
	int NodeNumber(BBSTNode<T, E>* TNode)const;
	BBSTNode<T, E>* root;
	int BBSTNodeDepth(BBSTNode<T, E> *TNode)const;
	bool rightBalance(BBSTNode<T, E> **BBST);
	bool leftBalance(BBSTNode<T, E> ** BBST);
	bool leftRoate(BBSTNode<T, E> **BBST);
	bool rightRotate(BBSTNode<T, E> **BBST);
	BBSTNode<T, E>* SearchBBSTNode(BBSTNode<T, E>* TNode, E keyNumber)const;
	bool InsertBBSTNode(BBSTNode<T, E>** TNode, T value, E key, bool *taller);
	bool DeleteBBSTNode(BBSTNode<T, E>** TNode, const E & key, BBSTNode<T, E>* f, BBSTNode<T, E> *p, bool *taller, int mark);
public:
	BBSTree();
	BBSTree(T valueOfData, E valueOfKey);
	BBSTree(const BBSTNode<T, E> &Root);
	BBSTNode<T, E>& SearchBBSTree(E keyNumber)const;
	bool InsertBBSTree(T value, E key);
	bool DeleteBBSTree(const E& key);
	int BBSTreeDepth()const;
	int BBSTNodeNum()const;
	bool isEmpty()const;
	BBSTNode<T, E>* getRoot()const;
};
#endif
