
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define max 50

// --- Character Stack Functions (for Infix to Postfix) ---

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

int push(char stack[], int top, char x) {
  if (is_full(stack, top)) {
    printf("Stack full\n");
  } else {
    top++;
    stack[top] = x;
  }
  return top;
}

char peek(char stack[], int top) {
  if (is_empty(stack, top)) {
    return '\0';
  } else {
    return stack[top];
  }
}

// --- Integer Stack Functions (for Postfix Evaluation) ---

int is_full_int(int stack[], int top) {
  if (top == max - 1) {
    return 1;
  } else {
    return 0;
  }
}

int is_empty_int(int stack[], int top) {
  if (top == -1) {
    return 1;
  } else {
    return 0;
  }
}

int push_int(int stack[], int top, int x) {
  if (is_full_int(stack, top)) {
    printf("Stack full\n");
  } else {
    top++;
    stack[top] = x;
  }
  return top;
}

// --- Algorithm Logic ---

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

int is_right_associative(char op) {
    if (op == '^')
        return 1;
    return 0;
}

// Function to convert infix to postfix
void infix_to_postfix(char infix[], char postfix[]) {
    char stack[max];
    int top = -1;
    int i = 0, k = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (ch == ' ' || ch == '\t') {
            i++;
            continue;
        }

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            top = push(stack, top, ch);
        }
        else if (ch == ')') {
            while (!is_empty(stack, top) && peek(stack, top) != '(') {
                postfix[k++] = stack[top--];
            }
            if (!is_empty(stack, top) && peek(stack, top) == '(') {
                top--; 
            }
        }
        else {
            while (!is_empty(stack, top) && peek(stack, top) != '(') {
                char top_op = peek(stack, top);
                
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

    while (!is_empty(stack, top)) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';
}

// Function to evaluate postfix expression
int evaluate_postfix(char postfix[]) {
    int stack[max];
    int top = -1;
    int i = 0;

    while (postfix[i] != '\0') {
        char ch = postfix[i];

        if (ch == ' ' || ch == '\t') {
            i++;
            continue;
        }

        if (isdigit(ch)) {
            top = push_int(stack, top, ch - '0');
        }
        else {
            int val2 = stack[top--];
            int val1 = stack[top--];
            int result = 0;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '%': result = val1 % val2; break;
                case '^': result = (int)pow(val1, val2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
            }
            top = push_int(stack, top, result);
        }
        i++;
    }
    return stack[top];
}

int main() {
    char infix[max], postfix[max];
    
    printf("Enter a valid Infix expression (e.g., 3+5*2): ");
    fgets(infix, max, stdin);
    infix[strcspn(infix, "\n")] = 0;

    // Step 1: Convert to Postfix
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    // Step 2: Evaluate the Postfix Expression
    int final_result = evaluate_postfix(postfix);
    printf("Evaluated Result: %d\n", final_result);

    return 0;
}
