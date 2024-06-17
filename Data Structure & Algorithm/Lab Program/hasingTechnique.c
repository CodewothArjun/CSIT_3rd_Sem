// Write a program to implement the hashing techniques.
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Structure for a node in the hash table
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize hash table
struct Node **initializeHashTable()
{
    struct Node **hashTable = (struct Node **)malloc(SIZE * sizeof(struct Node *));
    if (!hashTable)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = NULL;
    }
    return hashTable;
}

// Function to insert data into hash table
void insert(struct Node **hashTable, int key)
{
    int index = key % SIZE;
    struct Node *newNode = createNode(key);
    if (!hashTable[index])
    {
        hashTable[index] = newNode;
    }
    else
    {
        struct Node *temp = hashTable[index];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for data in hash table
int search(struct Node **hashTable, int key)
{
    int index = key % SIZE;
    struct Node *temp = hashTable[index];
    while (temp)
    {
        if (temp->data == key)
        {
            return 1; // Key found
        }
        temp = temp->next;
    }
    return 0; // Key not found
}

// Function to free memory allocated for hash table
void freeHashTable(struct Node **hashTable)
{
    for (int i = 0; i < SIZE; i++)
    {
        struct Node *temp = hashTable[i];
        while (temp)
        {
            struct Node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(hashTable);
}

int main()
{
    struct Node **hashTable = initializeHashTable();

    int choice, key;
    char ch;

    do
    {
        printf("\n1. Insert key\n");
        printf("2. Search key\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(hashTable, key);
            break;
        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            if (search(hashTable, key))
                printf("Key %d found\n", key);
            else
                printf("Key %d not found\n", key);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

        // Clear input buffer
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

    } while (choice != 3);

    freeHashTable(hashTable);

    return 0;
}
