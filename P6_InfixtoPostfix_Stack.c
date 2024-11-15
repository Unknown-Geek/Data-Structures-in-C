#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char stack[100];
int TOP = -1;
char postfix[100];
char infix[100];

void push(char ch)
{
    TOP++;
    stack[TOP] = ch;
}

char pop()
{
    char ch = stack[TOP];
    TOP--;
    return ch;
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int evaluate() {
    int val1,val2;
    int len = strlen(postfix);
    char symbol;
    char result;
    int i = 0;

    while((symbol = postfix[i++])!='\0') {
        if(symbol>='0' && symbol <= '9'){
            push(symbol);
        }
        else {
            val2 = pop()-'0';
            val1 = pop()-'0';
            switch(symbol) {
                case '+' :
                    result = val1+val2;
                    break;
                case '-' :
                    result = val1-val2;
                    break;
                case '*' :
                    result = val1*val2;
                    break;
                case '/' :
                    result = val1/val2;
                    break;
                case '^' :
                    result = pow(val1,val2);
                    break;
            }
            push(result);
        }
    }
    result = pop();
    return (result);
}

void main()
{
    int i = 0, j = 0;
    int result;
    char ch, op;
    printf("Enter the infix exp : ");
    gets(infix);
    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        switch (ch)
        {
        case '(':
            push(ch);
            break;

        case ')':
            while ((op = pop()) != '(')
            {
                postfix[j] = op;
                j++;
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (TOP != -1 && (precedence(stack[TOP]) >= precedence(ch)))
            {
                postfix[j] = pop();
                j++;
            }
            push(ch);
            break;

        default:
            postfix[j] = ch;
            j++;
            break;
        }
    }
    while(TOP!=-1) {
        postfix[j] = pop();
        j++;
    }
    puts(postfix);
    result = evaluate();
    printf("Result : %d\n",result);
}