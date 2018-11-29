//      code by Joshua Lauterbach

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Implementierung eines dynamisch erweiterbaren Arrays */
struct DynArray {
    int length;
    int max_length;
    int *inner_array;
};

struct DynArrayMin {
    int length;
    int *inner_array;
};

void dyn_array_add(struct DynArray *arr, int number) {
    if (arr->max_length == 0) {
        // initialize
        arr->inner_array = malloc(sizeof(int));
        arr->max_length = 1;
        arr->length = 1;
        arr->inner_array[0] = number;
    } else {
        // extend inner array if needed
        if (arr->length >= arr->max_length) {
            int *new_inner_array = malloc(sizeof(int)*2*arr->max_length);
            for (int i = 0; i < arr->length; i++) {
                new_inner_array[i] = arr->inner_array[i];
            }
            free(arr->inner_array);
            arr->inner_array = new_inner_array;
            arr->max_length *= 2;
        }
        arr->inner_array[arr->length] = number;
        arr->length++;
    }
}

void dyn_array_min_add(struct DynArrayMin *arr, int number) {
    if (arr->length == 0) {
        // initialize
        arr->inner_array = malloc(sizeof(int));
        arr->length = 1;
        arr->inner_array[0] = number;
    } else {
        // extend inner array if needed
        int *new_inner_array = malloc(sizeof(int)*(arr->length+1));
        for (int i = 0; i < arr->length; i++) {
            new_inner_array[i] = arr->inner_array[i];
        }
        free(arr->inner_array);
        arr->inner_array = new_inner_array;
        arr->inner_array[arr->length] = number;
        arr->length++;
    }
}

void dyn_array_print(struct DynArray *arr) {
    printf("[");
    for (int i = 0; i < arr->length; i++) {
        printf("%d,", arr->inner_array[i]);
    }
    printf("]\n");
}

void dyn_array_min_print(struct DynArrayMin *arr) {
    printf("[");
    for (int i = 0; i < arr->length; i++) {
        printf("%d,", arr->inner_array[i]);
    }
    printf("]\n");
}

void testDynArray() {
    int cycles = 1;
    clock_t t;
    float seconds;

    do {
        struct DynArray arr = {0,0,NULL};

        t = clock();
        for (long i = 0; i < cycles; i++) {
            dyn_array_add(&arr, 10);
        }
        t = clock() - t;
        seconds = (float)t/(float)CLOCKS_PER_SEC;

        printf("Dauer von %d Zyklen auf DynArray:\t", cycles);
        printf("%fs\n", (float)t/(float)CLOCKS_PER_SEC);

        cycles *= 10;
    } while (seconds < 10.0);
}

void testDynArrayMin() {
    int cycles = 1;
    clock_t t;
    float seconds;

    do {
        struct DynArrayMin arr = {0,0,NULL};

        t = clock();
        for (long i = 0; i < cycles; i++) {
            dyn_array_min_add(&arr, 10);
        }
        t = clock() - t;
        seconds = (float)t/(float)CLOCKS_PER_SEC;

        printf("Dauer von %d Zyklen auf DynArrayMin:", cycles);
        printf("%fs\n", (float)t/(float)CLOCKS_PER_SEC);

        cycles *= 10;
    } while (seconds < 10.0);
}

int main() {
    struct DynArray arr = {0,0,NULL};
    struct DynArrayMin arr_min = {0,NULL};

    for (int i = 10; i < 60; i++) {
        dyn_array_add(&arr, i);
        dyn_array_min_add(&arr_min, i);
    }

    dyn_array_print(&arr);
    dyn_array_min_print(&arr_min);

    printf("\n\n");

    testDynArray();
    testDynArrayMin();
}