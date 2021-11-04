#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int size;
    int top;
    int *storage;
} stack_array_t;

void push(int value, stack_array_t *stack) {
    if(stack->top == stack->size - 1) {
        return;
    }
    stack->storage[++stack->top] = value;
}

int pop(stack_array_t *stack) {
    if(stack->top == -1) {
        return 0;
    }

    int lastElement = stack->storage[stack->top];
    
    stack->storage[stack->top] = 0;
    stack->top--;

    return lastElement;
}

int top(stack_array_t *stack) {
    if(stack->top == -1) {
        return 0;
    }
    
    return stack->storage[stack->top];
}

int *createStackStorage(int size) {
    int *stackStorage = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        stackStorage[i] = 0;
    }
    return stackStorage;
}

void printStack(stack_array_t *stack) {
    int i = stack->top;
    while (i >= 0)
    {
        if(stack->storage[i] == 0) {
            i--;
            continue;
        }
        printf("------\n| %d  |\n", stack->storage[i]);
        i--;
    }
    printf("------\n");
}

int main() {
    int *stackStorage = createStackStorage(10);
    
    stack_array_t myStack;
    
    myStack.size = 10;
    myStack.top = -1;
    myStack.storage = stackStorage;

    push(1, &myStack);
    push(2, &myStack);
    pop(&myStack);
    push(3, &myStack);
    push(4, &myStack);
    push(5, &myStack);
    pop(&myStack);
    push(11, &myStack);
    pop(&myStack);
    push(12, &myStack);
    push(20, &myStack);

    printStack(&myStack);
    
    return 0;
}