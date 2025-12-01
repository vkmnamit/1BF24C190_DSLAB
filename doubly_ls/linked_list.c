#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void createList(int n) {
    if (n <= 0) {
        printf("Number of nodes must be > 0\n");
        return;
    }

    int value;
    Node *temp, *newNode;
    head = NULL;

    printf("Enter data for node 1: ");
    scanf("%d", &value);
    head = createNode(value);

    temp = head;
    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = createNode(value);

        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    printf("Doubly linked list created with %d nodes.\n", n);
}


void insertLeftOf(int key, int newValue) {
    if (head == NULL) {
        printf("List is empty. Cannot insert to the left of %d.\n", key);
        return;
    }

    Node *current = head;

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found. Insertion failed.\n", key);
        return;
    }

    Node *newNode = createNode(newValue);


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

    printf("Inserted %d to the left of node with value %d.\n", newValue, key);
}


void deleteByValue(int key) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node *current = head;


    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found. Deletion failed.\n", key);
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

    printf("Deleted node with value %d.\n", key);
    free(current);
}


void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    printf("List contents (from left to right): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, n, value, key;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create doubly linked list\n");
        printf("2. Insert a new node to the LEFT of a given node\n");
        printf("3. Delete a node by value\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many nodes you want to create? ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                printf("Enter the value of the node to the LEFT of which you want to insert: ");
                scanf("%d", &key);
                printf("Enter the new value to insert: ");
                scanf("%d", &value);
                insertLeftOf(key, value);
                break;

            case 3:
                printf("Enter the value of the node you want to delete: ");
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
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
