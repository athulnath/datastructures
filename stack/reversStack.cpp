#include<iostream>
#include "src/StackL.h"

using namespace std;

void insertAtBottom(StackL<int>* stack, int item) {
	int temp;
	if(stack->isEmpty()) {
		stack->push(item);
	} else {
		temp = stack->pop();
		insertAtBottom(stack, item);
		stack->push(temp);
	}
}

void reverseStack(StackL<int>* stack) {
	int tmp;
	if(!stack->isEmpty()) {
		tmp = stack->pop();
		reverseStack(stack);
		insertAtBottom(stack, tmp);
	}
}

int main(void) {
	StackL<int>* stack = new StackL<int>();
	for(int i = 0; i < 10; i++) {
		stack->push(i + 1);			 
	}
	stack->printStack();
	reverseStack(stack);
	stack->printStack();
	return 0;
}