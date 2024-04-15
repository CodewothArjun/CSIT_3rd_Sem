#include <stdio.h>
#include <stdlib.h>

struct linkList
{
    int data;
    struct linkList *next;
};
typedef struct linkList NODE;

NODE *start = NULL; // Declare the start pointer globally

void insert_at_begin(int item)
{
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    if (start == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        ptr->next = start;
    }
    start = ptr;
}

int main()
{
    // Example usage
    insert_at_begin(5);
    insert_at_begin(10);
    insert_at_begin(100);
    insert_at_begin(15);

    // Printing the linked list
    NODE *temp = start;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
