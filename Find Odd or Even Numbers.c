#include <stdio.h>

int main() {
    int n;
    
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    
    printf("Enter %d numbers:\n", n);
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        if (num % 2 == 0) {
            printf("%d is even.\n", num);
        } else {
            printf("%d is odd.\n", num);
        }
    }
    
    return 0;
}
