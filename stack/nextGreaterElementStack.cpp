#include<iostream>
#include "src/StackL.h"

using namespace std;

void display(int ele, int gt) {
	cout<<ele<<" --->  "<<gt<<endl;
}

void printNGE(int* arr, int size) {
	StackL<int>* stack = new StackL<int>();
	stack->push(arr[0]);
	int next, element;
	for(int i = 1; i < size; i++) {
		next = arr[i];
		if(!stack->isEmpty()) {
			element = stack->pop();
			while(element < next) {
				display(element, next);
				if(stack->isEmpty()) {
					break;
				}
				element = stack->pop();
			}

			if(element > next) {
				stack->push(element);
			}
		}

		stack->push(next);
	}

	while(!stack->isEmpty()) {
		element = stack->pop();
		display(element, -1);
	}
}

int main() {

int arr[] = {4, 2, 1, 3};
int size = sizeof(arr) / sizeof(arr[0]);;
printNGE(arr, size);
return 0;
}