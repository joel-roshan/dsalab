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

// Function to insert a node into a sorted linked list
void insertInSortedOrder(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // If the list is empty or the new node data is smaller than the head
    if (*head == NULL || data < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Find the node after which the new node should be inserted
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
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
    struct Node* sortedList = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Add element to the sorted list\n");
        printf("2. Display the sorted list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &data);
                insertInSortedOrder(&sortedList, data);
                break;
            case 2:
                printf("Sorted List: ");
                display(sortedList);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
