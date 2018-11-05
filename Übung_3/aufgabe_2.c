#include <stdio.h>

int main() {
    printf("Bitte Anzahl der Zahlen eingeben!\n");
    int length;
    scanf("%d", &length);
    float a[length];
    printf("Bitte die Nummern eingeben!\n");
    for (int i = 0; i < length; i++) {
        scanf("%f", &a[i]);
    }

    printf("Ihre Zahlen sind:\n[");
    for (int i = 0; i < length; i++) {
        printf("%f,", a[i]);
    }
    printf("]\n");

    float x = 0;
    for (int i = 0; i < length; i++) {
        x += a[i];
    }
    x /= length;

    float s_sq = 0;
    for (int i = 0; i < length; i++) {
        s_sq += (a[i]-x)*(a[i]-x);
    }
    s_sq /= (length-1);

    printf("x = %f\n", x);
    printf("s = %f\n", s_sq);

    return 0;
}