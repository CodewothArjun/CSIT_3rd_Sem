/*
Write a menu driven program to illustrate basic operations of
circular queue having following menu:
a) Enqueue
b) Dequeue
c) Traverse
d) Exit
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to represent a circular queue
typedef struct
{
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

// Function prototypes
void enqueue(CircularQueue *cq, int value);
int dequeue(CircularQueue *cq);
void traverse(CircularQueue *cq);

int main()
{
    CircularQueue cq;
    cq.front = -1;
    cq.rear = -1;
    int choice, value;

    do
    {
        printf("\nCircular Queue Operations\n");
        printf("a) Enqueue\n");
        printf("b) Dequeue\n");
        printf("c) Traverse\n");
        printf("d) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'a':
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(&cq, value);
            break;
        case 'b':
            value = dequeue(&cq);
            if (value != -1)
            {
                printf("Dequeued element: %d\n", value);
            }
            break;
        case 'c':
            traverse(&cq);
            break;
        case 'd':
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 'd');

    return 0;
}

// Function to check if the queue is full
int isFull(CircularQueue *cq)
{
    return (cq->front == (cq->rear + 1) % MAX_SIZE);
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *cq)
{
    return (cq->front == -1);
}

// Function to enqueue a value into the circular queue
void enqueue(CircularQueue *cq, int value)
{
    if (isFull(cq))
    {
        printf("Queue is full, cannot enqueue\n");
    }
    else
    {
        if (cq->front == -1)
        {
            cq->front = 0;
        }
        cq->rear = (cq->rear + 1) % MAX_SIZE;
        cq->items[cq->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to dequeue a value from the circular queue
int dequeue(CircularQueue *cq)
{
    int item;
    if (isEmpty(cq))
    {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    else
    {
        item = cq->items[cq->front];
        if (cq->front == cq->rear)
        {
            cq->front = -1;
            cq->rear = -1;
        }
        else
        {
            cq->front = (cq->front + 1) % MAX_SIZE;
        }
        return item;
    }
}

// Function to traverse and display all values in the circular queue
void traverse(CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is empty, nothing to display\n");
    }
    else
    {
        printf("Elements in the circular queue: ");
        int i = cq->front;
        while (i != cq->rear)
        {
            printf("%d ", cq->items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", cq->items[i]);
    }
}
