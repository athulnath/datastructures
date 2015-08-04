#include<iostream>
#include<cstdlib>
#include "src/StackL.h"

using namespace std;


int main(void) {

	StackL<int> *testObj = new StackL<int>();

	for(int i = 0; i< 100000; i++) {
		testObj->push(rand() * 100 + 1);	
	}
	
	testObj->printStack();

	cout<<testObj->pop()<<endl;

	testObj->printStack();
	cout<<testObj->peek()<<endl;
	testObj->printStack();

	delete testObj;

	return 0;
}