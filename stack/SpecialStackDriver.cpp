#include<iostream>
#include "src/SpecialStackL.h"

using namespace std;


int main(void) {

	SpecialStackL<int>* spStack = new SpecialStackL<int>();

	spStack->push(5);
	spStack->push(10);/**/
	// spStack->push(14);
	// spStack->push(20);
	spStack->printStack();
	cout<<spStack->getMin()<<endl;
	delete spStack;
}

