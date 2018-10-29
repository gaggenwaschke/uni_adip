#include <stdio.h>

int main() {
    for (int a = 1; a <= 10; a++) {
        for (int b = 1; b <= 10; b++) {
            printf("%d x %d = %d\n", b, a, a*b);
        }
    }
}