/*
  WACP to implement stack using array with given function.
  push,pop,peek,is _empty,is_full, traverse using call by value.
*/
#include <stdio.h>
# define max 50

int is_full(int stack[], int top) {
  if (top == max - 1) {
    return 1;
  } else {
    return 0;
  }
}

int is_empty(int stack[], int top) {
  if (top == -1) {
    return 1;
  } else {
    return 0;
  }
}

int push(int stack[], int top) {
  int x = 0;
  if (is_full(stack, top)) {
    printf("Stack full\n");
  } else {
    printf("Enter the value to push: ");
    scanf("%d", &x);
    top++;
    stack[top] = x;
  }
  return top;
}

int pop(int stack[], int top) {
  if (is_empty(stack, top)) {
    printf("Stack empty \n");
  } else {
    printf("Element popped is = %d\n", stack[top]);
    top--;
  }
  return top;
}

void peek(int stack[], int top) {
  if (is_empty(stack, top)) {
    printf("Stack empty\n");
  } else {
    printf("Element is = %d\n", stack[top]);
  }
}

void disp(int stack[], int top) {
  if (is_empty(stack, top)) {
    printf("Stack empty\n");
  } else {
    int temp = top;
    while (temp >= 0) {
      printf("\t Values of stack are: %d\n", stack[temp]);
      temp--;
    }
  }
}

int main() {
  int stack[max], top = -1, ch;
  do {
    printf("\n1.Push \n2.Pop \n3.Peek \n4.is_empty \n5.is_full \n6.Traversal\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch) {
      case 1:
        top = push(stack, top);
        break;
      case 2:
        top = pop(stack, top);
        break;
      case 3:
        peek(stack, top);
        break;
      case 4:
        if (is_empty(stack, top))
          printf("Stack is empty\n");
        else
          printf("Stack is not empty\n");
        break;
      case 5:
        if (is_full(stack, top))
          printf("Stack is full\n");
        else
          printf("Stack is not full\n");
        break;
      case 6:
        disp(stack, top);
        break;
      default:
        printf("Exiting...\n");
    }
  } while (ch <= 6);
  return 0;
}