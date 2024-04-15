#include <stdio.h>
#include <stdlib.h>

struct linkList
{
    int data;
    struct linkList *next;
};
typedef struct linkList NODE;

NODE *start = NULL; // Declare the start pointer globally

// insert a node at the end
void insert_end(int item)
{
    NODE *ptr, *temp;
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    ptr->next = NULL;
    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

int main()
{

    // Inserting node at end
    insert_end(9);
    insert_end(2);
    insert_end(28);

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
