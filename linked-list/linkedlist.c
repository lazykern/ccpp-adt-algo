#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create_node(int data)
{
    Node *node = NULL;
    node = (Node *)malloc(sizeof(Node *));
    node->data = data;
    node->next = NULL;

    return node;
}

void display(Node *head)
{
    Node *p = head;
    while (p)
    {
        printf("%d", p->data);
        p = p->next;
        if (p)
        {
            printf("-> ");
        }
    }
    printf("\n");
}

int max(Node *head)
{
    int max = head->data;
    Node *p = head->next;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int min(Node *head)
{
    int min = head->data;
    Node *p = head->next;
    while (p)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

void insert(Node **head, int data, int index)
{
    Node *p = *head;
    Node *new_node = create_node(data);
    
    if (index == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    int i = 0;
    while (p && i < index - 1)
    {
        p = p->next;
        ++i;
    }
    if (p)
    {
        new_node->next = p->next;
        p->next = new_node;
    }
}

int main()
{
    Node *head = NULL;
    head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);
    insert(&head, 6, 2);
    display(head);
    insert(&head, 7, 0);
    display(head);
}