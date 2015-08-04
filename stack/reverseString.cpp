#include<iostream>
#include "src/StackL.h"

using namespace std;

void reverse(char* exp) {

	StackL<char> *stack = new StackL<char>();

	for(int i = 0; exp[i]; i++) {
		stack->push(exp[i]);
	}

	for(int i = 0; exp[i]; i++) {
		exp[i] = stack->pop();
	}

	delete stack;
}

int main(void) {
	char exp[] = "athulnath";
	cout<<exp<<endl;
	reverse(exp);
	cout<<exp<<endl;

}