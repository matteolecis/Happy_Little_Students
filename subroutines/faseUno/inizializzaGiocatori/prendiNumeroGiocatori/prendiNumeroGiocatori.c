#include "prendiNumeroGiocatori.h"
int prendiNumeroGiocatori(){
    int nGiocatori;
    do {
        printf("\n\nQuanti giocatori devono giocare? [2-4 GIOCATORI] \n");
        scanf("%d", &nGiocatori);

        if(nGiocatori<MIN_NUM_GIOCATORI||nGiocatori>MAX_NUM_GIOCATORI)
            printf("NUMERO INSERITO NON VALIDO\n");

    } while(nGiocatori<MIN_NUM_GIOCATORI||nGiocatori>MAX_NUM_GIOCATORI);
    return nGiocatori;
}