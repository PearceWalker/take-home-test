#include <stdio.h>

int main() {
    int trib0, trib1, trib2, n;


    printf("Enter tribonacci(0): ");
    scanf("%d", &trib0);
    while (trib0 < 0) {
        printf("Invalid input. Please enter a non-negative number for tribonacci(0): ");
        scanf("%d", &trib0);
    }

   
    printf("Enter tribonacci(1): ");
    scanf("%d", &trib1);
    while (trib1 < 0) {
        printf("Invalid input. Please enter a non-negative number for tribonacci(1): ");
        scanf("%d", &trib1);
    }

    
    printf("Enter tribonacci(2): ");
    scanf("%d", &trib2);
    while (trib2 < 0) {
        printf("Invalid input. Please enter a non-negative number for tribonacci(2): ");
        scanf("%d", &trib2);
    }

    
   
        printf("Enter n: ");
        scanf("%d", &n);
    while (n < 0) {
        printf("Invalid input. Please input a non-negative number for n: ");
        scanf("%d", &n);
    }

    int result;

    if (n == 0) {
        result = trib0;
    } 

    else if (n == 1) {
        result = trib1;
    }

    else if (n == 2) {
        result = trib2;
    } 
    
    else {
        int n_minus_3 = trib0;
        int n_minus_2 = trib1;
        int n_minus_1 = trib2;
        for (int i = 3; i <= n; i++) {
            result = n_minus_3 + n_minus_2 + n_minus_1;
            n_minus_3 = n_minus_2;
            n_minus_2 = n_minus_1;
            n_minus_1 = result;
        }
    }

    printf("tribonacci(%d) = %d\n", n, result);
    return 0;
}
