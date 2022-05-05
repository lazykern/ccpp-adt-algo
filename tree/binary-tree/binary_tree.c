#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    int data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

typedef struct
{
    BTNode *root;
    int size;
} BinaryTree;

BTNode *new_btnode(int data)
{
    BTNode *node = (BTNode *)malloc(sizeof(BTNode *));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BinaryTree *new_binarytree()
{
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree *));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

void set_root_data(BinaryTree *tree, int data)
{

    if (tree->root == NULL)
    {
        BTNode *root_node = new_btnode(data);
        tree->root = root_node;
        tree->size = 1;
        return;
    }

    tree->root->data = data;
}

void set_node_data(BTNode *node, int data)
{
    node->data = data;
}

void insert_left_child(BinaryTree *tree, BTNode *parent, int data)
{
    if (parent == NULL)
    {
        printf("Parent node is NULL\n");
        return;
    }

    if (parent->left != NULL)
    {
        printf("Left child already exists\n");
        return;
    }

    BTNode *left_child = new_btnode(data);
    parent->left = left_child;
    tree->size++;
}

void insert_right_child(BinaryTree *tree, BTNode *parent, int data)
{
    if (parent == NULL)
    {
        printf("Parent node is NULL\n");
        return;
    }

    if (parent->right != NULL)
    {
        printf("Right child already exists\n");
        return;
    }

    BTNode *right_child = new_btnode(data);
    parent->right = right_child;
    tree->size++;
}

/******************************************************************************/
/*
    Stack implementation for binary tree nodes.
*/

typedef struct BTNodeStackNode
{
    BTNode *data;
    struct BTNodeStackNode *next;
} BTNodeStackNode;

typedef struct
{
    BTNodeStackNode *top;
    unsigned int size;
} BTNodeStack;

BTNodeStackNode *new_btnode_stack_node(BTNode *data)
{
    BTNodeStackNode *node = (BTNodeStackNode *)malloc(sizeof(BTNodeStackNode *));
    node->data = data;
    node->next = NULL;
    return node;
}

BTNodeStack *new_btnode_stack()
{
    BTNodeStack *stack = (BTNodeStack *)malloc(sizeof(BTNodeStack *));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

BTNode *pop(BTNodeStack *stack)
{
    BTNode *data = NULL;
    if (stack->top == NULL)
    {
        return data;
    }

    BTNodeStackNode *temp_node = stack->top;
    stack->top = temp_node->next;
    data = temp_node->data;
    free(temp_node);
    return data;
}

BTNode *peek(BTNodeStack *stack)
{
    if (stack->top == NULL)
    {
        return NULL;
    }

    return stack->top->data;
}

void push(BTNodeStack *stack, BTNode *data)
{
    BTNodeStackNode *node = new_btnode_stack_node(data);

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

int is_empty(BTNodeStack *stack)
{
    if (stack->top == NULL)
    {
        return 1;
    }
    return 0;
}


/******************************************************************************/

void preorder_display(BinaryTree *tree)
{

    BTNodeStack *stack = new_btnode_stack();
    BTNode *curr_node = tree->root;

    while (!is_empty(stack) || curr_node != NULL)
    {
        while (curr_node != NULL)
        {
            printf("%d ", curr_node->data);

            if (curr_node->right != NULL){
                push(stack, curr_node->right);
            }
            curr_node = curr_node->left;
        }
        
        if (!is_empty(stack)) {
            curr_node = pop(stack);
        }
    }
    printf("\n");
    
}




int main()
{
    BinaryTree *tree = new_binarytree();
    set_root_data(tree, 10);
    insert_left_child(tree, tree->root, 20);
    insert_right_child(tree, tree->root, 30);
    insert_left_child(tree, tree->root->left, 40);
    insert_right_child(tree, tree->root->left, 50);
}