#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;
int minStack[MAX_SIZE];
int minTop = -1;

void push(int element) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }

    stack[++top] = element;

    if (minTop == -1 || element <= minStack[minTop]) {
        minStack[++minTop] = element;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    int element = stack[top--];

    if (element == minStack[minTop]) {
        minTop--;
    }

    return element;
}

int getMinimum() {
    if (minTop == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    return minStack[minTop];
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("1. Push\n2. Pop\n3. Get Minimum\n4. Display Stack\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                element = pop();
                if (element != -1) {
                    printf("Popped element: %d\n", element);
                }
                break;
            case 3:
                printf("Minimum element in the stack: %d\n", getMinimum());
                break;
            case 4:
                displayStack();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
