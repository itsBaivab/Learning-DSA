#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Stack to help with postfix expression conversion
char stack[MAX_STACK_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char item) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        return '\0'; // Null character to indicate an empty stack
    } else {
        return stack[top--];
    }
}

// Function to check the precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char token;
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        if (isalnum(token)) {
            postfix[j] = token;
            j++;
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while ((token = pop()) != '(') {
                postfix[j] = token;
                j++;
            }
        } else {
            while (precedence(token) <= precedence(stack[top]) && top != -1) {
                postfix[j] = pop();
                j++;
            }
            push(token);
        }
    }

    while (top != -1) {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
