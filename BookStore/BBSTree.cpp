#include<iostream>
using namespace std;
#include"BBSTree.h"

template<class T, class E>
BBSTree<T, E>::BBSTree(){
	root = NULL;
}
template<class T, class E>
BBSTree<T, E>::BBSTree(T valueOfData, E valueOfKey){
	root = new BBSTNode<T, E>(valueOfData, valueOfKey);
}
template<class T, class E>
BBSTree<T, E>::BBSTree(const BBSTNode<T, E> &Root){
	root = &Root;
}
template<class T, class E>
BBSTNode<T, E>& BBSTree<T, E>::SearchBBSTree(E keyNumber)const{
	return *(SearchBBSTNode(root, keyNumber));
}
template<class T, class E>
BBSTNode<T, E>* BBSTree<T, E>::SearchBBSTNode(BBSTNode<T, E>* TNode, E keyNumber)const{
	if (!TNode || (keyNumber == TNode->data->key))
		return TNode;
	else if (keyNumber < TNode->data->key){
		return SearchBBSTNode(TNode->lchild, keyNumber);
	}
	else{
		return SearchBBSTNode(TNode->rchild, keyNumber);
	}
}
template<class T, class E>
bool BBSTree<T, E>::leftRoate(BBSTNode<T, E> **BBST){
	BBSTNode<T, E> *rc;
	rc = (*BBST)->rchild;
	(*BBST)->rchild = rc->lchild;
	rc->lchild = (*BBST);
	(*BBST) = rc;
	return true;
}
template<class T, class E>
bool BBSTree<T, E>::rightRotate(BBSTNode<T, E> **BBST){
	BBSTNode<T, E> *lc;
	lc = (*BBST)->lchild;
	(*BBST)->lchild = lc->rchild;
	lc->rchild = (*BBST);
	(*BBST) = lc;
	return true;
}
template<class T, class E>
bool BBSTree<T, E>::leftBalance(BBSTNode<T, E> **BBST){
	BBSTNode<T, E> *lc, *rd;
	lc = (*BBST)->lchild;
	switch (lc->bf){
	case 1:
		(*BBST)->bf = lc->bf = 0;
		rightRotate(&(*BBST));
		return true;
		break;
	case -1:
		rd = lc->rchild;
		switch (rd->bf){
		case 1:
			(*BBST)->bf = -1;
			lc->bf = 0;
			break;
		case 0:
			(*BBST)->bf = lc->bf = 0;
			break;
		case -1:
			(*BBST)->bf = 0;
			lc->bf = 1;
			break;
		}
		rd->bf = 0;
		leftRoate(&((*BBST)->lchild));
		rightRotate(&(*BBST));
		return true;
		break;
	default:
		return false;
		break;
	}
}
template<class T, class E>
bool BBSTree<T, E>::rightBalance(BBSTNode<T, E> ** BBST){
	BBSTNode<T, E> *rc, *ld;
	rc = (*BBST)->rchild;
	switch (rc->bf){
	case -1:
		(*BBST)->bf = rc->bf = 0;
		leftRoate(&(*BBST));
		return true;
		break;
	case 1:
		ld = rc->lchild;
		switch (ld->bf){
		case 0:
			(*BBST)->bf = rc->bf = 0;
			break;
		case -1:
			(*BBST)->bf = 1;
			rc->bf = 0;
			break;
		case 1:
			(*BBST)->bf = 0;
			rc->bf = 1;
			break;
		}
		ld->bf = 0;
		rightRotate((&(*BBST)->rchild));
		leftRoate(&(*BBST));
		return true;
		break;
	default:
		return false;
		break;
	}
}
template<class T, class E>
bool BBSTree<T, E>::InsertBBSTree(T value, E key){

	bool taller = false;
	bool temp;
	temp = InsertBBSTNode(&root, value, key, &taller);

	return temp;
}
template<class T, class E>
bool BBSTree<T, E>::InsertBBSTNode(BBSTNode<T, E>** TNode, T value, E key, bool *taller){

	if ((*TNode) == NULL){

		(*TNode) = new BBSTNode<T, E>(value, key);
		(*TNode)->lchild = (*TNode)->rchild = NULL;
		(*TNode)->bf = 0;
		*taller = true;
	}
	else{

		if (key == (*TNode)->data->key){
			*taller = false;
			return false;
		}
		else if (key < (*TNode)->data->key){
			if (!InsertBBSTNode(&((*TNode)->lchild), value, key, taller)){
				return false;
			}
			if (*taller){
				switch ((*TNode)->bf){
				case 1:
					leftBalance(&(*TNode));
					*taller = false;
					break;
				case 0:
					(*TNode)->bf = 1;
					*taller = true;
					break;
				case -1:
					(*TNode)->bf = 0;
					*taller = false;
					break;
				}//end switch
			}//endif
		}
		else{
			if (!InsertBBSTNode(&((*TNode)->rchild), value, key, taller)){
				return false;
			}
			if (*taller){
				switch ((*TNode)->bf){
				case 1:
					(*TNode)->bf = 0;
					*taller = false;
					break;
				case 0:
					(*TNode)->bf = -1;
					*taller = true;
					break;
				case -1:
					rightBalance(&(*TNode));
					*taller = false;
					break;
				}
			}
		}
	}
	return true;
}
template<class T, class E>
bool BBSTree<T, E>::DeleteBBSTree(const E& key){
	bool taller = false;
	int mark = 0;
	BBSTNode<T, E>* f = NULL;
	return DeleteBBSTNode(&root, key, f, root, &taller, mark);
}
template<class T, class E>
bool BBSTree<T, E>::DeleteBBSTNode(BBSTNode<T, E>** TNode, const E & key, BBSTNode<T, E>* f, BBSTNode<T, E> *p, bool *taller, int mark){
	//p is the current node,f is the father of p,mark is the relation of f and p.
	BBSTNode<T, E> * r;
	E keyValue;
	T value;
	if (!p){
		cerr << "Delete Error!" << endl;
		exit(1);
	}
	else{
		if (key < p->data->key){
			if (!DeleteBBSTNode(TNode, key, p, p->lchild, taller, 0)){
				cerr << "Delete Error!" << endl;
				exit(1);
			}
			if (*taller){
				switch (p->bf){
				case 1:
					p->bf = 0;
					*taller = true;
					break;
				case 0:
					p->bf = -1;
					*taller = false;
					break;
				case -1:
					if (!f)
						rightBalance(TNode);
					else
						rightBalance(&(f->lchild));
					*taller = true;
					break;
				}
			}
		}
		else if (key > p->data->key){
			if (!DeleteBBSTNode(TNode, key, p, p->rchild, taller, 1)){
				cerr << "Delete Error!" << endl;
				exit(1);
			}
			if (*taller){
				switch (p->bf){
				case 1:
					if (!f)
						leftBalance(TNode);
					else
						leftBalance(&(f->rchild));
					*taller = true;
					break;
				case 0:
					p->bf = 1;
					*taller = false;
					break;
				case -1:
					p->bf = 0;
					*taller = true;
					break;
				}
			}
		}
		else{
			if (p->lchild != NULL&&p->rchild == NULL){
				if (!f)
					*TNode = p->lchild;
				else{
					if (mark == 0)
						f->lchild = p->lchild;
					else
						f->rchild = p->lchild;
				}
				free(p);
				p = NULL;
				*taller = true;
			}
			else if (p->lchild == NULL&&p->rchild != NULL)
			{
				if (!f)
					*TNode = p->rchild;
				else{
					if (mark == 0)
						f->lchild = p->rchild;
					else
						f->rchild = p->rchild;
				}
				free(p);
				p = NULL;
				*taller = true;
			}
			else if (p->lchild == NULL&&p->rchild == NULL){
				if (!f)
					*TNode = NULL;
				else{
					if (mark == 0)
						f->lchild = NULL;
					else
						f->rchild = NULL;
				}
				free(p);
				p = NULL;
				*taller = true;
			}
			else{
				r = p->lchild;
				while (r->rchild)
					r = r->rchild;
				keyValue = r->data->key;
				value = r->data->value;
				*taller = false;
				if (!f)
					DeleteBBSTNode(TNode, keyValue, NULL, p, taller, mark);
				else{
					if (mark == 0)
						DeleteBBSTNode(&(f->lchild), keyValue, NULL, p, taller, mark);
					else
						DeleteBBSTNode(&(f->rchild), keyValue, NULL, p, taller, mark);
				}
				p->data->key = keyValue;
				p->data->value = value;
			}
		}
		return true;
	}
}
template<class T, class E>
int BBSTree<T, E>::BBSTNodeDepth(BBSTNode<T, E> *TNode)const{
	int leftDepth, rightDepth;
	if (TNode == NULL){
		return 0;
	}
	else{
		leftDepth = BBSTNodeDepth(TNode->lchild);
		rightDepth = BBSTNodeDepth(TNode->rchild);
		return (leftDepth >= rightDepth ? leftDepth : rightDepth) + 1;
	}
}
template<class T, class E>
int BBSTree<T, E>::BBSTreeDepth()const{
	return BBSTNodeDepth(root);
}
template<class T, class E>
int BBSTree<T, E>::BBSTNodeNum()const{
	return NodeNumber(root);
}
template<class T, class E>
int BBSTree<T, E>::NodeNumber(BBSTNode<T, E>* TNode)const{
	int totalNum, leftnum, rightnum;
	if (TNode == NULL)
		totalNum = 0;
	else{
		leftnum = NodeNumber(TNode->lchild);
		rightnum = NodeNumber(TNode->rchild);
		totalNum = leftnum + rightnum + 1;
	}
	return totalNum;
}
template<class T, class E>
bool BBSTree<T, E>::isEmpty()const{
	return root == NULL;
}
template<class T, class E>
BBSTNode<T, E>* BBSTree<T, E>::getRoot()const{
	return root;
}
