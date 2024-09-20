#include <stdio.h>

int main() {
    int n, i, pos, element;
    int arr[100];

   
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    printf("Enter the position (1 to %d) where the element should be inserted: ", n + 1);
    scanf("%d", &pos);

    if(pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
    } else {

        for(i = n; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos - 1] = element;


        n++;


        printf("Array after insertion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
