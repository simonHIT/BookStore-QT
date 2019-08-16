#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
template<class T>
class Stack{
public:
    Stack(int sz=50);
    ~Stack(){
        delete [] elements;
    }
    bool push( const T & x);
    bool pop(T &x);
    bool getTop(T &x);
    bool isEmpty()const{
        return (top==-1)?true:false;
    }
    bool isFull()const{
        return (top==maxSize-1)?true:false;
    }
    int getSize()const{
        return top+1;
    }
   bool MakeEmpty(){
       top=-1;
       return true;
   }
private:
   T *elements;
   int top;
   int maxSize;
   void overflowProcess();

};
template<class T>
Stack<T>::Stack(int size):top(-1),maxSize(size){
    elements=new T[maxSize];
    if(elements==NULL){
        cerr<<"Allocation error!"<<endl;
    }
}
template<class T>
void Stack<T>::overflowProcess(){
    T *newArray=new T[maxSize+20];
    if(newArray==NULL){
        cerr<<"Allocation Error!"<<endl;
        exit(1);
    }
    for(int i=0;i<=top;i++)
        newArray[i]=elements[i];
    maxSize=maxSize+20;
    delete [] elements;
    elements=newArray;
}
template<class T>
bool Stack<T>::push(const T &x){
    if(isFull()==true)
        overflowProcess();
    elements[++top]=x;
    return true;
}
template<class T>
bool Stack<T>::pop(T &x){
    if(isEmpty()==true)
        return false;
    x=elements[top--];
    return true;
}
template<class T>
bool Stack<T>::getTop(T& x){
    if(isEmpty()==true)
        return false;
    x=elements[top];
    return true;
}


#endif // STACK_H
