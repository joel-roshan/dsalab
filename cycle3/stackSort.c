#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int sortedStack[MAX_SIZE];
int top = -1;


void push(int element) {
    if (top == -1 || element >= sortedStack[top]) {

        sortedStack[++top] = element;
    } else {
      
        while (top >= 0 && element < sortedStack[top]) {
            int temp = sortedStack[top--];
            stack[++top] = temp;
        }
        sortedStack[++top] = element;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    int element = sortedStack[top--];
    return element;
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (sorted): ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", sortedStack[i]);
    }
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");
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
                displayStack();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
