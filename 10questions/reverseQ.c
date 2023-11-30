#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Structure for a node in the stack
struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* top = NULL;

// Function to insert element at the rear of the queue
void enqueue(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to delete element from the front of the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    free(temp);
    if (front == NULL) {
        rear = NULL;
    }
}

// Function to display the elements in the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to push an element onto the stack
void push(int item) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct StackNode* temp = top;
    int item = temp->data;
    top = top->next;
    free(temp);
    return item;
}

// Function to reverse the content of the queue using a stack
void reverseQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    while (front != NULL) {
        push(front->data);
        dequeue();
    }
    while (top != NULL) {
        enqueue(pop());
    }
}

int main() {
    int choice, item;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Reverse Queue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                reverseQueue();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
