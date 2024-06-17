/*
Write a menu driven program to illustrate basic operations of
stack using array.
a) Push
b) Pop
c) Traverse
d) Exit
*/

#include <stdio.h>
#define SIZE 100

int stack[SIZE], top = -1;
void push(int value);
int pop();
void display();

int main()
{
    int choice, value;
    do
    {
        printf("\n---- Menu ----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            value = pop();
            if (value != -1)
                printf("\nPopped element: %d\n", value);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\n**Exiting the program.**\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("** ! Stack Overflow. Cannot push element.**\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("Element %d pushed to the stack.\n", value);
    }
}

int pop()
{
    int value = -1; // Default value for an empty stack

    if (top == -1)
    {
        printf("** ! Stack Underflow. Cannot pop element.**\n");
    }
    else
    {
        value = stack[top];
        top--;
    }

    return value;
}

void display()
{
    if (top == -1)
    {
        printf("\n**Stack is empty.**\n");
    }
    else
    {
        printf("\nStack elements:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
