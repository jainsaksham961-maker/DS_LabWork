/* Q1)  WACP to convert an infix expression into a postfix expression handling 
   		all the exceptions like right associative rule.*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define max 50

int is_full(char stack[], int top) {
  if (top == max - 1) {
    return 1;
  } else {
    return 0;
  }
}

int is_empty(char stack[], int top) {
  if (top == -1) {
    return 1;
  } else {
    return 0;
  }
}

// Adapted push to take a character value directly instead of scanf
int push(char stack[], int top, char x) {
  if (is_full(stack, top)) {
    printf("Stack full\n");
  } else {
    top++;
    stack[top] = x;
  }
  return top;
}

// Adapted pop to return the popped character
char pop(char stack[], int top_ptr_val) {
    // Note: This helper matches  logic structure
    return stack[top_ptr_val];
}

char peek(char stack[], int top) {
  if (is_empty(stack, top)) {
    return '\0';
  } else {
    return stack[top];
  }
}

// Function to return operator precedence
int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

// Function to check right-associativity (e.g., exponentiation '^')
int is_right_associative(char op) {
    if (op == '^')
        return 1;
    return 0;
}

// Function to convert infix to postfix using the stack
void infix_to_postfix(char infix[], char postfix[]) {
    char stack[max];
    int top = -1;
    int i = 0, k = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];

        // Skip spaces/tabs
        if (ch == ' ' || ch == '\t') {
            i++;
            continue;
        }

        // If operand (alphanumeric), add to postfix output
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            top = push(stack, top, ch);
        }
        // If ')', pop until '(' is encountered
        else if (ch == ')') {
            while (!is_empty(stack, top) && peek(stack, top) != '(') {
                postfix[k++] = stack[top--];
            }
            if (!is_empty(stack, top) && peek(stack, top) == '(') {
                top--; // Pop '('
            }
        }
        // If an operator is scanned
        else {
            while (!is_empty(stack, top) && peek(stack, top) != '(') {
                char top_op = peek(stack, top);
                
                // Handle precedence and right-associativity exceptions
                if (precedence(top_op) > precedence(ch) || 
                   (precedence(top_op) == precedence(ch) && !is_right_associative(ch))) {
                    postfix[k++] = stack[top--];
                } else {
                    break;
                }
            }
            top = push(stack, top, ch);
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (!is_empty(stack, top)) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0'; // Null-terminate postfix expression
}

int main() {
    char infix[max], postfix[max];
    printf("Enter a valid Infix expression: ");
    fgets(infix, max, stdin);
    infix[strcspn(infix, "\n")] = 0;
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
