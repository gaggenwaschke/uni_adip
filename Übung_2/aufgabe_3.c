#include <stdio.h>
#include <stdbool.h>

// returns the sum of all divisors
int get_div_sum(int n) {
    int sum = 0;
    for (int i = 1; i<= n/2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

bool ist_vollkommen(int n) {
    if (n == get_div_sum(n)) {
        return true;
    } else {
        return false;
    }
}

bool ist_defizient(int n) {
    if (n > get_div_sum(n)) {
        return true;
    } else {
        return false;
    }
}

void liste_vollkommene_zahlen(int r) {
    printf("[");
    for (int i = 1; i<r; i++) {
        if (ist_vollkommen(i)) {
            printf("%d,", i);
        }
    }
    printf("]");
}

int nummer_defizient(int r) {
    int n = 0;
    for (int i = 1; i < r; i++) {
        if (ist_defizient(i)) {
            n++;
        }
    }
    return n;
}

int main() {
    printf("Please enter a number n!\n");
    int n;
    scanf("%d", &n);
    printf("\n");

    // Teil 1
    if (ist_vollkommen(n)) {
        printf("%d ist vollkommen.\n", n);
    } else {
        printf("%d ist nicht vollkommen.\n", n);
    }
    if (ist_defizient(n)) {
        printf("%d ist defizient.\n", n);
    } else {
        printf("%d ist nicht defizient.\n", n);
    }

    printf("\n----------------------------------------\n");

    // Teil 2
    int r = n;
    liste_vollkommene_zahlen(r);
    printf("\nAnzahl defizienter Zahlen kleiner als %d = %d\n\n", r, nummer_defizient(r));

    return 0;
}