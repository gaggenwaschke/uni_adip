#include <stdio.h>

/* rekursive Lösung ist falsch!
float exp_a(float a, int n, int *counter) {
    (*counter)++;
    if (n == 1)
    {
        return a;
    } else {
        return exp_a(a, n-1, counter) * a;
    }
}

float exp_b(float a, int n, int *counter) {
    (*counter)++;
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        float inner = exp_b(a, n/2, counter);
        return inner*inner;
    } else {
        float inner = exp_b(a, (n-1)/2, counter);
        return a*inner*inner;
    }
}
*/

float exp_a(float a, int n, int *counter) {
    float result = 1.0;
    for (int i = 0; i < n; i++) {
        (*counter)++;
        result *= a;
    }

    return result;
}

float exp_b(float a, int n, int *counter) {
    float result = 1.0;
    float factor = 1.0;

    while (n != 0) {
        (*counter)++;
        if (n % 2 != 0) {
            for (int i = 0; i<factor; i++) {
                result *= a;
            }
        } 
        factor*= 2.0;
        n /= 2;
    }

    return result;
}

int main() {
    int n;
    float a;

    printf("Geben sie eine reelle Zahl a ein!\n");
    scanf("%f", &a);
    printf("\nGeben Sie einen Exponent n ein!\n");
    scanf("%d", &n);
    int counter = 0;
    float result_a = exp_a(a, n, &counter);
    printf("\n(a)\t%f hoch %d = %f (berechnet in %d Iterationen)\n", a, n, result_a, counter);
    counter = 0;
    float result_b = exp_b(a, n, &counter);
    printf("\n(b)\t%f hoch %d = %f (berechnet in %d Iterationen)\n", a, n, result_b, counter);
}