// Circular Queue implementation in C
/*
#include <stdio.h>
#define maxSize 30
int items[maxSize];
int front = -1, rear = -1;

// Check if the queue is full
int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == maxSize - 1))
        return 1;
    return 0;
}

// Check if the queue is empty
int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}

// Adding an element
void enQueue(int element)
{
    if (isFull())
    {
        printf("\n Queue is full!! \n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxSize;
        }
        items[rear] = element;
    }
}

// Removing an element
void deQueue()
{
    int element;
    if (isEmpty())
    {
        printf("\n Queue is empty !! \n");
    }
    else
    {
        element = items[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % maxSize;
        }
        printf("\n Deleted element -> %d ", element);
    }
}

int main()
{
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(6);
    enQueue(8);
    printf(" Inserted Items: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", items[i]);
    }
    deQueue();
    deQueue();

    return 0;
}
*/

#include <stdio.h>
#define maxSize 40

struct circular
{
    int rear, front, items[maxSize];
};
typedef struct circular cqueue;

int isFull(cqueue *cq)
{
    if ((cq->rear == maxSize - 1 && cq->front == 0) || (cq->front == cq->rear + 1))
    {
        return 1;
    }
    return 0;
}

int isEmpty(cqueue *cq)
{
    if (cq->rear == -1 && cq->front == -1)
    {
        return 1;
    }
    return 0;
}

// insertion
void Cqueue(cqueue *cq, int newItem)
{
    if (isFull(cq))
    {
        printf("Queue is full.\n");
        return;
    }
    else
    {
        if (cq->front == -1 && cq->rear == -1)
        {
            cq->front = cq->rear = 0;
        }
        else
        {
            cq->rear = (cq->rear + 1) % maxSize;
        }
        cq->items[cq->rear] = newItem;
    }
}

// Deletion
void Dqueue(cqueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is Empty!");
    }
    else
    {
        printf("\nDeleted: %d", cq->items[cq->front]);
        if (cq->front == cq->rear)
        {
            cq->front = cq->rear = -1;
        }
        else
        {
            cq->front = (cq->front + 1) % maxSize;
        }
    }
}

int main()
{
    cqueue cq;
    int newItem;
    cq.rear = -1;
    cq.front = -1;
    int n, i;
    printf("Enter the no. of new Item to enqueue: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter a new Item to cqueue: ");
        scanf("%d", &newItem);
        Cqueue(&cq, newItem);
    }

    // Displaying cqueue
    printf("\nEnqueue: \n");
    for (int i = cq.front; i <= cq.rear; i++)
    {
        printf("%d\t", cq.items[i]);
    }

    // Displaying dqueue
    Dqueue(&cq);
    Dqueue(&cq);
}