#include<iostream>
#include "src/StackL.h"

using namespace std;


int main(void) {

	StackL<int> *testObj = new StackL<int>();
	testObj->push(12);
	testObj->push(13);
	testObj->push(14);
	testObj->push(15);
	testObj->push(16);

	
	testObj->printStack();

	cout<<testObj->pop()<<endl;

	testObj->printStack();
	cout<<testObj->peek()<<endl;
	testObj->printStack();
	delete testObj;

	return 0;
}