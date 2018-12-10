#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char nachname[30];
    float note;
} student;

int main() {
    int n;
    student *studenten;

    printf("Anzahl der Studenten eingeben!\t");
    scanf("%d", &n);
    printf("\n\n\n\n");

    studenten = malloc(sizeof(student)*n);

    for (int i = 0; i < n; i++) {
        printf("Bitte Nachnamen eingeben!\t");
        scanf("%s", &(studenten[i].nachname));

        do {
            printf("Bitte Note eingeben!\t");
            scanf("%f", &(studenten[i].note));
        } while(studenten[i].note < 1.0 || studenten[i].note > 5.0);

        printf("\n");
    }

    float besteNote = 6.0;
    float avg = 0.0;

    for (int i = 0; i < n; i++) {
        avg += studenten[i].note;
        if (studenten[i].note < besteNote) {
            besteNote = studenten[i].note;
        }
    }

    avg /= n;

    printf("Beste Studenten:\n");
    for (int i = 0; i < n; i++) {
        if (studenten[i].note == besteNote) {
            printf("\t%s\n", studenten[i].nachname);
        }
    }
    printf("Durchschnitt = %f\n\n", avg);

    free(studenten);

    return 0;
}