#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // For tolower and toupper functions

// Structure for a node in the doubly linked list
struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a character at the end of the doubly linked list
void insertEnd(struct Node** head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to check if the given doubly linked list is a palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    struct Node *front = head, *back = head;

    while (back->next != NULL) {
        back = back->next;
    }

    while (front != back && front->prev != back) {
        if (tolower(front->data) != tolower(back->data)) {
            return false;
        }
        front = front->next;
        back = back->prev;
    }
    return true;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    struct Node* head = NULL;

    // Create a doubly linked list from the string characters (converted to lowercase)
    for (int i = 0; i < strlen(str); ++i) {
        insertEnd(&head, tolower(str[i]));
    }

    // Check if the created doubly linked list (converted to lowercase) is a palindrome
    if (isPalindrome(head)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
