#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the linked list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Function to insert a node before the occurrence of a specific data value
void insertBeforeData(struct Node** head, int searchData, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == searchData) {
            struct Node* newNode = createNode(data);
            if (temp == *head) {
                newNode->next = *head;
                *head = newNode;
            } else {
                newNode->next = temp;
                prev->next = newNode;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Data %d not found in the list.\n", searchData);
}

// Function to display the linked list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* myList = NULL;
    int choice, data, searchData;

    do {
        printf("\nMenu:\n");
        printf("1. Add element to the list\n");
        printf("2. Display the list\n");
        printf("3. Insert element before a data value\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &data);
                append(&myList, data);
                break;
            case 2:
                printf("Linked List: ");
                display(myList);
                break;
            case 3:
                printf("Enter data value to search: ");
                scanf("%d", &searchData);
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insertBeforeData(&myList, searchData, data);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
