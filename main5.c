#include <stdio.h>

int main() {
    int n, i;
    int arr1[100], arr2[100], sum[100];

    printf("Enter the number of elements in the arrays: ");
    scanf("%d", &n);

    
    printf("Enter the elements of the first array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    
    printf("Enter the elements of the second array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

 
    for(i = 0; i < n; i++) {
        sum[i] = arr1[i] + arr2[i];
    }

 
    printf("The sum of the two arrays is:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", sum[i]);
    }
    printf("\n");

    return 0;
}
