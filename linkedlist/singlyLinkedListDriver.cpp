#include<iostream>
#include "src/SinglyLinkedList.h"

using namespace std;

int main(void) {

	SinglyLinkedList<int> *list = new SinglyLinkedList<int>();

	for(unsigned int i = 0; i < 5; i++) {
		list->push(i);	
	}

	list->append(-1);
	list->append(-2);


	list->printList();

	list->deleteNode(-1);

	list->printList();

	list->deleteNode(4);

	list->printList();

	list->deleteNode(-2);

	list->printList();

	delete list;
}