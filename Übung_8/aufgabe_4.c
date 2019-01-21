#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>


#define ROUNDTRIPS          (4)


void swap(int* data, int a, int b) {
    int temp;
    temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

int findMin(int* data, int size, int pos) {
    int min = pos;
    int i;
    for(i = pos; i < size; i++) {
        if(data[i] < data[min])
            min = i;
        }
    return min;
}

void printFirst(int* data, int length) {
    int printed = 10;
    printf("[");
    for (int i = 0; i < printed && i < length; i++) {
        printf("%d,", data[i]);
    }
    if (length > 2 * printed) printf("...");
    printf("]\n");
}

void selectionSort(int* data, int length) {
    clock_t start,end;
    start = clock();

    int min, next;
    for(next = 0; next < length - 1; next++) {
        min = findMin(data, length, next);
        swap(data, next, min);
    }

    end = clock();
    printf("\t%-40s%-10dms\t", "time needed for selectionSort:", (int)(1000.0f * (end-start)/CLOCKS_PER_SEC));
    printFirst(data, length);
    printf("\n");
}

void insertionSort(int* data, int length) {
    clock_t start,end;
    start = clock();

    for (int i = 1; i < length; i++) {
        int next = data[i];
        int j = i-1;
        while(j >= 0 && data[j] > next) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = next;
    }

    end = clock();
    printf("\t%-40s%-10dms\t", "time needed for insertionSort:", (int)(1000.0f * (end-start)/CLOCKS_PER_SEC));
    printFirst(data, length);
    printf("\n");
}

void bubbleSort(int* data, int length) {
    clock_t start,end;
    start = clock();

    int pos;
    int hasSwapped;

    do {
        hasSwapped = 0;
        for(pos = 0; pos < length - 1; pos++) {
            if(data[pos] > data[pos + 1]) {
                swap(data, pos, pos+1);
                hasSwapped = 1;
            }
        }
    } while(hasSwapped == 1);

    end = clock();
    printf("\t%-40s%-10dms\t", "time needed for bubbleSort:", (int)(1000.0f * (end-start)/CLOCKS_PER_SEC));
    printFirst(data, length);
    printf("\n");
}

void innerQuickSort(int * data, int size, int l, int r)
{
    // 0. Initialisiere
    int i = l, j = r-1;
    // 1. Check auf Trivialfall
    if (l >= r) return;
    // Initialisiere pivot
    int pivot = data[r];
    // 2. Teile: Füge pivot an einem Platz p in F (=data),
    // ein, so dass F[i]<F[p] für l<=i<p und
    // F[j] >= F[p] für p<=j<=r.
    // 2.1 Finde äusserstes ungeordnetes Paar F[i], F[j],
    // i<j, mit F[i] >= pivot und F[j] < pivot und
    // F[s] < pivot für l<=s<i und F[s] >= pivot
    // für j<s<=r.
    while( data[i]< pivot) i++;
    while( j>=l && data[j] >= pivot) j--;
    // 2.2 Ordne Paar; finde nächstes ungeordnetes Paar.
    while( i < j ) {
        // i<j impliziert j>=l,
        // daher F[j]<pivot und F[i]>=pivot.
        swap(data, i, j);
        while( data[i] < pivot) i++;
        while( data[j]>= pivot) j--;
    }
    // 2.3 Endgültiger Platz für pivot ist i: es gilt i>j
    // (und nicht nur i>=j, denn i=j impliziert
    // pivot<=F[i]<pivot) und F[k]<pivot f¨ur 0<=k<i;
    // F[k]>=pivot für j<k<=r; wegen i>j folgt
    // F[k]>=pivot für i<=k<=r.
    swap(data, i, r);
    // 3. Herrsche: Sortiere links und rechts
    // vom Ausgangspunkt.
    innerQuickSort(data, size, l, i-1);
    innerQuickSort(data, size, i+1, r);
    // Das Combine war trivial!
}

void quickSort(int* data, int length) {
    clock_t start,end;
    start = clock();

    innerQuickSort(data, length, 0, length-1);

    end = clock();
    printf("\t%-40s%-10dms\t", "time needed for quickSort:", (int)(1000.0f * (end-start)/CLOCKS_PER_SEC));
    printFirst(data, length);
    printf("\n");
}

void merge(int* data, int start, int haelfte, int ende) {
    int pos1 = start, pos2 = haelfte + 1, i = 0;
    int temp[ende - start + 1];
    while(pos1 <= haelfte || pos2 <= ende) {
        if(pos2 > ende) {
            temp[i++] = data[pos1++];
        } else if (pos1 > haelfte) {
            temp[i++] = data[pos2++];
        } else if (data[pos1] < data[pos2]) {
            temp[i++] = data[pos1++];
        } else {
            temp[i++] = data[pos2++];
        }
    }
    for(i=0; i< ende - start + 1; i++) {
        data[start + i] = temp[i];
    }
}

void innerMergeSort(int* data, int start, int ende) {
    int haelfte;
        if(start != ende) {
        haelfte = (start + ende) / 2;
        innerMergeSort(data, start, haelfte);
        innerMergeSort(data, haelfte + 1, ende);
        merge(data, start, haelfte, ende);
    }
}

void mergeSort(int* data, int length) {
    clock_t start,end;
    start = clock();

    innerMergeSort(data, 0, length-1);

    end = clock();
    printf("\t%-40s%-10dms\t", "time needed for mergeSort:", (int)(1000.0f * (end-start)/CLOCKS_PER_SEC));
    printFirst(data, length);
    printf("\n");
}

int* getRandomArray(int length) {
    srand(time(NULL));
    int* a = malloc(length*sizeof(int));
    for (int i = 0; i < length; i++) {
        a[i] = rand();
    }
    return a;
}


int main() {
    int length[ROUNDTRIPS] = {1000, 10000, 50000, 100000};
    for (int i = 0; i < ROUNDTRIPS; i++) {
        printf("Elements: %d\n", length[i]);
        int* template = getRandomArray(length[i]);

        int* a = malloc(length[i]*sizeof(int));

        memcpy(a, template, length[i]*sizeof(int));
        selectionSort(a, length[i]);

        memcpy(a, template, length[i]*sizeof(int));
        insertionSort(a, length[i]);

        memcpy(a, template, length[i]*sizeof(int));
        bubbleSort(a, length[i]);

        memcpy(a, template, length[i]*sizeof(int));
        quickSort(a, length[i]);

        memcpy(a, template, length[i]*sizeof(int));
        mergeSort(a, length[i]);

        free(a);
        free(template);

        printf("\n");
    }

    return 0;
}