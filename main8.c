#include <stdio.h>

int main() {
    int a1[10], a2[10], a3[20], n1, n2, i, index = 0;

  
    printf("\nEnter size of array1: ");
    scanf("%d", &n1);
    printf("\nEnter the elements of the first array: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &a1[i]);
    }


    printf("\nEnter size of array2: ");
    scanf("%d", &n2);
    printf("\nEnter the elements of the second array: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &a2[i]);
    }

  
    for (i = 0; i < n1; i++) {
        a3[index] = a1[i];
        index++;
    }
    for (i = 0; i < n2; i++) {
        a3[index] = a2[i];
        index++;
    }


    printf("\nThe resultant array is: ");
    for (i = 0; i < (n1 + n2); i++) {
        printf("\t%d", a3[i]);
    }
    printf("\n");

    return 0;
}
