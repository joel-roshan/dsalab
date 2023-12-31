#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

char postfix[MAX_SIZE];
char stack[MAX_SIZE];
int top=-1;

int precedence(char op){
    switch (op) {
        case '+':
        case '-':
            return 1;
            break;
        
        case '/':
        case '*':
            return 2;
            break;
        
        case '^':
            return 3;
            break;
        
        default:
            return -1;
    }
}

int is_op(char op){
    if(op=='+' || op=='-' || op=='/' || op=='*' || op =='^') {
        return 1;
    } 
    else{
        return 0;
    }
}

void infixtopostfix(char infix[MAX_SIZE]) {
    int i,j = 0;
    for (i=0;i<strlen(infix);i++){
        if(infix[i]==' ')
            continue;
        else if(isalnum(infix[i])){
            postfix[j]=infix[i];
            j++;
        } 
        else if(infix[i]=='('){
            stack[++top] = infix[i];
        } 
        else if(infix[i]==')'){
            while(top>-1 && stack[top]!='(') {
                postfix[j]=stack[top--];
                j++;
            }
            top--;
        } 
        else if(is_op(infix[i])){
            while (top>-1 && (precedence(stack[top]) > precedence(infix[i]) || (precedence(stack[top]) == precedence(infix[i]) && infix[i] != '^')) && (stack[top] != '(')){
                postfix[j]=stack[top--];
                j++;
            }
            stack[++top]=infix[i];
        }
    }
    while (top>-1) {
        if(stack[top] == '('){
            top--;
            continue;
        } 
        else{
            postfix[j++]=stack[top--];
        }
    }
    postfix[j] ='\0';
}

int main()
{
    char infix[MAX_SIZE];
    printf("Enter infix expression: ");
    gets(infix);
    infixtopostfix(infix);
    printf("Postfix expression is: ");
    puts(postfix);
    return 0;
}