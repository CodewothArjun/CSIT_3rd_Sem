/*

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
        printf("Queue is full. Cannot enqueue.\n");
    }
    else
    {
        q->rear++;
        q->items[q->rear] = value;
    }
}

int main()
{
    Queue q;
    q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    // Displaying the queue
    printf("Queue: ");
    for (int i = 0; i <= q.rear; i++)
    {
        printf("%d ", q.items[i]);
    }
    printf("\n");

    return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>

#define maxSize 1

typedef struct linear_queue
{
    int rear, front, items[maxSize];
} Queue;

int isfull(Queue *q)
{
    if (q->rear == maxSize - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(Queue *q, int value)
{
    if (isfull(q))
    {
        printf("\nThe Queue is full");
    }
    else
    {
        q->rear++;
        q->items[q->rear] = value;
    }
}

// dequeue opereation

int main()
{
    Queue q;
    q.front = q.rear = -1;

    enqueue(&q, 20);
    enqueue(&q, 24);
    printf("The Queue: \n");
    for (int i = 0; i <= q.rear; i++)
    {
        printf("%d\t", q.items[i]);
    }
    return 0;
}