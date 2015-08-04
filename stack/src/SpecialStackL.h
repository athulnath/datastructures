#ifndef __SPECIAL_SpecialStackL_HEADER__
#define __SPECIAL_SpecialStackL_HEADER__

#include "StackL.h"

template <class X> class SpecialStackL {
private:
	StackL<X> *stack;
	StackL<X> *auxilaryStack;
public:
	SpecialStackL();
	~SpecialStackL();

	void push(X data);
	X pop();
	X peek();
	bool isEmpty();
	X getMin();
	void printStack();
};

template <class X> SpecialStackL<X>::SpecialStackL() {
	stack = new StackL<X>();
	auxilaryStack = new StackL<X>();
}

template <class X> SpecialStackL<X>::~SpecialStackL() {
	delete auxilaryStack;
	delete stack;
}

template <class X> bool SpecialStackL<X>::isEmpty() {
	return stack->isEmpty();
}

template <class X> void SpecialStackL<X>::push(X data) {
	if(auxilaryStack->isEmpty() || auxilaryStack->peek() > data) {
		auxilaryStack->push(data);
	}
	stack->push(data);
}

template <class X> void SpecialStackL<X>::printStack() {
	stack->printStack();
}

template <class X> X SpecialStackL<X>::pop() {
	if(!(stack->isEmpty()) && stack->peek() == auxilaryStack->peek()) {
		auxilaryStack->pop();
	}
	return stack->pop();
}

template <class X> X SpecialStackL<X>::peek() {
	return stack->peek();
}

template <class X> X SpecialStackL<X>::getMin() {
	if(!auxilaryStack->isEmpty()) {
		auxilaryStack->peek();
	} else {
		std::cout<<"Empty"<<std::endl;
	}
}
#endif