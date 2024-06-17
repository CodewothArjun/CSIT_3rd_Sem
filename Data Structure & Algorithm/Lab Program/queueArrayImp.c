/*
Write a menu driven program to illustrate basic operations of
Linear queue using pointer implementation.
a) Enqueue
b) Dequeue
c) Display all values
d) Exit

*/

#include <stdio.h>
#define maxSize 30
int rear = -1, front = 0, item[maxSize]; // Initialize front to 0

int isFull() {
    if (rear == maxSize - 1) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front > rear) { // Check if front has surpassed rear
        return 1;
    }
    return 0;
}

void Enqueue(int newItem) {
    if (isFull()) {
        printf("The Queue is Full.\n");
    } else {
        if (rear == -1) { // If queue is initially empty
            front = 0;
        }
        rear++;
        item[rear] = newItem;
    }
}

void Dequeue() {
    if (isEmpty()) {
        printf("The Queue is Empty.\n");
    } else {
        printf("\nDeleted Item: %d", item[front]);
        front++;
        if (front > rear) { // Reset the queue if it becomes empty
            front = rear = -1;
        }
    }
}

int main() {
    int i, num, data;
    
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &num);
    
    for(i = 0; i < num; i++) {
        printf("Enter data for item %d: ", i+1);
        scanf("%d", &data);
        Enqueue(data);
    }

    printf("\nEnqueue Items: \n");
    for (i = front; i <= rear; i++) { // Start loop at front
        printf("%d\t", item[i]);
    }

    Dequeue();
    Dequeue();
    
    printf("\nAfter Dequeue Items: \n");
    for (i = front; i <= rear; i++) { // Start loop at front
        printf("%d\t", item[i]);
    }
    
    printf("\n");

    return 0;
}