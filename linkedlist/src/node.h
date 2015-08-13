#ifndef _L_LIST_H
#define _L_LIST_H


template <class X> class Node {
	X data;
	Node *next;
public:
	Node();
	X getData();
	void setData(X data);
	Node* getNext();
	void setNext(Node* node);
};

template <class X> Node<X>::Node() {
	next = NULL;
}

template <class X> X Node<X>::getData() {
	return data;
}

template <class X> void Node<X>::setData(X data) {
	this->data = data;
}

template <class X> Node<X>* Node<X>::getNext() {
	return next;
}

template <class X> void Node<X>::setNext(Node* node) {
	next = node;
}

#endif
