#include<iostream>
#include "src/Stack.h"

using namespace std;

int main(void) {

	Stack<char> *stack = new Stack<char>(5);
	for(int i = 1; i <= 7; i++) {
		stack->push('a');	
	}

	for(int i = 1; i <= 6; i++) {
		cout<<stack->pop()<<endl;	
	}	

	
 	return 0;
}