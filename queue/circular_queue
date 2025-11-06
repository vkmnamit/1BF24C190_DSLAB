


#include <stdio.h>
#define N 5

int queue[N];
int top = -1;
int rear = -1;

void enqueue(int x) {
    if ((rear + 1) % N == top) {
        printf("Queue is full\n");
    } else if (top == -1 && rear == -1) {
        top = rear = 0;
        queue[rear] = x;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() {
    if (top == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (top == rear) {
        printf("Item deleted: %d\n", queue[top]);
        top = rear = -1;
    } else {
        printf("Item deleted: %d\n", queue[top]);
        top = (top + 1) % N;
    }
}

void display() {
    if (top == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        int i = top;
        printf("Queue elements: ");
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % N;
        }
        printf("\n");
    }
}

int main() {
    enqueue(45);
    enqueue(34);
    enqueue(3);
    display();
    dequeue();
    enqueue(21);
    enqueue(34);
    enqueue(34);
    display();
    enqueue(34);
    display();

    return 0;
}
