#ifndef _SINGLY_LIST_H
#define _SINGLY_LIST_H

#include<iostream>
#include "node.h"

template <class X> class SinglyLinkedList {
	Node<X> *head;
	public: 
		SinglyLinkedList();
		~SinglyLinkedList();

		void push(X data);
		void append(X data);
		void deleteNode(X data);
		void printList();

};

template <class X> SinglyLinkedList<X>::SinglyLinkedList() {
}

template <class X> SinglyLinkedList<X>::~SinglyLinkedList() {
	Node<X>* current = head;
	Node<X>* prev = head;
	while(current) {
		prev = current;
		current = current->getNext();
		delete prev;
	}
}

template <class X> void SinglyLinkedList<X>::push(X data) {

	if(head) {
		Node<X> *newnode = new Node<X>();
		newnode->setData(data);
		newnode->setNext(head);
		head = newnode;

	} else {
		head = new Node<X>();
		head->setData(data);
	}
}

template <class X> void SinglyLinkedList<X>::append(X data) {
	Node<X> *newnode = new Node<X>();
	newnode->setData(data);
	if(!head->getNext()) {
		head->setNext(newnode);
	}

	Node<X> *current = head;
	while(current->getNext()) {
		current = current->getNext();
	}
	current->setNext(newnode);
}

template<class X> void SinglyLinkedList<X>::deleteNode(X data) {
	
	Node<X> *current = head;
	Node<X> *previous = head;

	//check for head itself
	if(current->getNext() && current->getData() == data) {
		head = current->getNext();
		delete current;
		return;
	}

	while(current->getNext() && current->getData() != data) {
		previous = current;
		current = current->getNext();
	}

	if(current == NULL ) return;

	previous->setNext(current->getNext());
	delete current;
} 

template <class X> void SinglyLinkedList<X>::printList() {
	Node<X>* current = head;
	while(current) {
		std::cout<<current->getData()<<" ";
		current = current->getNext();
	}
	std::cout<<std::endl;
}

#endif
