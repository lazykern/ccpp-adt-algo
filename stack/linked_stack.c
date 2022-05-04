#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
    unsigned int size;
} LinkedStack;

Node *new_node(int data)
{
    Node *node = NULL;
    node = (Node *)malloc(sizeof(Node *));
    node->data = data;
    node->next = NULL;

    return node;
}

LinkedStack *new_linkedstack()
{
    LinkedStack *stack = NULL;
    stack = (LinkedStack *)malloc(sizeof(LinkedStack *));
    stack->top = NULL;
    stack->size = 0;

    return stack;
}

void push(LinkedStack *stack, int data)
{
    Node *node = new_node(data);

    if (stack->top == NULL)
    {
        stack->top = node;
    }
    else
    {
        node->next = stack->top;
        stack->top = node;
    }
    ++stack->size;
}

int pop(LinkedStack *stack)
{
    int data;
    if (stack->top == NULL) {
        return data;
    }
    Node *temp_node = stack->top;
    stack->top = temp_node->next;
    data = temp_node->data;
    free(temp_node);
    return data;
}

int peek(LinkedStack *stack)
{
    if (stack->top == NULL)
    {
        int data;
        return data;
    }
    return stack->top->data;
}

void display(LinkedStack *stack)
{
    Node *node = stack->top;
    while (node != NULL)
    {
        printf("%d|", node->data);
        node = node->next;
    }
    printf("\n");
}

int is_empty(LinkedStack *stack)
{
    return stack->top == NULL;
}

int is_full(LinkedStack *stack)
{
    Node *node = new_node(0);
    if (node == NULL) return 1;
    else
    {
        free(node);
        return 0;
    }
}