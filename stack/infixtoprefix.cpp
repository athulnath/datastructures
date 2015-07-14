#include<iostream>
#include "src/Stack.h"

using namespace std;

int isOperand(char operand) {
	return ((operand >= 'a' && operand <= 'z') || (operand >= 'A' && operand <= 'Z'));
}

int prec(char op) {
	switch(op) {
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

void infixToPostfix(char* exp) {
	Stack<char> *stack = new Stack<char>(100);
	int k = -1;
	for(int i = 0; exp[i]; i++) {

		if(isOperand(exp[i])) {
			exp[++k] = exp[i];	
		} else if(exp[i] == '(') {
			stack->push(exp[i]);
		} else if(exp[i] == ')') {
			while(!stack->isEmpty() && stack->peek() != '(') {
				exp[++k] = stack->pop();
			}

			if (!stack->isEmpty() && stack->peek() != '(')
                return ; // invalid expression                
            else
                stack->pop();

		} else {
			while(!stack->isEmpty() && prec(exp[i]) <= prec(stack->peek())) {
				exp[++k] = stack->pop();
			}
			stack->push(exp[i]);
		}
	}

	  // pop all the operators from the stack
    while (!stack->isEmpty())
        exp[++k] = stack->pop();
 
    exp[++k] = '\0';

	cout<<exp<<endl;
}

int main(void) {
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}