#include <stdio.h>

int main(){
    char x1,x2,result;
    // Beispiel 1:
    x1 = 35;
    x2 = 85;
    result = x1 + x2;
    printf("Beispiel 1: %hi + %hi = %hi\n",x1 ,x2, result);
    // Beispiel 2:
    x1 = 85;
    x2 = 85;
    result = x1 + x2;
    printf("Beispiel 2: %hi + %hi = %hi\n",x1 ,x2, result);
    return 0;
}

/* Der Fehler ist ein klassischer Überlauf der 8-bit Char Variable.
    85+85 = 170
    170%128 = 42
    -128+42 = -86
    */