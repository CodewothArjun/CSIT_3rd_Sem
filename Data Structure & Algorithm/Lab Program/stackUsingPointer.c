#include <stdio.h>

#define SIZE 100

int stack[SIZE], *top = NULL;

void push(int value);
int pop();
void display();

int main()
{
    int choice, value;

    top = stack; // Initialize top to the beginning of the stack array

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
                printf("Popped element: %d\n", value);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void push(int value)
{
    if (top == stack + SIZE - 1)
    {
        printf("Stack Overflow. Cannot push element.\n");
    }
    else
    {
        *top = value;
        top++;
        printf("Element %d pushed to the stack.\n", value);
    }
}

int pop()
{
    int value = -1; // Default value for an empty stack

    if (top == stack)
    {
        printf("Stack Underflow. Cannot pop element.\n");
    }
    else
    {
        top--;
        value = *top;
    }

    return value;
}

void display()
{
    if (top == stack)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements:\n");
        for (int *ptr = top - 1; ptr >= stack; ptr--)
        {
            printf("%d\n", *ptr);
        }
    }
}
