//  code by Joshua Lauterbach
//  12.11.18

#include <stdio.h>

#define DEBUG

/** 
 * Gibt den Nachfolger des ¨ubergebenen Wertes zurück
 */
int succ(int x) {
    return ++x;
}

/**
 * Gibt den Vorg¨anger des ¨ubergebenen Wertes zurück
 */
int pre(int x) {
    return --x;
}

/**
 * adds x to y
 */
int add(int x, int y) {
    if (y == 0) {
        return x;
    }
    x = succ(x);
    y = pre(y);
    return add(x, y);
}

/**
 * subtracts y from x
 */
int sub(int x, int y) {
    if (y == 0) {
        return x;
    }
    x = pre(x);
    y = pre(y);
    return sub(x, y);
}

/**
 * multiplies x by y
 */
int mult(int x, int y) {
    if (y == 0) {
        return 0;
    }
    int next_sum = mult(x, pre(y));
    if (next_sum < 0) {
        // make next sum positives
        return sub(x, -1*next_sum);
    } else {
        return add(x, next_sum);
    }
}

int main() {
    int x = 2;
    int y = 0;

    printf("x = %d, y = %d\n", x, y);
    printf("x+y= %d\n", add(x,y));
    printf("x-y= %d\n", sub(x,y));
    printf("x*y= %d\n\n", mult(x,y));

    x = -3;
    y = 2;

    printf("x = %d, y = %d\n", x, y);
    printf("x+y= %d\n", add(x,y));
    printf("x-y= %d\n", sub(x,y));
    printf("x*y= %d\n", mult(x,y));

    return 0;
}