#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a node at the start of the circular doubly linked list
void insertStart(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
        *head = newNode;
    }
}

// Function to insert a node at a specified position in the circular doubly linked list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertStart(head, data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = *head;
    int i = 1;
    while (temp->next != *head && i < position - 1) {
        temp = temp->next;
        i++;
    }

    if (i != position - 1) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Function to delete a node by value from the circular doubly linked list
void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* toDelete = NULL;

    do {
        if (temp->data == value) {
            toDelete = temp;
            break;
        }
        temp = temp->next;
    } while (temp != *head);

    if (toDelete == NULL) {
        printf("Value not found in the list\n");
        return;
    }

    if (toDelete == *head) {
        *head = (*head)->next;
    }

    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;
    free(toDelete);
}

// Function to display the circular doubly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// ... (Previous code remains the same)

// Function to insert a node at the end of the circular doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, value;

    do {
        printf("\nCircular Doubly Linked List Operations:\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete by Value\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at start: ");
                scanf("%d", &data);
                insertStart(&head, data);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(&head, value);
                break;
            case 5:
                printf("Circular Doubly Linked List: ");
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
