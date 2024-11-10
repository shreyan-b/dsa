#include <stdio.h>

struct sparse {
  int row;
  int col;
  int val;
} s[10];

void readSparseMatrix() {
  int i, j, r, c, ele, pos = 0;
  printf("Enter rows and cols: ");
  scanf("%d%d", &r, &c);
  printf("Enter the sparse matrix elements: \n");
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      scanf("%d", &ele);
      if (ele != 0) {
        pos++;
        s[pos].row = i;
        s[pos].col = j;
        s[pos].val = ele;
      }
    }
  }
  s[0].row = r;
  s[0].col = c;
  s[0].val = pos;
}

void triplet() {
  int i;
  printf("\nTriplet representation:\n");
  printf("Row\tCol\tValue\n");
  for (i = 0; i <= s[0].val; i++) {
    printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].val);
  }
}

void search() {
  int i, key, found = 0;
  printf("Enter key to search: ");
  scanf("%d", &key);
  for (i = 1; i <= s[0].val; i++) {
    if (s[i].val == key) {
      printf("key found at: ");
      printf("%d\t%d\n", s[i].row, s[i].col);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("\nElement not found.\n");
  }
}

void transpose() {
  int i, j, pos = 1;
  struct sparse trans[10];
  trans[0].row = s[0].col;
  trans[0].col = s[0].row;
  trans[0].val = s[0].val;
  for (i = 0; i < s[0].col; i++) {
    for (j = 1; j <= s[0].val; j++) {
      if (s[j].col == i) {
        trans[pos].row = s[j].col;
        trans[pos].col = s[j].row;
        trans[pos].val = s[j].val;
        pos++;
      }
    }
  }
  for (i = 0; i <= s[0].val; i++) {
    s[i] = trans[i];
  }
  triplet();
}

int main() {
  readSparseMatrix();
  triplet();
  search();
  transpose();
  return 0;
}