#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack {
	int top;
	int* array;
	unsigned int capacity;
};

void freeArray(struct Stack* stack) {
	free(stack->array);
}

struct Stack* createStack(unsigned int capacity) {
	struct Stack* stack = (struct Stack *) malloc(sizeof(struct Stack));
	stack->top =  -1;
	stack->capacity = capacity;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack) {
	return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
	return stack->top == -1;
}

void push(struct Stack* stack, int data) {
	if(isFull(stack)) {
		printf("Stack is full!!!\n");
		return;
	}
	stack->array[++stack->top] = data;
	printf("Item pushed to stack %d:%d\n", stack->top, data);
}

int pop(struct Stack* stack) {
	if(isEmpty(stack)) {
		printf("Stack is empty!!\n");
		return INT_MIN;
	}
	return stack->array[stack->top--];
}



//stack driver 
int main(void) {
	struct Stack* stack = createStack(1);

	push(stack, 12);
	push(stack, 13);
	push(stack, 14);

	printf("Pop: %d\n", pop(stack));
	printf("Pop: %d\n", pop(stack));
	printf("Pop: %d\n", pop(stack));
	printf("Pop: %d\n", pop(stack));


	freeArray(stack);
	free(stack);
	return 0;
} 