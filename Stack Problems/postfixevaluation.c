#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

char stack[MAX_STACK_SIZE];
int top = -1;

void push(char item) {
  if (top >= MAX_STACK_SIZE - 1) {
    printf("Stack Overflow\n");
    return;
  } else {
    stack[++top] = item;
  }
}

char pop() {
  if (top == -1) {
    printf("Stack Underflow\n");
    return '\0';
  } else {
    return stack[top--];
  }
}

int postfixEvaluation() {
  

  // Check for invalid characters in postfix expression
  char postfix[100];
  char ch;
  int i = 0;
  int op1, op2, evaluatedResult;
  printf("Enter the postfix expression: ");
  scanf("%s", postfix);
  while ((ch = postfix[i++]) != '\0') {
    if (!isdigit(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/') {
      printf("Invalid character '%c' in postfix expression\n", ch);
      return -1;
    }
  }

  // Evaluate the postfix expression
  i = 0;
  while ((ch = postfix[i++]) != '\0') {
    if (isdigit(ch)) {
      push(ch - '0');
    } else {
      op2 = pop();
      op1 = pop();
      switch (ch) {
        case '+':
          evaluatedResult = op1 + op2;
          break;
        case '-':
          evaluatedResult = op1 - op2;
          break;
        case '*':
          evaluatedResult = op1 * op2;
          break;
        case '/':
          evaluatedResult = op1 / op2;
          break;
      }
      push(evaluatedResult);
    }
  }

  // Return the evaluated result
    return evaluatedResult;
}

int main() {
  // Check the return value of postfixEvaluation()
  int result = postfixEvaluation();
  if (result == -1) {
    return 1;
  }

  printf("The evaluated result is: %d\n", result);

  return 0;
}
