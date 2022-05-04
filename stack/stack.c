#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int *data;
    unsigned int size;
} Stack;

Stack *new_stack(unsigned int size)
{
    Stack *stack = NULL;
    stack = (Stack *)malloc(sizeof(Stack *));
    stack->data = (int *)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}


int peek(Stack *stack)
{
    return stack->data[stack->top];
}

int push(Stack *stack, int value)
{
    if (stack->top == stack->size-1) {
        return 0;
    }
    stack->data[++stack->top] = value; 
    return 1;
}

int pop(Stack *stack)
{
    if (stack->top == -1) stack->top = 0;
    return stack->data[stack->top--];
}

int is_empty(Stack *stack)
{
    return stack->top == -1;
}

int is_full(Stack *stack)
{
    return stack->top == stack->size-1;
}

int display(Stack *stack)
{
    int i = stack->top;
    for (i; i > -1; --i) {
        printf("%d|", stack->data[i]);
    }
    printf("\n");
}