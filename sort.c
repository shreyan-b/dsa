#include <stdio.h>
#include <stdlib.h>

void selectionSort(int a[], int n) {
  int i, j, pos, temp;
  for (i = 0; i < n - 1; i++) {
    pos = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[pos]) {
        pos = j;
      }
    }
    if (pos != i) {
      temp = a[i];
      a[i] = a[pos];
      a[pos] = temp;
    }
  }
}

int main() {
  int *a, i, n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  a = (int *)malloc(n * sizeof(int));

  printf("Enter the array elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  selectionSort(a, n);

  printf("Array after Selection Sort: ");
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  return 0;
}