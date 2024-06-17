/*
Write a program that uses functions to perform the
following operations on circular linked List
a) Creation
b) Insertion
 1) Insertion at beginning
 2) Insertion at specified position
 3) Insertion at end
c) Deletion
 1) Deletion from the beginning
 2) Deletion from the specified position
 3) Deletion from the end
d) Traversal.
 e) Exit
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(struct Node **headRef, int data)
{
    struct Node *newNode = createNode(data);
    if (*headRef == NULL)
    {
        newNode->next = newNode;
        *headRef = newNode;
    }
    else
    {
        struct Node *last = *headRef;
        while (last->next != *headRef)
        {
            last = last->next;
        }
        newNode->next = *headRef;
        last->next = newNode;
        *headRef = newNode;
    }
}

void insertAtPosition(struct Node **headRef, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1)
    {
        insertBeginning(headRef, data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *current = *headRef;
    for (int i = 1; i < position - 1 && current->next != *headRef; i++)
    {
        current = current->next;
    }
    if (current->next == *headRef && position > 1)
    {
        printf("Position out of range.\n");
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void insertEnd(struct Node **headRef, int data)
{
    struct Node *newNode = createNode(data);
    if (*headRef == NULL)
    {
        newNode->next = newNode;
        *headRef = newNode;
    }
    else
    {
        struct Node *last = *headRef;
        while (last->next != *headRef)
        {
            last = last->next;
        }
        newNode->next = *headRef;
        last->next = newNode;
    }
}

void deleteBeginning(struct Node **headRef)
{
    if (*headRef == NULL)
    {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    if ((*headRef)->next == *headRef)
    {
        free(*headRef);
        *headRef = NULL;
    }
    else
    {
        struct Node *last = *headRef;
        while (last->next != *headRef)
        {
            last = last->next;
        }
        struct Node *temp = *headRef;
        *headRef = (*headRef)->next;
        last->next = *headRef;
        free(temp);
    }
}

void deleteAtPosition(struct Node **headRef, int position)
{
    if (*headRef == NULL)
    {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    if (position < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1)
    {
        deleteBeginning(headRef);
        return;
    }
    struct Node *current = *headRef;
    struct Node *prev = NULL;
    for (int i = 1; i < position && current->next != *headRef; i++)
    {
        prev = current;
        current = current->next;
    }
    if (current->next == *headRef && position > 1)
    {
        printf("Position out of range.\n");
        return;
    }
    prev->next = current->next;
    free(current);
}

void deleteEnd(struct Node **headRef)
{
    if (*headRef == NULL)
    {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    if ((*headRef)->next == *headRef)
    {
        free(*headRef);
        *headRef = NULL;
    }
    else
    {
        struct Node *current = *headRef;
        struct Node *prev = NULL;
        while (current->next != *headRef)
        {
            prev = current;
            current = current->next;
        }
        prev->next = *headRef;
        free(current);
    }
}

void traverse(struct Node *head)
{
    struct Node *temp = head;
    printf("Circular Linked List: ");
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

void freeList(struct Node **headRef)
{
    if (*headRef == NULL)
    {
        return;
    }
    struct Node *temp = *headRef;
    while (temp->next != *headRef)
    {
        struct Node *del = temp;
        temp = temp->next;
        free(del);
    }
    free(temp);
    *headRef = NULL;
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    while (1)
    {
        printf("\nOperations on Circular Linked List:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Specified Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from Specified Position\n");
        printf("6. Delete from End\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            insertBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;
        case 3:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertEnd(&head, data);
            break;
        case 4:
            deleteBeginning(&head);
            break;
        case 5:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        case 6:
            deleteEnd(&head);
            break;
        case 7:
            traverse(head);
            break;
        case 8:
            freeList(&head);
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}
