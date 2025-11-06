#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int queue_array[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1 || front > rear);
}

int isFull() {
    return (rear == MAX_SIZE - 1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow: Cannot add element, queue is full.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue_array[rear] = value;
    printf("%d enqueued to queue.\n", value);
}


void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow: Cannot remove element, queue is empty.\n");
        return;
    }
    printf("%d dequeued from queue.\n", queue_array[front]);
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue_array[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
