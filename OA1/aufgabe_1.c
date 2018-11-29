#include <stdio.h>
#include <stdbool.h>


double evaluate(double a, double b, double c, double d, double x) {
    return a*x*x*x + b*x*x + c*x + d;
}

double min(double a, double b, double c, double d) {
    double temp = evaluate(a,b,c,d,-5.0);
    double y;
    for (double x = -5.0; x <= 5.1; x+= 1.0) {
        y = evaluate(a,b,c,d,x);
        if (y < temp) {
            temp = y;
        }
    }
    return temp;
}

double max(double a, double b, double c, double d) {
    double temp = evaluate(a,b,c,d,-5.0);
    double y;
    for (double x = -5.0; x <= 5.1; x+= 1.0) {
        y = evaluate(a,b,c,d,x);
        if (y > temp) {
            temp = y;
        }
    }
    return temp;
}

double monotone(double a, double b, double c, double d) {
    double old_fx = evaluate(a,b,c,d,0.0);
    double fx;

    for (double x = 1.0; x <= 5.1; x+= 1.0) {
        fx = evaluate(a,b,c,d,x);
        if (fx < old_fx) {
            return false;
        }
    }
    return true;
}

double derivation(double a, double b, double c, double x) {
    return 3.0*a*x*x + 2.0*b*x + c;
}


int main () {
    double a,b,c,d;
    printf("(a)\n");
    printf("Geben Sie a ein!\t");
    scanf("%lf", &a);
    printf("\nGeben Sie b ein!\t");
    scanf("%lf", &b);
    printf("\nGeben Sie c ein!\t");
    scanf("%lf", &c);
    printf("\nGeben Sie d ein!\t");
    scanf("%lf", &d);
    printf("\n\n");

    printf("(b)\n");
    printf("Evaluate 2.0 = %lf\n\n", evaluate(a,b,c,d,2.0));

    printf("(c)\n");
    printf("min[-5;5](f(x)) = %lf\n", min(a,b,c,d));
    printf("max[-5;5](f(x)) = %lf\n\n", max(a,b,c,d));

    printf("(d)\n");
    if (monotone(a,b,c,d)) {
        printf("f(x) ist im Intervall [0;5] monoton wachsend.\n\n");
    } else {
        printf("f(x) ist im Intervall [0;5] nicht monoton wachsend.\n\n");
    }    

    printf("(e)\n");
    printf("f'(1.0) = %lf\n\n", derivation(a,b,c,1.0));
    return 0;
}