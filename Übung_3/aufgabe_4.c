#include <stdio.h>

void calc_with_float() {
    float x_1, x_2, x_3, x_4, x_5, result;
    x_1 = 10000.0;
    x_2 = -1.0e-3/9.0;
    x_3 = 25.0e2;
    x_4 = 1.0e-3;
    x_5 = -12.5e3;

    result = x_1 + x_2 + x_3 + x_4 + x_5;
    printf("with floats: %f\n", result);
}

void calc_with_double() {
    double x_1, x_2, x_3, x_4, x_5, result;
    x_1 = 10000.0;
    x_2 = -1.0e-3/9.0;
    x_3 = 25.0e2;
    x_4 = 1.0e-3;
    x_5 = -12.5e3;

    result = x_1 + x_2 + x_3 + x_4 + x_5;
    printf("with doubles: %lf\n", result);
}

int main() {
    calc_with_float();
    calc_with_double();
}