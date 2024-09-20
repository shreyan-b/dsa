#include <stdio.h>

int main() {
    int n, i, pos;
    int arr[100];

    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

   
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

 
    printf("Enter the position (1 to %d) of the element to be deleted: ", n);
    scanf("%d", &pos);

   
        if(pos < 1 || pos > n) {
        printf("Invalid position!\n");
    } else {
      
        for(i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

   
        n--;

   
        printf("Array after deletion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
