#include<iostream>
#include "src/StackL.h"

using namespace std;

int precedence(char operat) {
	switch(operat) {
		case '+':
		case '-':
				return 1;
		case '*':
		case '/':
				return 2;
		case '^':
				return 3;
	}

	return -1;
}

bool isOPerand(char op) {
	return ((op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z'));
}

void infixToPrefix(char* exp) {

	StackL<char> *stack = new StackL<char>();

	int k = 0;
	for(int i = 0; exp[i]; i++) {
		if(isOPerand(exp[i])) {
			exp[k++] = exp[i];
		} else if(exp[i] == '('){
			stack->push(exp[i]);
		} else if(exp[i] == ')') {
			while(stack->peek() != '(' && !stack->isEmpty()) {
				exp[k++] = stack->pop();
			}

			stack->pop();
		} else {
			while(!stack->isEmpty() && precedence(stack->peek()) >= precedence(exp[i])) {
			  exp[k++] = stack->pop();
		    }
		    stack->push(exp[i]);
		}
	}

	while(!stack->isEmpty()) {
		exp[k++] = stack->pop();
	}

	exp[k++] = '\0';

	delete stack;
	cout<<exp<<endl;
}

int main(void) {

	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPrefix(exp);
	return 0;
}