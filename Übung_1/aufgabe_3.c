#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n)
{
    if (n == 0 || n == 1)
    {
        // by def
        return true;
    } else {
        // check to sqrt(n)
        int i = 2;
        while (i*i <= n)
        {
            if (n % i == 0) return false;
            i++;
        }
        return true;
    }
}

int main() {
    // input
    printf("Please type in a positive number n!\n");
    int n;
    scanf("%d", &n);
    // check neg
    if (n < 0)
    {
        printf("\nError: You typed a negative number.\n");
        return 0;
    }
    // check prime
    if (is_prime(n)) {
        printf("\n%d is prime\n", n);
    } else {
        printf("\n%d is not prime\n", n);
    }

    return 0;
}