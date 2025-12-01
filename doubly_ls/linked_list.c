#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;


struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void createList(int n) {
    int value, i;
    struct Node *temp, *newNode;

    if (n <= 0) {
        printf("Number of nodes must be greater than 0\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &value);
    head = createNode(value);

    temp = head;

    for (i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = createNode(value);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

    printf("Doubly linked list created.\n");
}


void insertLeftOf(int key, int newValue) {
    struct Node *current = head;
    struct Node *newNode = createNode(newValue);

    if (head == NULL) {
        printf("List is empty. Cannot insert.\n");
        return;
    }

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", key);
        free(newNode);
        return;
    }

    if (current == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    printf("Inserted %d to the left of %d.\n", newValue, key);
}


void deleteByValue(int key) {
    struct Node *current = head;

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    if (current == head) {
        head = current->next;
        if (head != NULL)
            head->prev = NULL;
    } else {
        current->prev->next = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Deleted node with value %d.\n", key);
}


void displayList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, n, key, value;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create list\n");
        printf("2. Insert to the LEFT of a node\n");
        printf("3. Delete a node\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                printf("Enter existing node value: ");
                scanf("%d", &key);
                printf("Enter new node value: ");
                scanf("%d", &value);
                insertLeftOf(key, value);
                break;

            case 3:
                printf("Enter value of node to delete: ");
                scanf("%d", &key);
                deleteByValue(key);
                break;

            case 4:
                displayList();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
