// Code for normal double-ended queue using linked list

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the deque
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to insert element at the front of the deque
void insertFront(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    if (front == NULL) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front = newNode;
    }
}

// Function to insert element at the rear of the deque
void insertRear(int item) {
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

// Function to delete element from the front of the deque
void deleteFront() {
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

// Function to delete element from the rear of the deque
void deleteRear() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    while (temp->next != rear) {
        temp = temp->next;
    }
    temp->next = NULL;
    free(rear);
    rear = temp;
}

// Function to display the elements in the deque
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

int main() {
    int choice, item;
    do {
        printf("\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
//input restricted double ended queue using linked list
// Code for input-restricted double-ended queue using linked list

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the deque
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to insert element at the rear of the deque
void insertRear(int item) {
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

// Function to delete element from the front of the deque
void deleteFront() {
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

// Function to display the elements in the deque
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

int main() {
    int choice, item;
    do {
        printf("\n1. Insert at rear\n2. Delete from front\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 2:
                deleteFront();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;

}
// Code for output-restricted double-ended queue using linked list

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the deque
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to insert element at the front of the deque
void insertFront(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    if (front == NULL) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front = newNode;
    }
}

// Function to delete element from the rear of the deque
void deleteRear() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    while (temp->next != rear) {
        temp = temp->next;
    }
    temp->next = NULL;
    free(rear);
    rear = temp;
    if (rear == NULL) {
        front = NULL;
    }
}

// Function to display the elements in the deque
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

int main() {
    int choice, item;
    do {
        printf("\n1. Insert at front\n2. Delete from rear\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                deleteRear();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
