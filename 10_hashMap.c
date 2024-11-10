#include <stdio.h>
#include <stdlib.h>

#define m 20

int key[20], n;
int *a, index1;
int count = 0;

void linearprobing(int key) {
  index1 = key % m;
  while (a[index1] != -1) {
    index1 = (index1 + 1) % m; // collision resolved using linear probing
  }
  a[index1] = key;
  count++;
}

void display() {
  int i;
  if (count == 0) {
    printf("\nHash Table is empty");
    return;
  }
  printf("\nHash Table contents are: \n");
  for (i = 0; i < m; i++) {
    printf("\nT[%d] --> %d", i, a[i]);
  }
}

int main() {
  int i;
  printf("\nEnter the number of four digit key values:\n");
  scanf("%d", &n);
  a = (int *)malloc(m * sizeof(int));
  for (i = 0; i < m; i++) {
    a[i] = -1;
  }
  printf("\nEnter the four digit key values (K):\n");
  for (i = 0; i < n; i++) {
    scanf("%4d", &key[i]);
  }
  for (i = 0; i < n; i++) {
    if (count == m) {
      printf("\n---- Hash table is full . Cannot insertthe record %d key ----",
             i + 1);
      break;
    }
    linearprobing(key[i]);
  }
  display();
}