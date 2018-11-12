//  code by Joshua Lauterbach
//  12.11.18

#include <stdio.h>

void split_line() {
    printf("-----------------------------------------------\n");
}

/**
 * berechnet die Fakultät von n
 */
long fac(long n) {
    long temp = n--;
    while(n > 0) {
        temp *= n--;
    }
    return temp;
}

/**
 * Brechnet den Binomialkoeffizienten von n übe k
 */
long n_over_k(long n, long k) {
    if (n < k) {
        return 0;
    }
    return fac(n) / (fac(k)*fac(n-k));
}

int main() {
    split_line();
    printf("(a)\n");
    split_line();
    long n, k;
    printf("Bitte Zahl n eingeben!\n");
    scanf("%ld", &n);
    printf("\nFakultät n = %ld\n\n", fac(n));

    split_line();
    printf("(b)\n");
    split_line();
    printf("Bitte geben Sie n ein!\n");
    scanf("%ld", &n);
    printf("\nBitte geben Sie k ein!\n");
    scanf("%ld", &k);
    printf("\nn über k = %ld\n\n", n_over_k(n, k));

    split_line();
    printf("(c)\n");
    split_line();
    printf("Bitte Anzahl Zahlen eingeben!\n");
    scanf("%ld", &n);
    printf("\nBitte die Anzahl der Ziehungen eingeben!\n");
    scanf("%ld", &k);
    long poss = n_over_k(n, k) * fac(k);
    printf("\nEs gibt insgesamt %ld Arten, %ld aus %ld zu ziehen.\n", poss, k, n);

    
    return 0;
}