/*
Write a program that uses functions to perform the
following operations on singly linked list
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

// Define the Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new Node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a Node at the beginning of the list
void insertBeginning(struct Node **headRef, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a Node at a specified position
void insertAtPosition(struct Node **headRef, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1 || *headRef == NULL) {
        insertBeginning(headRef, data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *current = *headRef;
    for (int i = 1; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert a Node at the end of the list
void insertEnd(struct Node **headRef, int data) {
    struct Node *newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node *current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a Node from the beginning of the list
void deleteBeginning(struct Node **headRef) {
    if (*headRef == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    struct Node *temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
}

// Function to delete a Node from a specified position
void deleteAtPosition(struct Node **headRef, int position) {
    if (*headRef == NULL || position < 1) {
        printf("List is empty or invalid position. Deletion not possible.\n");
        return;
    }
    if (position == 1) {
        deleteBeginning(headRef);
        return;
    }
    struct Node *current = *headRef;
    struct Node *prev = NULL;
    for (int i = 1; i < position && current != NULL; i++) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->next = current->next;
    free(current);
}

// Function to delete a Node from the end of the list
void deleteEnd(struct Node **headRef) {
    if (*headRef == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        return;
    }
    struct Node *current = *headRef;
    struct Node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}

// Function to traverse the list and print all elements
void traverse(struct Node *head) {
    struct Node *current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free all memory allocated for the list
void freeList(struct Node **headRef) {
    struct Node *current = *headRef;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

// Main function to run the program
int main() {
    struct Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nOperations on Singly Linked List:\n");
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

        switch (choice) {
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
