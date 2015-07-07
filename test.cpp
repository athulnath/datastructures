#include<iostream>

#define STACK_SIZE 100

using namespace std;

class Stack {

	int stack[STACK_SIZE];
	int pos;

public:
	Stack();
	int push(int data);
	int pop();
};

Stack::Stack() {
	this->pos = -1;
}

int Stack::push(int data) {

	if(this->pos <= STACK_SIZE) {
		this->stack[++this->pos] = data;	
		cout<<"push success"<<endl;
		return 1;
	} else {
		return -1;
	}
}

int Stack::pop() {
	if(this->pos < 0) {
		cout<<"empty stack"<<endl;
		return -1;
	} else {
		return this->stack[this->pos--];
	}
}

int main(void) {

	Stack myStack;

	myStack.push(12313);
	myStack.push(22);
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
}



