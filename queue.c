#include <stdio.h>
#include <stdlib.h>

int max;
int *queue;
int rear = -1;
int front = 0;
int count = 0;

void enqueue(int ele) {
  if (count == max) {
    printf("Overflow Error.\n");
    return;
  }
  rear = (rear + 1) % max;
  queue[rear] = ele;
  count++;
}

int dequeue() {
  if (count == 0) {
    printf("Underflow Error.\n");
    return -9999;
  }
  int ele = queue[front];
  front = (front + 1) % max;
  return ele;
}

void display() {
  int i,k;
  if (count == 0)
  {
     printf("queue is empty");

  }
  else {
    k = front;
    printf("queue elements are : ");
    for ( i=0;i<count;i++) {
        printf("%d \t",queue[i]);
        k = (k+1)%max;
    }
    printf("\n");
   }
}

int main() {
  int choice, ele;
  printf("Enter max: ");
  scanf("%d", &max);
  queue = (int *)malloc(max * sizeof(int));
  while (1) {
    printf("Enter choice: \n");
    printf(" 1 - enqueue \n 2 - dequeue \n 3 - display \n 4 - exit \n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter element to push: ");
      scanf("%d", &ele);
      enqueue(ele);
      break;
    case 2:
      ele = dequeue();
      printf("The dequeued element is %d.\n", ele);
      break;
    case 3:
      display();
      break;
     case 4:
     exit(0); 
    default:
      printf("Invalid case.\n");
      free(queue);
      exit(0);
    }
  }
  free(queue);
  return 0;
}