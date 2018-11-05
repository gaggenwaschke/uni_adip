#include <stdio.h>
#include <string.h>

int main() {
    int a;
    printf("Bitte geben Sie eine Zahl zwischen 20 und 69 ein!\n");    
    scanf("%d", &a);
    if (a < 20 || a > 69) {
        printf("Your number is not in rangen!");
        return 0;
    }

    char str[18];
    
    int low = a % 10;
    int high = a / 10;

    switch(low) {
        case 0:
        // do nothing
        break;
        case 1:
        strcat(str, "ein-");
        break;
        case 2:
        strcat(str, "zwei-");
        break;
        case 3:
        strcat(str, "drei-");
        break;
        case 4:
        strcat(str, "vier-");
        break;
        case 5:
        strcat(str, "fünf-");
        break;
        case 6:
        strcat(str, "sechs-");
        break;
        case 7:
        strcat(str, "sieben-");
        break;
        case 8:
        strcat(str, "acht-");
        break;
        case 9:
        strcat(str, "neun-");
        break;
        default:
        printf("Error, unknown low value: %d", low);
        return 0;
    }

    if (low != 0) strcat(str, "und-");

    switch(high) {
        case 2:
        strcat(str, "zwanzig");
        break;
        case 3:
        strcat(str, "dreißig");
        break;
        case 4:
        strcat(str, "vierzig");
        break;
        case 5:
        strcat(str, "fünfzig");
        break;
        case 6:
        strcat(str, "sechzig");
        break;
        default:
        printf("Error, unknown low value: %d", low);
        return 0;
    }

    printf("%d = %s\n", a, str);

    return 0;
}