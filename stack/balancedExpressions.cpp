#include<iostream>
#include "src/StackL.h"

using namespace std;

bool isBalanced(char* exp) {
	bool isBalanced = true;
	StackL<char> *stack = new StackL<char>();
	for(int i = 0; exp[i]; i++) {

		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
			stack->push(exp[i]);
		}

		if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
			if(!stack->isEmpty()) {
				if(stack->pop() == exp[i]) {
				isBalanced = false;
				}	
			} else {
				isBalanced = false;
			}
			
		}
	}

	if(!stack->isEmpty()) {
		isBalanced = false;	
	}

	delete stack;
	return isBalanced;
}

int main(void) {
	char exp[] = "(((())))]";
	if(isBalanced(exp)) {
		cout<<"Balanced"<<endl;
	} else {
		cout<<"Not Balanced"<<endl;
	}
}
 
