#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 100

bool isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return true;
    else if (character1 == '[' && character2 == ']')
        return true;
    else if (character1 == '<' && character2 == '>')
        return true;
    else
        return false;
}

bool isExpressionBalanced(char expression[]) {
    int i;
    char stack[MAX_LEN];
    int top = -1;

    for (i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '<') {
            stack[++top] = expression[i];
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '>') {
            if (top == -1 || !isMatchingPair(stack[top], expression[i])) {
                return false;
            }
            else {
                top--;
            }
        }
    }

    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    char expression[MAX_LEN];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isExpressionBalanced(expression)) {
        printf("The expression is balanced.\n");
    }
    else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}