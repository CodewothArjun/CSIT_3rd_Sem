#include <stdio.h>
#include <stdlib.h>

struct linkList
{
    int data;
    struct linkList *next;
};
typedef struct linkList NODE;

NODE *start = NULL; // Declare the start pointer globally

// function to insert node at the specific position
void insert_spe(int item, int pos)
{
    NODE *temp, *ptr;
    int i;
    temp = start;
    for (i = 1; i < pos - 1; i++)
    {
        if (temp == NULL)
        {
            printf("There are less than %d elements.\n", pos);
            return;
        }
        temp = temp->next;
    }
    ptr = (NODE *)malloc(sizeof(NODE));
    if (pos == 1) // Inserting at the beginning
    {
        ptr->data = item;
        ptr->next = start;
        start = ptr;
    }
    else
    {
        ptr->data = item;
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

int main()
{

    // Inserting node at specific positon
    insert_spe(5, 1);   // Inserting 5 at position 1
    insert_spe(10, 2);  // Inserting 10 at position 2
    insert_spe(100, 1); // Inserting 100 at position 1
    insert_spe(15, 3);  // Inserting 15 at position 3

    // Printing the linked list
    NODE *temp = start;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    return 0;
}
