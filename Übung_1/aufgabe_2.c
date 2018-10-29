#include <stdio.h>

int fac(int n) {
    if (n == 1){
        return 1;
    } else {
        return fac(n-1) + n;
    }
}

int sqr_fac(int n) {
    if (n == 1) {
        return 1;
    } else {
        return sqr_fac(n-1) + n*n;
    }
}

int main(){
    int n;
    printf("Please enter number n\n");
    scanf("%d", &n);
    int fac_n = fac(n);
    printf("\nFaculty of your number is = %d\n", fac_n);
    int sqr_fac_n = sqr_fac(n);
    printf("\nsum of squares from 1..n is = %d\n", sqr_fac_n);
    return 0;
}