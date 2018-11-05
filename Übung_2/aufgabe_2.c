#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

long fib_rec(long n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
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
    printf("The first 50 even fib numbers are:[\n");

    long long unsigned int a[200];
    int i_f = 0;
    a[0] = 0;
    a[1] = 1;

    for(long i = 2; i < 200; i++)
    {
        // overflow detection
        if (a[i-1] > (UINT64_MAX-a[i-2]))
        {
            printf("\nError, overflow while trying to add!\n");
            break;
        }

        a[i] = a[i-1] + a[i-2];
        if (a[i] % 2 == 0)
        {
            i_f++;
            printf("%llu,\n", a[i]);
        }
        if (i_f >= 50) break;
    }

    printf("]\n");
    printf("number even fib number: %d\n", i_f);

    return 0;
}