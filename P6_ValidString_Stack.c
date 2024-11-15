#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0';
}

int isValid(char *expr) {
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            char topChar = pop();
            if ((expr[i] == ')' && topChar != '(') || 
                (expr[i] == '}' && topChar != '{') || 
                (expr[i] == ']' && topChar != '[')) {
                return 0;
            }
        }
    }
    return (top == -1);
}

void main() {
    char expr[MAX];
    printf("Enter an expression: ");
    scanf("%s", expr);

    if (isValid(expr)) {
        printf("Valid\n");
    } else {
        printf("Not Valid\n");
    }
}
