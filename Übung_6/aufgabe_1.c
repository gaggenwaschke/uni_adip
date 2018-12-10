
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float GetRand() {
    return (float)rand() / (float)__INT32_MAX__;
}

int main() {
    int I,J,K,L;

    printf("Bitte geben Sie I ein!\t");
    scanf("%d", &I);
    printf("Bitte geben Sie J ein!\t");
    scanf("%d", &J);
    float A[I][J];

    printf("Bitte geben Sie K ein!\t");
    scanf("%d", &K);
    printf("Bitte geben Sie L ein!\t");
    scanf("%d", &L);
    float B[K][L];
    float C[I][L];

    if (J != K) {
        printf("--- Fehlerhafte Eingabe, J muss gleich K sein!\n\n\n");
        return 1;
    }

    // init random
    srand(time(NULL));

    printf("------------A-------------\n");
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            A[i][j] = GetRand();
            printf("%f\t", A[i][j]);
        }
        printf("\n");
    }

    printf("\n\n------------B-------------\n");
    for (int k = 0; k < K; k++) {
        for (int l = 0; l < L; l++) {
            B[k][l] = GetRand();
            printf("%f\t", B[k][l]);
        }
        printf("\n");
    }

    printf("\n\n------------C-------------\n");
    for (int l = 0; l < L; l++) {
        for (int i = 0; i < I; i++) {
            C[i][l] = 0.0;            
            for (int k = 0; k < K; k++) {
                C[i][l] += A[i][k] * B[k][l];
            }
            printf("%f\t", C[i][l]);
        }
        printf("\n");
    }

    return 0;
}