#include <stdio.h>
#include "linked_stack.c"

int is_open(char c)
{
    return c == '(' || c == '[' || c == '{' || c == '<';
}

int is_close(char c)
{
    return c == ')' || c == ']' || c == '}' || c == '>';
}

int hash(char c)
{
    if (c == '(' || c == ')')
        return 1;
    if (c == '[' || c == ']')
        return 2;
    if (c == '{' || c == '}')
        return 3;
    if (c == '<' || c == '>')
        return 4;

    return 0;
}

int main()
{
    char c;
    char *string = (char *)malloc(sizeof(char));
    int length = 0;
    while (1)
    {
        scanf("%c", &c);
        if (c == '\n')
            break;
        string[length++] = c;
        string = (char *)realloc(string, sizeof(char) * (length + 1));
    }
    string[length] = '\0';

    LinkedStack *stack = new_linkedstack();

    int i = 0;
    for (i; i < length; ++i)
    {
        if (is_open(string[i]))
            push(stack, hash(string[i]));
        else if (is_close(string[i]))
        {
            if (is_empty(stack))
            {
                printf("No\n");
                return 0;
            }
            if (hash(string[i]) != pop(stack))
            {
                printf("No\n");
                return 0;
            }
        }
    }

    if (is_empty(stack))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}