#include <stdio.h>


int recursiveTrib(int trib0, int trib1, int trib2, int n) {
    if (n == 0){
        return trib0; 
    }       
    if (n == 1){ 
        return trib1;  
    }     
    if (n == 2){
        return trib2;
    }        
    
    return recursiveTrib(trib0, trib1, trib2, n - 1) + recursiveTrib(trib0, trib1, trib2, n - 2) + recursiveTrib(trib0, trib1, trib2, n - 3);
}

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
        printf("Invalid input. Please enter a non-negative number for n: ");
        scanf("%d", &n);
    }

    int result = recursiveTrib(trib0, trib1, trib2, n);
    printf("tribonacci(%d) = %d\n", n, result);

    return 0;
}
