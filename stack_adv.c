#include <stdio.h>
#include <stdlib.h>

const int size = 10;  // any size

typedef struct node
{
    int num;

    struct node *next;

} node;

int push(node **stack, int num, int *top);

int pop (node **stack, int *top);

int main(void)
{
    node *stack = NULL;

    int top = -1;  // stack is empty

    for (int i = 0; i < size; i++)
    {
        top = push(&stack, 5, &top);
    }

    top = pop(&stack, &top);

    printf("%i\n", top);

    // Printing the stack

    for (node *ptr = stack; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->num);
    }

    printf("\n");

    return 0;
}

int push(node **stack, int num, int *top)
{
    if (*top == size - 1)
    {
        return 179; // Custom error code for stack overflow
    }

    node *new_num = malloc(sizeof(node));

    if (new_num == NULL)
    {
        return -1; // Memory allocation failed
    }

    new_num->num = num;

    new_num->next = NULL;

    if (*stack == NULL)  // If stack is empty, initialize with the new node
    {
        *stack = new_num;
    }

    else  // Traverse to the end and insert the new node
    {
        for (node *ptr = *stack; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->next == NULL)
            {
                ptr->next = new_num;

                break;
            }
        }
    }

    (*top)++;  // Increment top after inserting the new node

    return *top;
}

int pop (node **stack, int *top)
{
    if (*top == -1)
    {
        return -179; //custom error code for underflow
    }

    else
    {
        for (node *ptr = *stack; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->next->next == NULL)
            {
                ptr->next = NULL;

                break;
            }
        }

        (*top)--;
    }

    return *top;
}