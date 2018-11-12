//  code by Joshua Lauterbach
//  12.11.18

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX_RAND            (500)      // maximaler random Wert

int coins[6] = {50,20,10,5,2,1};

int rand_coins() {
    return rand() % MAX_RAND; 
}

int main() {
    // init random number generator
    srand(time(NULL));

    int chosen_coins = 0;
    int start_coins = rand_coins();
    int dif, test;
        
    while(chosen_coins <= start_coins){
        printf("\nBitte einen Wert größer als %d eingeben!\n", start_coins);
        scanf("%d", &chosen_coins);
    }

    dif = chosen_coins-start_coins;
    test = 0;
    
    printf("Rückgeld %d:\n", dif);
    
    for(int i = 0; i < 6; i++)
    {
        int count = dif / coins[i];
        printf("number %d:\t%d\n", coins[i], count);
        dif -= (count*coins[i]);
        test += count * coins[i];
    }  

    printf("test = %d\n", test);

    return 0;
}