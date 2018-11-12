#include <stdio.h>

void calc_with_float() {
    float x[5], result;
    x[0] = 10000.0;
    x[1] = -1.0e-3/9.0;
    x[2] = 25.0e2;
    x[3] = 1.0e-3/7.0;
    x[4] = -12.5e3;

    result = 0.0;
    for (int i = 0; i < 5; i++) {
        result += x[i];
    }
    printf("with floats:\t\t\t\t%.15f\n", result);
}

void calc_with_double() {
    double x[5], result;
    x[0] = 10000.0;
    x[1] = -1.0e-3/9.0;
    x[2] = 25.0e2;
    x[3] = 1.0e-3/7.0;
    x[4] = -12.5e3;

    result = 0.0;
    for (int i = 0; i < 5; i++) {
        result += x[i];
    }
    printf("with doubles:\t\t\t\t%.15lf\n", result);
}

void calc_alternative_float() {
    float x[5], S, S_alt, D;
    x[0] = 10000.0;
    x[1] = -1.0e-3/9.0;
    x[2] = 25.0e2;
    x[3] = 1.0e-3/7.0;
    x[4] = -12.5e3;

    S = 0.0;
    D = 0.0;

    for (int i = 0; i < 5; i++) {
        S_alt = S;
        S = S+x[i];
        D = D + (x[i] - (S - S_alt));
    }

    S = S+D;
    printf("with alternative float method:\t\t%.15f\n", S);
}

void calc_alternative_double() {
    double x[5], S, S_alt, D;
    x[0] = 10000.0;
    x[1] = -1.0e-3/9.0;
    x[2] = 25.0e2;
    x[3] = 1.0e-3/7.0;
    x[4] = -12.5e3;

    S = 0.0;
    D = 0.0;

    for (int i = 0; i < 5; i++) {
        S_alt = S;
        S = S+x[i];
        D = D + (x[i] - (S - S_alt));
    }

    S = S+D;
    printf("with alternative double method:\t\t%.15lf\n", S);
}

int main() {
    printf("Hand calculated value\t\t\t%.15f\n", 3.1746e-5);
    calc_with_float();
    calc_with_double();
    calc_alternative_float();
    calc_alternative_double();
    // D wird in diesem Verfahren angewandt um die Unterschiede in der Größenordnung,
    // welche in der Mantisse einer float nicht gespeichert werden können, abzufangen.
    // Die großen Werte in der Summe werden durch (S-S_alt) maskiert und, wodurch D 
    // anschließend nur noch die kleineren Stellen in der Mantisse darstellen muss.
    // Schon beim Rechnen in 3 Größenordnungen würde aber auch dieses Verfahren ungenau.
    // Außerdem ist es langsamer als das Rechnen mit double-precission.
}