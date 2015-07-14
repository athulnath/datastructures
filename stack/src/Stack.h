#ifndef __STACK_H_INCLUDE__
#define __STACK_H_INCLUDE__

template <class stackType> class Stack {
	stackType *p;
	int capacity, top;
public: 
	Stack(int capacity);
	~Stack();
	void push(stackType data);
	stackType pop();
	stackType peek();
	bool isEmpty();
	bool isFull();
};


template <class stackType> Stack<stackType>::Stack(int capacity) {
	this->top = -1;
	this->capacity = capacity;
	this->p = new stackType[capacity];
}

template <class stackType> Stack<stackType>::~Stack() {
	delete[] this->p;
}

template <class stackType> bool Stack<stackType>::isEmpty() {
	return this->top == -1;
}

template <class stackType> bool Stack<stackType>::isFull() {
	return this->top == this->capacity - 1;
}

template <class stackType> void Stack<stackType>::push(stackType data) {
  if(this->isFull()) {
  	std::cout<<"Stack is Full"<<std::endl;
  	return;
  }

  *(this->p + (++this->top)) = data;
}

template <class stackType> stackType Stack<stackType>::pop() {
	if(this->isEmpty()) {
		std::cout<<"Stack is empty!!"<<std::endl;
		stackType tmp;
		return tmp;
	}

	return *(this->p + (this->top--));
}

template <class stackType> stackType Stack<stackType>::peek() {
	if(this->isEmpty()) {
		std::cout<<"Stack is empty!!"<<std::endl;
		stackType tmp;
		return tmp;
	}

	return *(this->p + this->top);
}

#endif