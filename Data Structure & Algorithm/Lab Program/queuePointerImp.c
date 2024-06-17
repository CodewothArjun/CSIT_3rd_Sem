/*
Write a menu driven program to illustrate basic operations of
Linear queue using pointer implementation.
a) Enqueue
b) Dequeue
c) Display all values
d) Exit

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a node in the queue
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Structure to represent a queue
typedef struct
{
    Node *front;
    Node *rear;
} Queue;

// Function prototypes
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void display(Queue *q);

int main()
{
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    int choice, value;

    do
    {
        printf("\nLinear Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            value = dequeue(&q);
            if (value != -1)
            {
                printf("Dequeued element: %d\n", value);
            }
            break;
        case 3:
            display(&q);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to enqueue a value into the queue
void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Enqueued %d\n", value);
}

// Function to dequeue a value from the queue
int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }

    int value = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    return value;
}

// Function to display all values in the queue
void display(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty, nothing to display\n");
    }
    else
    {
        printf("Elements in the queue: ");
        Node *current = q->front;
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
