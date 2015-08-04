#include<iostream>
#include "src/TwoStacks.h"

using namespace std;

int main(void) {

	TwoStacks<int> *stack = new TwoStacks<int>(10);
	stack->push1(12);
	stack->push1(13);
	stack->push1(14);
	stack->push1(15);


	stack->push2(22);
	stack->push2(23);
	stack->push2(24);
	stack->push2(25);

	cout<<stack->pop1()<<endl;
	cout<<stack->pop1()<<endl;
	cout<<stack->pop1()<<endl;
	cout<<stack->pop1()<<endl;
	cout<<stack->pop1()<<endl;
	cout<<stack->pop2()<<endl;
	cout<<stack->pop2()<<endl;
	cout<<stack->pop2()<<endl;
	cout<<stack->pop2()<<endl;
	cout<<stack->pop2()<<endl;

	delete stack;
	return 0;
}
