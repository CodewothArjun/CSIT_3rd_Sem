// Write a program to convert Infix Expression into postfix Expression.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int precedency(char ch);
void infixToPostfix(char infix[], char postfix[]);

int main()
{
    char infix[100], postfix[100];
    printf("Enter a valid infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove trailing newline

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, otos = -1, ptos = -1;
    int length = strlen(infix);
    char opstack[100];

    for (i = 0; i < length; i++)
    {
        if (infix[i] == '(')
        {
            opstack[++otos] = infix[i];
        }
        else if (isalpha(infix[i]))
        {
            postfix[++ptos] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (otos != -1 && opstack[otos] != '(')
            {
                postfix[++ptos] = opstack[otos--];
            }
            otos--; // Pop the '('
        }
        else
        {
            while (otos != -1 && precedency(opstack[otos]) >= precedency(infix[i]))
            {
                postfix[++ptos] = opstack[otos--];
            }
            opstack[++otos] = infix[i];
        }
    }

    while (otos != -1)
    {
        postfix[++ptos] = opstack[otos--];
    }

    postfix[++ptos] = '\0'; // Null-terminate the postfix expression
}

int precedency(char ch)
{
    switch (ch)
    {
    case '$':
    case '^':
        return 3; // Higher precedence for ^ and $
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
