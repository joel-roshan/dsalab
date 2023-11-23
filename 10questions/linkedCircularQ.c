#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* rear = NULL;

// Function to enqueue an element into the circular queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Queue overflow.\n");
        return;
    }
    newNode->data = value;
    if (rear == NULL) {
        newNode->next = newNode;
        rear = newNode;
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued into the circular queue.\n", value);
}

// Function to dequeue an element from the circular queue
void dequeue() {
    if (rear == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    struct Node* temp = rear->next;
    printf("Dequeued element: %d\n", temp->data);
    if (rear->next == rear) {
        free(rear);
        rear = NULL;
    } else {
        rear->next = temp->next;
        free(temp);
    }
}

// Function to display the circular queue
void display() {
    struct Node* temp = rear;
    if (rear == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements:\n");
    temp = temp->next;
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
}

int main() {
    int choice, value;

    do {
        printf("\nCircular Queue Menu:\n");
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
