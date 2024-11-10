#include <stdio.h>
#include <stdlib.h>

int max;
int *stack;
int top = -1;

void push(int ele) {
  if (top == max - 1) {
    printf("Overflow Error\n");
    max = 2 * max;
    stack = realloc(stack, max * sizeof(int));
    printf("Stack has been resized.\n");
  }
  stack[++top] = ele;
}

int pop() {
  if (top == -1) {
    printf("Underflow Error.\n");
    return -9999;
  }
  return stack[top--];
}

void display() {
  if (top == -1) {
    printf("Empty Stack.\n");
    return;
  }
  printf("Stack elements are:\n");
  for (int i = top; i >= 0; i--) {
    printf("%d\t", stack[i]);
  }
  printf("\n");
}

int main() {
  int choice, ele;
  printf("Enter the max size: ");
  scanf("%d", &max);
  stack = (int *)malloc(max * sizeof(int));
  while (1) {
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter element to push: ");
      scanf("%d", &ele);
      push(ele);
      break;
    case 2:
      ele = pop();
      printf("popped element is %d\n", ele);
      break;
    case 3:
      display();
      break;
    default:
      printf("Invalid choice.\n");
      free(stack);
      exit(0);
    }
  }
  free(stack);
  return 0;
}