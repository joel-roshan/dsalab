#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 20

char stk[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

char peek() {
    return stk[top];
}

char pop() {
    if (isEmpty())
        return -1;

    char ch = stk[top];
    top--;
    return ch;
}

void push(char oper) {
    if (isFull())
        printf("Stack Full!!!!\n");
    else {
        top++;
        stk[top] = oper;
    }
}

int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void covertInfixToPostfix(char *infix) {
    int i, j;
    char expression[MAX];

    for (i = 0, j = -1; infix[i]; ++i) {
        if (checkIfOperand(infix[i]))
            expression[++j] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(')
                expression[++j] = pop();
            if (!isEmpty() && peek() != '(') {
                printf("Invalid expression\n");
                return;
            } else
                pop();
        } else {
            while (!isEmpty() && precedence(infix[i]) <= precedence(peek()))
                expression[++j] = pop();
            push(infix[i]);
        }
    }

    while (!isEmpty())
        expression[++j] = pop();

    expression[++j] = '\0';
    printf("Postfix expression: %s\n", expression);
}

int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    covertInfixToPostfix(infix);
    return 0;
}
