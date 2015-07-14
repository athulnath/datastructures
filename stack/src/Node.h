#ifndef __NODE_HEADER__
#define __NODE_HEADER__

template <class X> class Node {
	X *data;
	Node *next;
public:
	Node();
	~Node();
	void setData(X &data);
	void setNext(Node* node);
	X getData();
	Node* getNext();
};

template <class X> Node<X>::Node() {
	data = new int();
	next = NULL;
}

template <class X> Node<X>::~Node() {

	delete data;
	delete next;	
}

template <class X> void Node<X>::setData(X &datas) {
	*data = datas;
}

template <class X> void Node<X>::setNext(Node* node) {
	next = node;
}

template <class X> X Node<X>::getData() {
	return *data;
}

template <class X> Node<X>* Node<X>::getNext() {
	return next;
}

#endif
