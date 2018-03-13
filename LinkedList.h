
/*
Author: David Wallace
Date: 02/15/2018
name: LinkedList.h
purpose: to provide container via a template linked list class
*/
#include <cstddef>//included b/c NULL was out of scope

#include <iostream>

using namespace std;

template <typename T>

class LinkedList{
	public :
		
		struct ListNode{
			T value;
			struct ListNode* next;	
		};
	
	private:
		ListNode* head;
		ListNode* tail;
		int numNodes;
	
	public:
		
		LinkedList();
		~LinkedList();
	
		int getLength();
		T getNodeValue(int);
		void appendNode(T);
		void deleteNode(int);
		int getNumNodes(){return numNodes;}
		ListNode* getHead(){return head;};
		ListNode* getTail(){return tail;};
		void swap(int,int);
};

template <typename T> 
LinkedList<T>::LinkedList(){
	
	head = NULL;
	tail = NULL;
	numNodes = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	
	ListNode* nodePtr = head;
	while (head!=NULL){
		head = nodePtr->next;
		delete nodePtr;
		nodePtr= nodePtr->next;		
	}
	head = NULL;
	tail = NULL;
}

template <typename T> 
int LinkedList<T>::getLength(){
	
	int counter =0;
	if(!head){
		return 0;
	}
	
	ListNode* nodePtr = head;
	while(nodePtr){
		nodePtr = nodePtr->next;
		counter++;
	}
	return counter;
}

template <typename T>
T LinkedList<T>::getNodeValue(int position){
	
	int counter = 0;
	ListNode* nodePtr = head;
	while(counter != position){
		nodePtr = nodePtr->next;
		counter++;
	}
	return nodePtr->value;
}

template <typename T>
void LinkedList<T>::appendNode(T object){
	
	ListNode* newNode;
	newNode = new ListNode;
	newNode->value = object;
	newNode->next = NULL;

	if(!head){
		head =newNode;
		tail = newNode;	
		numNodes++;
	}
	else{
		tail->next = newNode;
		tail=newNode;
		numNodes++;
	}

}

template <typename T>
void LinkedList<T>::deleteNode(int position){
	
	int counter = 0;
	while(position >= numNodes){
		cout<<"please enter a valid position\n";
		cin>>position;
		}
	ListNode* nodePtr = head;
	ListNode * nodePtr2 = head->next;
	if(position == 0){
		head = head->next;
		delete nodePtr;
		}
	if(position == numNodes-1){
		while(nodePtr->next != tail){
			nodePtr = nodePtr->next;
			}
		tail = nodePtr;
		nodePtr = nodePtr->next;	
		delete nodePtr;
		}
	while(counter != position){
		counter++;
		nodePtr = nodePtr->next;
		nodePtr2 = nodePtr2->next;
	}
	nodePtr->value = nodePtr2->value;
	nodePtr->next = nodePtr2->next;
	delete nodePtr2;
	numNodes--;
}

template <typename T>
void LinkedList<T>::swap (int objectGreater, int objectLesser){
	ListNode * nodePtr = head; 
	ListNode* nodePtrPlus = nodePtr->next;
	int counter = 0;
	while(counter != objectGreater){
		nodePtr = nodePtr->next;
		nodePtrPlus = nodePtr->next;
		counter++;
	}
	T temp = nodePtr->value;
	nodePtr->value = nodePtrPlus->value;
	nodePtrPlus->value = temp;
	
}
	

