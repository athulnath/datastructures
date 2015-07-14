#include<iostream>
#include "Stack.h"
#include "Stack.h"
using namespace std;

int main(void) {

	Stack *stack = new Stack(3);

	stack->push(12);
	stack->push(13);
	stack->push(14);
	stack->push(15);


	stack->push(16);

	//while(!stack->isEmpty()) {
		//cout<<"item poped: " << stack->pop()<<endl;
	//}

	std::cout<<"peek item: "<<stack->peek()<<std::endl;
	delete stack;
	return 0;
}