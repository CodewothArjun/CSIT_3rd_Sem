#include <stdio.h>
#define size 50
int tos = -1, n, stack[size], i;

// Function
void push(int *tos, int stack[], int n)
{
    int value;
    if (*tos == n - 1)
    {
        printf("\nThe stack is overflow.");
    }
    else
    {
        printf("\nEnter an items: ");
        scanf("%d", &value);
        (*tos)++;
        stack[*tos] = value;
    }
}

void pop(int *tos, int stack[])
{
    printf("\nPoping an items: %d ", stack[*tos]);
    (*tos)--;
}

void transveral(int *tos, int stack[])
{
    if (*tos == -1)
    {
        printf("The stack is Empty.");
    }
    else
    {
        printf("Traversal of items: \n");
        for (i = *tos; i >= 0; i--)
        {
            printf("%d\t\t", stack[*tos]);
        }
    }
}

// main
int main()
{
    printf("\nEnter the no. of choice: ");
    scanf("%d", &n);
    int choice = 0;
    while (choice != 4)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&tos, stack, n);
            break;
        case 2:
            pop(&tos, stack);
            break;

        case 3:
            transveral(&tos, stack);
            break;
        case 4:
            printf("Exit");
        }
    }
    return 0;
}