//  code by Joshua Lauterbach
//  12.11.18

#include <math.h>
#include <stdio.h>

#define MAX_N           (5)     // Konstante für maximale Approximationsgenauigkeit

/**
 * berechnet die Fakultät von n
 */
long fac(long n) {
    if (n == 0) {
        return 1;
    }
    long temp = n--;
    while(n > 0) {
        temp *= n--;
    }
    return temp;
}

/**
 * approximates sinus
 */
double prox_cos(double x) {
    double sum = 0.0;
    for(int n = 0; n < MAX_N; n++)
    {
        sum += pow(-1.0, n) * pow(x, 2*n) / fac(2*n);
    }   
    return sum;
} 

/**
 * approximates cosine
 */
double prox_sin(double x) {
    double sum = 0.0;
    for(int n = 0; n < MAX_N; n++)
    {
        sum += pow(-1.0, n) * pow(x, 2*n+1) / fac(2*n+1);
    }   
    return sum;
} 

/**
 * approximates exp
 */
double exp(double x) {
    double sum = 0.0;
    for(int n = 0; n < MAX_N*2; n++)
    {
        sum += pow(x, n) / fac(n);
    }   
    return sum;
}

int main() {
    double x = M_PI / 4;
    printf("\nsin(%lf)=\t%lf\n", x, prox_sin(x));
    printf("cos(%lf)=\t%lf\n", x, prox_cos(x));
    x = M_PI / 2;
    printf("\nsin(%lf)=\t%lf\n", x, prox_sin(x));
    printf("cos(%lf)=\t%lf\n", x, prox_cos(x));
    x = 1.0;
    printf("\nexp(%lf)=\t%lf\n", x, exp(x));

    return 0;
}