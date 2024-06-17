// Write a program to convert Infix Expression into infix Expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int precedency(char ch);
void reverse(char *exp);
void infixToPrefix(char infix[], char prefix[]);

// Function to return precedence of operators
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

// Function to reverse a string
void reverse(char *exp)
{
    int length = strlen(exp);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
}

// Function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[])
{
    int i, otos = -1, ptos = -1;
    int length = strlen(infix);
    char opstack[100], prestack[100];

    // Step 1: Reverse the infix expression
    reverse(infix);

    // Step 2: Replace ( with ) and vice versa
    for (i = 0; i < length; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Obtain the postfix expression of the modified infix expression
    for (i = 0; i < length; i++)
    {
        char c = infix[i];

        if (c == '(')
        {
            opstack[++otos] = c;
        }
        else if (isalnum(c))
        {
            prestack[++ptos] = c;
        }
        else if (c == ')')
        {
            while (otos != -1 && opstack[otos] != '(')
            {
                prestack[++ptos] = opstack[otos--];
            }
            otos--; // Pop the '('
        }
        else
        {
            while (otos != -1 && precedency(opstack[otos]) >= precedency(c))
            {
                prestack[++ptos] = opstack[otos--];
            }
            opstack[++otos] = c;
        }
    }

    while (otos != -1)
    {
        prestack[++ptos] = opstack[otos--];
    }

    prestack[++ptos] = '\0'; // Null-terminate the postfix expression

    // Step 4: Reverse the postfix expression to get prefix
    reverse(prestack);

    // Copy the prefix result
    strcpy(prefix, prestack);
}

int main()
{
    char infix[100], prefix[100];
    printf("Enter a valid infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove trailing newline

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
