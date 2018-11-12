//  code by Joshua Lauterbach
//  12.11.18

#include <math.h>
#include <stdio.h>

int main() {    
    long max_c, count, steps;
    printf("Bitte geben Sie das maximale c ein!\n");
    scanf("%ld", &max_c);
    printf("\n\n");

    count = 0;
    steps = 0;
    for(long c = 2; c <= max_c; c++) {
        for (long b = 1; b < c; b++) {
            for (long a = 0; a<b; a++) {
                if (a*a + b*b == c*c) {
                    printf("%ld² + %ld² = %ld²\n", a, b, c);
                    count++;
                }
                steps++;
            }
        }
        //printf("c = %ld\tin\t%ld\tMia Schritten\n", c, (long)(steps/1e9));
    }  

    printf("\n%ld gefundene Pythagoras-Triplets in %lf Millionen Schritten\n", count, steps/1e6);
    return 0;  
}