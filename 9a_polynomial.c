#include <math.h>
#include <stdio.h>

struct polynomial {
  int coeff;
  int expo;
};

typedef struct polynomial poly;

void readPolynomial(poly p[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("\nEnter the Coefficient and the Exponent: ");
    scanf("%d%d", &p[i].coeff, &p[i].expo);
  }
}

int addPolynomial(poly p1[], poly p2[], int n1, int n2, poly p3[]) {
  int i = 0, j = 0, k = 0;

  while (i < n1 && j < n2) {
    if (p1[i].expo == p2[j].expo) {
      p3[k].coeff = p1[i].coeff + p2[j].coeff;
      p3[k].expo = p1[i].expo;
      i++;
      j++;
      k++;
    } else if (p1[i].expo > p2[j].expo) {
      p3[k] = p1[i];
      i++;
      k++;
    } else {
      p3[k] = p2[j];
      j++;
      k++;
    }
  }

  while (i < n1) {
    p3[k] = p1[i];
    i++;
    k++;
  }

  while (j < n2) {
    p3[k] = p2[j];
    j++;
    k++;
  }

  return k;
}

void printPolynomial(poly p[], int n) {
  int i;
  for (i = 0; i < n - 1; i++) {
    printf("%d(x^%d) + ", p[i].coeff, p[i].expo);
  }
  printf("%d(x^%d)", p[n - 1].coeff, p[n - 1].expo);
}

void evaluate(poly p[], int n) {
  int i, x, sum = 0;
  printf("\nEnter the value of x: ");
  scanf("%d", &x);
  for (i = 0; i < n; i++) {
    sum = sum + p[i].coeff * pow(x, p[i].expo);
  }
  printf("\nResult = %d\n", sum);
}

int main() {
  int n1, n2, n3;
  poly p1[10], p2[10], p3[10];

  printf("Enter number of terms in first polynomial: ");
  scanf("%d", &n1);
  readPolynomial(p1, n1);

  printf("\nEnter number of terms in second polynomial: ");
  scanf("%d", &n2);
  readPolynomial(p2, n2);

  printf("\nFirst Polynomial: ");
  printPolynomial(p1, n1);

  printf("\nSecond Polynomial: ");
  printPolynomial(p2, n2);

  n3 = addPolynomial(p1, p2, n1, n2, p3);

  printf("\nResultant Polynomial: ");
  printPolynomial(p3, n3);

  evaluate(p3, n3);

  return 0;
}