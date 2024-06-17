/*
//  using of structure  (Structure Implementation)

#include <stdio.h>
#define MAX_SIZE 100

// Define the structure for the Queue
struct queue
{
    int items[MAX_SIZE];
    int rear, front;
};
typedef struct queue Queue;

// Function to enqueue an element into the queue
void enqueue(Queue *q, int value)
{
    if (q->rear == MAX_SIZE - 1)
    {
        printf("\nQueue is full. Cannot Enqueue.\n");
    }
    else
    {
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to dequeue an element from the queue
void dequeue(Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("\nQueue is Empty.");
    }
    else
    {
        q->items[q->front];
        q->front++;
    }
}

int main()
{
    Queue q;
    q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 233);

    // Displaying the queue
    printf("Queue: ");
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.items[i]);
    }

    dequeue(&q);
    dequeue(&q);

    // Displaying the dequeue
    printf("\nDequeue: ");
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.items[i]);
    }
    printf("\n");

    return 0;
}
*/

// ! Without using of structure  (Array Implementation)
#include <stdio.h>
#define maxSize 30
int rear = -1, front = -1, item[maxSize];

int isFull()
{
    if (rear == maxSize - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (rear == -1 && front == -1)
    {
        return 1;
    }
    return 0;
}
void Enqueue(int newItem)
{
    if (isFull())
    {
        printf("The Queue is Full.\n");
    }
    else
    {
        rear++;
        item[rear] = newItem;
    }
}
void Dequeue()
{
    if (isEmpty())
    {
        printf("The Queue is Empty.\n");
    }
    else
    {
        item[front];
        front++;
        printf("\nDeleted Item: %d", item[front]);
    }
}

int main()
{
    // initilization
    int i;
    Enqueue(43);
    Enqueue(13);
    Enqueue(100);

    printf("Enqueue Items: \n");
    for (i = front + 1; i <= rear; i++)
    {
        printf("%d\t", item[i]);
    }

    Dequeue();
    Dequeue();
    printf("\nAfter Dqueue Items: \n");
    for (i = front + 1; i <= rear; i++)
    {
        printf("%d\t", item[i]);
    }
    printf("\n");

    return 0;
}
