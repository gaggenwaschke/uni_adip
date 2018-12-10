#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    long matrikelnummer;
    char *vorname;
    char *nachname;
} student;

student* NewStudent(long matrikelnummer, char* vorname, char* nachname) {
    student *s = malloc(sizeof(student));
    s->matrikelnummer = matrikelnummer;
    s->vorname = vorname;
    s->nachname = nachname;

    return s;
}

void print_student(student *s) {
    printf("(%ld) %s %s\n", s->matrikelnummer, s->vorname, s->nachname);
}

void print_students(student** s) {
    printf("Liste aller Studenten:\n");
    int i = 0;
    while(s[i] != NULL) {
        printf("\t");
        print_student(s[i++]);
    }
    printf("\n");
}

void clear_students(student** s) {
    int i = 0;
    while(s[i] != NULL) {
        free(s[i]);
        s[i] = NULL;
        i++;
    }

    printf("cleared students\n");
}

void get_name(long matrikelnummer, student** s) {
    int i = 0;
    while (s[i] != NULL) {
        if (s[i]->matrikelnummer == matrikelnummer) {
            printf("Found student:\t");
            print_student(s[i]);
            return;
        }
        i++;
    }
}

void add_student(long matrikelnummer, char* vorname, char* nachname, student** studenten, int max_n) {
    for (int i = 0; i<max_n; i++) {
        if(studenten[i] == NULL) {
            studenten[i] = NewStudent(matrikelnummer, vorname, nachname);
            printf("Added student @ %d\n", i);
            return;
        }
    }
    printf("Could not add student\n");
}

void remove_student(long matrikelnummer, student** s) {
    int i = 0;
    while(s[i] != NULL) {
        if (s[i]->matrikelnummer == matrikelnummer) {
            free(s[i]);

            // aufrücken
            int j = i+1;
            while(s[j] != NULL) {
                s[j-1] = s[j];
                j++;
            }
            s[j-1] = NULL;

            printf("deleted %ld\n", matrikelnummer);
            return;
        }

        i++;
    }
    printf("Could not find %ld\n", matrikelnummer);
}

int main() {
    student *stud = NewStudent(311233, "George", "Cloony");
    print_student(stud);

    free(stud);

    int number = 20;

    student** s = malloc(sizeof(student)*number);
    for (int i = 0; i < number; i++) {
        s[i] = NULL;
    }

    add_student(42, "Peter", "Griffin", s, number);
    get_name(42, s);
    add_student(30, "Karl", "Marx", s, number);
    remove_student(42, s);
    print_students(s);
    clear_students(s);
    print_students(s);

    free(s);
    return 0;
}