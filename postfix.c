#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

char stack[SIZE];S
int top = -1;


void push(char c) {
    if (top >= SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}


int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


void infixToPostfix(char* infix) {
    char postfix[SIZE];
    int j = 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isspace(c)) continue;
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (peek() != '(' && top != -1) {
                postfix[j++] = pop();
            }
            if (peek() == '(') pop();
        }
        else if (isOperator(c)) {
            while (isOperator(peek()) && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main() {
    char infix[SIZE];
    printf("Enter infix expression: ");
    fgets(infix, SIZE, stdin);


    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix);

    return 0;
}

