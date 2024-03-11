// Making a menu
#include <stdio.h>
#define size 100
int n, tos = -1, stack[size], i, j;
void push()
{
    int val;
    if (tos == n - 1)
    {
        printf("\n\n-------------------------------------------\nYour Menu is fulled of order \n-------------------------------------------");
    }
    else
    {
        printf("Enter the items you want to order: ");
        scanf("%d", &val);
        tos++;
        stack[tos] = val;
    }
}
void pop()
{
    if (tos == -1)
    {
        printf("\n\n-------------------------------------------\nYour Menu is Empty \n-------------------------------------------");
    }
    else
    {
        printf("\n\n-------------------------------------------\nYou early ordered Item: %d\n", stack[tos]);
        printf("\n-------------------------------------------");
        tos--;
    }
}
void traversal()
{
    if (tos == -1)
    {
        printf("\n\n-------------------------------------------\nYou doesn't have order any items \n-------------------------------------------");
    }
    else
    {
        printf("Travesal");
        for (i = tos; i >= 0; i--)
        {
            printf("\n\n-------------------------------------------\n");
            printf("stack[%d] = %d", i, stack[i]);
            printf("\n-------------------------------------------");
        }
    }
}
int main()
{
    int choice = 0;
    printf("Enter the no. of choice: ");
    scanf("%d", &n);
    printf("\n*** Stack Operation Using Array ***\n");
    do
    {
        printf("\n\nChoose any one fromm the below options:: ");
        printf("\n1. PUSH\n2. POP\n3. Traverse\n4. Exit\n");
        printf("\nEnter your choice (1/2/3/4): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traversal();
            break;
        case 4:
            printf("\nExiting.........\n");
            break;

        default:
            printf("\nEnter a valid choice...\n");
        }
    }while (choice != 4);

    return 0;
}