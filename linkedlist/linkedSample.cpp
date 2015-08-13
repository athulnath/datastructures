#include<iostream>
#include<cstdlib>

using namespace std;

struct node {
	int data;
	node *next;
};

void printList(node *node) {
	while(node) {
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;
} 

void push(node **head, int data) {
	node *newdata = (node *)malloc(sizeof(node));
	newdata->data = data;
	newdata->next = (*head);
	(*head) = newdata;
}

void insertAfter(node *prev, int data) {
	if(prev == NULL) {
		cout<<"prev node cannot be null"<<endl;
		return;
	}

	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = prev->next;
	prev->next = newnode;
}

void append(node *head, int data) {

	//creating new node
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;

	while(head->next) {
		head = head->next;
	}

	head->next = newnode;
}

void deleteNode(node **head, int key) {
	if(head == NULL) {
		cout<<"null list"<<endl;
		return;
	}

	node *tmp = *head, *prev;

	if(tmp->data == key) {
		*head = tmp->next;
		free((tmp));
		return;
	}

	while(tmp->data != key && tmp != NULL) {
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	free(tmp);
	return;
}

int main(void) {

	node *first = (node *)malloc(sizeof(node));
	node *second = (node *)malloc(sizeof(node));
	node *third = (node *) malloc(sizeof(node));

	first->data = 1;
	first->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;
 	
	printList(first);
	push(&first, 4);
	cout<<endl;
	insertAfter(second, 8);
	append(first, 10);
	printList(first);

	deleteNode(&first, 4);
	deleteNode(&first, 8);
	
	printList(first);	
	delete first;
	delete second;
	delete third;
	return 0;
}