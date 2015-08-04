#ifndef __STACKL_HEADER__
#define __STACKL_HEADER__

#include "Node.h"

template <class X> class StackL {
private:
	Node<X> *root;
	Node<X>* createNode(X data);
public:
	StackL();
	~StackL();

	void push(X data);
	X pop();
	X peek();
	bool isEmpty();
	void printStack();
};

template <class X> StackL<X>::StackL() {
	root = NULL;
}

template <class X> StackL<X>::~StackL() {
	delete root;
}

template <class X> bool StackL<X>::isEmpty() {
	return !root;
}

template <class X> void StackL<X>::push(X data) {
	Node<X> *tmpNode = new Node<X>();
	tmpNode->setData(data);
	if(root == NULL) {
		root = tmpNode;
		root->setNext(NULL);
	} else {
		tmpNode->setNext(root);
		root = tmpNode;
	}
}

template <class X> void StackL<X>::printStack() {
	Node<X> *tmp = root;
	while(tmp != NULL) {
		std::cout<<tmp->getData()<<"-->";
		tmp = tmp->getNext();
	}
	std::cout<<std::endl;
}

template <class X> X StackL<X>::pop() {
	if(!isEmpty()) {
		X tmp = root->getData();
		root = root->getNext();
		return tmp;
	}

	X tmp;
	return tmp;	
}

template <class X> X StackL<X>::peek() {
	return root->getData();
}

#endif

