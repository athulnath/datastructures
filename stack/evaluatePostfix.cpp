#include<iostream>
#include "src/StackL.h"

using namespace std;

bool isOperand(char op) {
	return op >= '0' && op <= '9';
}

int evaluatePostfix(char* exp) {
	StackL<int> *stack = new StackL<int>();

	int interRes, val1, val2;

	for(int i = 0; exp[i]; i++) {
		interRes = 0;
		if(isOperand(exp[i])) {
			stack->push((int)exp[i] - '0');
		} else {
				val1 = stack->pop();
				val2 = stack->pop();

				switch(exp[i]) {
					case '+': 
							interRes = val2 + val1;
							break;	
					case '-': 
							interRes = val2 - val1;
							break;			
					case '*': 
							interRes = val2 * val1;
							break;	
					case '/': 
							interRes = val2 / val1;
							break;	
					case '^': 
							interRes = val2 ^ val1;
							break;	
				}

				stack->push(interRes);
			}

		}

	int res = stack->pop();
	delete stack;
	return res;
}


int main(void) {

	char exp[] = "4572+-*";
	cout<<evaluatePostfix(exp)<<endl;

}
