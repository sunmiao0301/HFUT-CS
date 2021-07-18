//计科2班 2018211958 孙淼
//Node.h
#ifndef NODE_H
#define NODE_H

template<class T>
class Node{
	private:
		Node<T> *next;
	public:
		T date;
	
	Node(const T&date,Node<T>*next=0);
	void insertAfter(Node<T>*p);
	Node<T>*deleteAfter();
	Node<T>*nextNode();
	const Node<T>*nextNode() const;
};

template<class T>
Node<T>::Node(const T& date,Node<T>*next/*=0*/):date(date),next(next){}

template<class T>
Node<T>*Node<T>::nextNode(){
	return next;
}

template<class T>
const Node<T>*Node<T>::nextNode()const{
	return next;
}

template<class T>
void Node<T>::insertAfter(Node<T>*p){
	p->next=next;
	next=p;
}

template<class T>
Node<T>*Node<T>::deleteAfter(){
	Node<T>*tempPtr=next;
	if(next==0)
	 return 0;
	next=tempPtr->next;
	return tempPtr;
}
#endif

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#ifndef NULL
#define NULL 0
#endif
template<class T>
class LinkedList{
	private:
		Node<T>*front,*rear;
		Node<T>*prevPtr,*currPtr;
		int size;
		int position;
		
		Node<T>*newNode(const T &item,Node<T>*ptrNext=NULL);
		void copy(const LinkedList<T>&L);
	public:
		LinkedList();
		LinkedList(const LinkedList<T>&L);
		~LinkedList();
		LinkedList<T>&operator=(const LinkedList<T>&L);
		int getSize() const;
		bool isEmpty()const;
		void resert(int pos=0);
		void next();
		bool endOfList()const;
		int currentPosition(void) const;
		void insertFront(const T&item);
		void insertRear(const T&item);
		void insertAt(const T &item);
		void insertAfter(const T &item);
		T deleteFront();
		void deleteCurrrent();
		T& date();
		const T&data() const;
		void clear();
};

template<class T>
Node<T>*LinkedList<T>::nextNode(const T&item,Node<T>*ptrNext){
	Node<T>*tempPtr=new Node<T>(item,ptrNext);
	return tempPtr;
}

template <class T>
void LinkedList<T>::freeNode(Node<T>*p){
	delete p;
}

template<class T>
void LinkedList<T>::print(){
	reset();
	while(!endOfList()){
		cout<<data()<<" ";
		next();
	}
	cout<<endl;
	cout<<"size="<<getSize<<endl;
}

template<class T>
LinkedList<T>::LinkedList(){
	size=0;
	front=rear=new Node<T>(0);
	currPtr=prevPtr=front;
}

template<class T>
int LinkedList<T>::currrentPosition(void){
	Node<T>*tempPtr=front->nextNode();
	position=0;
	while(tempPtr!=currPtr){
		tempPtr=tempPtr->nextNode();
		position++;
	}
	return position;
}

template<class T>
int LinkedList<T>::getSize()const{
    return size; 
} 

template<class T>
T&LinkedList<T>::date(){
	return currPtr->data;
}

template<class T>
const T&LinkedList<T>::data()const{
	return currPtr->data;
}

template<class T>
void LinkedList<T>::next(){
	prevPtr=currPtr;
	currPtr=currPtr->nextNode();
}

template<class T>
bool LinkedList<T>::endOdList()const{
    if(currPtr==NULL) return true;
    else return false;
}

template<class T>
bool LinkedList<T>::isEmpty()const{
    if(front==rear) return true;
    else return false;
}

template<class T>
void LinkeedList<T>::reset(int pos){
	prePtr=front;
	currPtr=front->nextNode();
	position=pos;
	for(int i=0;i<position;i++){
		prePtr=currPtr;
		currPtr=currPtr->nextNode();
	}
}

template<class T>
coid LInkedList<T>::insertFront(const T&item){
	prePtr=currPtr;
	currPre=nextNode(item,front->next Node());
	front->next=currPtr;
	if(rear==front){
		rear=currPtr;
	}
	size++;
}

template<class T>
void LinkedList<T>::insertRear(const T&item){
	prePtr=nextNode(item,rear->nextNode());
	rear->nextNode()=currPtr;
	rear=currPtr;
	size++;
}

template<class T>
void LinkedList<T>::insertAfter(const T&item){
	prevPtr=currPtr;
    Node<T>*tempPtr=nextNode(item,currPtr->nextNode());
    currPtr->nextNode()=tempPtr;
    if(currPtr==rear){
    	rear=tempPtr;
	}
	currPtr=tempPtr;
	size;
}

template<class T>
void LinkedList<T>::insertAt(const T&item){
	currPtr=nextNode(item,prevPtr->nextNode());
	prePtr->next=currPtr;
	size++;
}

template<class T>
T LinkedList<T>::deleteFront(){
	currPtr=front->nextNode();
	delete front;
	front=currPtr;
	size--;
	return front->data;
}

template<class T>
LinkedList<T>::~LinkedLidt(){
	clear();
	delete front;
}


#endif

#include<iostream>
using namespace std;
int main(){
	LinkedList<int>list1;
	LinkedList<int>list2;
	cout<<"请输入a的各结点值"<<endl;
	for(int i=0;i<5;i++){
		int item;
		cin>>item;
		list1.insertFront(item);
	}
	cout<<"a:";
	list1.resert();
	while(!list1.endOfList()){
		cout<<list1.date()<<" ";
		list1.next();
	}
	cout<<endl;
	cout<<"请输入b的各结点值"<<endl;
	for(int j=0;j<5;j++){
		int item;
		cin>>item;
		list2.insertFront(item);
	}
	cout<<"b:";
	list2.resert();
	while(!list2.endOfList()){
		cout<<list2.date()<<" ";
		list2.next();
	}
	cout<<endl;
	cout<<"a:";
	list1.resert();
	while(!list1.endOfList()){
		cout<<list1.date()<<" ";
		list1.next();
	}
}

请输入a的各结点值:
1 2 3 4 5
a:1 2 3 4 5
请输入b的各结点值:
6 7 8 9 10
b:6 7 8 9 10
a:1 2 3 4 5 6 7 8 9 10 
--------------------------------
Process exited after 11.27 seconds with return value 0
请按任意键继续. . .
