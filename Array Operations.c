#include <stdio.h>

int main() {
    int arr[100]; // Assuming a maximum of 100 elements.
    int n, choice, position, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array operations menu:\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Display array\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insertion
                printf("Enter the position to insert (0-%d): ", n);
                scanf("%d", &position);

                if (position < 0 || position > n) {
                    printf("Invalid position!\n");
                } else {
                    printf("Enter the element to insert: ");
                    int element;
                    scanf("%d", &element);

                    // Shift elements to make space for the new element
                    for (i = n; i >= position; i--) {
                        arr[i] = arr[i - 1];
                    }

                    arr[position] = element;
                    n++; // Increase the array size
                    printf("Element inserted successfully.\n");
                }
                break;

            case 2:
                // Deletion
                printf("Enter the position to delete (0-%d): ", n - 1);
                scanf("%d", &position);

                if (position < 0 || position >= n) {
                    printf("Invalid position!\n");
                } else {
                    // Shift elements to fill the gap left by the deleted element
                    for (i = position; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }

                    n--; // Decrease the array size
                    printf("Element deleted successfully.\n");
                }
                break;

            case 3:
                // Display
                printf("Array elements: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                // Exit
                return 0;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
