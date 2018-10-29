#include <stdio.h>
#include <stdbool.h>

long fib_rec(long n) {
    if (n == 0) {
        printf("\ncase 0\n");
        return 0;
    } else if (n == 1) {
        printf("\ncase 1 \n");
        return 1;
    } else {
        printf("\ncase n > 1, n = %ld", n);
        // sehr uneffizient, aber Funktionsheader muss eingehalten werden
        long f_2 = fib_rec(n-2);
        long f_1 = fib_rec(n-1);

        return f_1 + f_2;
    }
}

int main() {
    printf("Please enter a number n\n");
    long n;
    scanf("%ld", &n);
    long f_n = fib_rec(n);
    printf("\nf_%ld is = %ld\n", n, f_n);


    printf("\n ---------------------------------- \n");
    printf("The first 50 fib numbers are:[\n");

    long a[50];
    a[0] = 0;
    a[1] = 1;

    for(long i = 2; i < 50; i++)
    {
        a[i] = a[i-1] + a[i-2];
        printf("%ld,", a[i]);
    }

    printf("]\n");

    return 0;
}