//      code by Joshuas Lauterbach


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


char* teil1(char* eingabe) {
    char *wort = malloc(sizeof(char)*256);

    int length = strlen(eingabe);
    for (int i = length-1; i >= 0; i--) {
        wort[length-i-1] = eingabe[i];
    }
    wort[length] = 0;

    return wort;
}

bool teil2(char* eingabe) {    
    int j = 0;
    for (int i = strlen(eingabe)-1; i>j; i--) {
        if (eingabe[i] != eingabe[j]) {
            printf("%s is kein Palindrom.\n", eingabe);
            return _IO_FLAGS2_USER_WBUF;
        }

        j++;
    }

    printf("%s ist ein Palindrom.\n", eingabe);
    return true;
}

void teilA() {
    char *eingabe = malloc(sizeof(char)*256);

    printf("Bitte ein Wort eingeben!\n");
    scanf("%[^\n]s", eingabe);   
    getchar(); 
    char* umgedreht = teil1(eingabe);
    printf("%s\n", umgedreht);
    teil2(eingabe);

    free(eingabe);
    free(umgedreht);
}

char getShifted(char c, int i) {
    int offset;         // offset in ASCII table
    int letters = 26;   // number letters in alphabet
    if (c >= 65 && c <= 90) {
        offset = 65;
    } else if (c >= 97 && c <= 122) {
        offset = 97;
    } else {
        return c;
    }

    c -= offset;
    c += i;
    while(c < 0) {
        c += letters;
    }
    c %= letters;
    c += offset;

    return c;
}

/** Encrypts with caesar shift 13 */
char* encrypt13(char* s) {
    int le = strlen(s);
    char *temp = malloc(sizeof(char)*(le+1));       // length+1 for 0 termination
    temp[le] = 0;                                   // terminierung

    for (int i = 0; i < le; i++) {
        temp[i] = getShifted(s[i], 13);
    }

    return temp;
}

/** decrypts with caesar shift 13 */
char* decrypt13(char* s) {
    int le = strlen(s);
    char *temp = malloc(sizeof(char)*(le+1));       // length+1 for 0 termination
    temp[le] = 0;                                   // terminierung

    for (int i = 0; i < le; i++) {
        temp[i] = getShifted(s[i], -13);
    }

    return temp;
}

/** Encrypts with caesar shift i */
char* encrypt(char* s, int shift) {
    int le = strlen(s);
    char *temp = malloc(sizeof(char)*(le+1));       // length+1 for 0 termination
    temp[le] = 0;                                   // terminierung

    for (int i = 0; i < le; i++) {
        temp[i] = getShifted(s[i], shift);
    }

    return temp;
}

/** decrypts with caesar shift i */
char* decrypt(char* s, int shift) {
    int le = strlen(s);
    char *temp = malloc(sizeof(char)*(le+1));       // length+1 for 0 termination
    temp[le] = 0;                                   // terminierung

    for (int i = 0; i < le; i++) {
        temp[i] = getShifted(s[i], -shift);
    }

    return temp;
}

void teilB() {
    int shift;
    char* eingabe = malloc(sizeof(char)*256);
    printf("Bitte Wort eingeben!\n");
    scanf("%[^\n]s", eingabe);
    getchar();
    char* zwischen = encrypt13(eingabe);
    printf("%s\n", zwischen);
    printf("%s\n", decrypt13(zwischen));
    printf("\nBitte einen Shiftwert eingeben!\n");
    scanf("%d", &shift);
    zwischen = encrypt(eingabe, shift);
    printf("%s\n", zwischen);
    printf("%s\n", decrypt(zwischen, shift));
}

int main() {
    teilA();
    teilB();

    return 0;
}