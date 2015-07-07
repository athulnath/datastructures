#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct StackNode {
	long long int data;
	StackNode* next;
};

struct StackNode* createNode(long long int data) {
	struct StackNode* node = (StackNode* )malloc(sizeof(struct StackNode));
	node->data = data;
	node->next = NULL;
	return node;
}

int isEmpty(struct StackNode *root) {
	return !root;
}

void push(struct StackNode** root, long long int data) {
	struct StackNode* node = createNode(data);
	node->next = *root;
	*root = node;
	printf("push success %lld\n", data);
}

int pop(struct StackNode** root) {
	if(isEmpty(*root)) {
		printf("Stack is Empty!!!\n");
		return INT_MIN;
	}

	struct StackNode* tmp = *root;
	*root = (*root)->next;
	int poped = tmp->data;
	free(tmp);
	return poped;
}
 
int main(void) {

	struct StackNode* root = NULL;
	long long int n = 100;
	for(long long int i = 1; i < n; i++) {
		push(&root, i);	
	}
	
	for(int i = 1; i < n + 1; i++) {
		printf("Pop: %d\n", pop(&root));
	}

	free(root);
}