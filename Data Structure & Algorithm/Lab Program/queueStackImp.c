#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a queue
typedef struct
{
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void display(Queue *q);

int main()
{
    Queue q;
    q.front = -1;
    q.rear = -1;
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
            if (q.front == -1)
            {
                printf("Queue is empty, cannot dequeue\n");
            }
            else
            {
                printf("Dequeued element: %d\n", dequeue(&q));
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
    if (q->rear == MAX_SIZE - 1)
    {
        printf("Queue is full, cannot enqueue\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0; // Set front to 0 for the first element
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to dequeue a value from the queue
int dequeue(Queue *q)
{
    int item;
    if (q->front == -1)
    {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    else
    {
        item = q->items[q->front];
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front++;
        }
        return item;
    }
}

// Function to display all values in the queue
void display(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty, nothing to display\n");
    }
    else
    {
        printf("Elements in the queue: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}
