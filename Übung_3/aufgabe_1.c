#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializegenerator() {
    srand(time(NULL));
}

int karteziehen() {
    int zufall = rand()%9 + 2;
    printf("Karte gezogen: %d\n", zufall);
    return zufall;
}

int main() {
    initializegenerator();

    int selection;
    int pts_player = 0;
    int pts_bank = 0;

    printf("Bank zieht eine Karte: ");
    pts_bank += karteziehen();
    printf("Bank hat %d Punkte\n\n", pts_bank);
    printf("-----------------------------\n");
    printf("-----------------------------\n");

    do {
        printf("Spieler zieht eine Karte:");
        pts_player += karteziehen();        
        printf("Spieler hat %d Punkte\n", pts_player);

        if (pts_player > 21) {
            printf("\n\t--Spieler verliert!--\n");
            return 0;
        }

        printf("Geben Sie die 1 ein um weiterzuspielen und eine andere Zahl zum beenden!\n");
        
        scanf("%d", &selection);
        printf("-----------------------------\n");


    } while(selection == 1);

    printf("-----------------------------\n");
    printf("-----------------------------\n");

    do {
        printf("Bank zieht eine Karte: ");
        pts_bank += karteziehen();
        printf("Bank hat %d Punkte\n", pts_bank);
    } while(pts_bank <= 16);

    if (pts_bank >= pts_player && pts_bank <= 21) {
        printf("\n\t--Spieler verliert!--\n");
    } else {
        printf("\n\t--Spieler gewinnt!--\n");
    }

    return 0;
}