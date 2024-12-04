#include <stdio.h>
#include <stdlib.h>

const int size = 10;

int push (int arr[], int size, int top, int num);

int pop (int arr[], int top);

int top (int arr[], int top);

int isEmpty (int arr[], int top);

int main (void)
{
    int top = -1; // for empty stack

    int arr[size]; //create an array of choice and conduct the desired operations

    return 0;
}

int push (int arr[], int size, int top, int num)
{
    if (top == size - 1)
    {
        printf("Overflow\n");
    }

    else
    {
        top++;

        arr[top] = num;
    }

    return top;
}


int pop (int arr[], int top)
{
    if (top == -1)
    {
        printf("Underflow\n");
    }

    else
    {
        printf("Element popped: %i\n", arr[top]);

        top--;
    }

    return top;
}

int top (int arr[], int top)
{
    if (top != -1)
    {
        return arr[top];
    }
    
    else
    {
        return -100; //some error value
    }
}

int isEmpty (int arr[], int top)
{
    if (top == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}