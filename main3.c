#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int sum = 0;

    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

   
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

  
    for(i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("The sum of the array elements is: %d\n", sum);

    return 0;
}