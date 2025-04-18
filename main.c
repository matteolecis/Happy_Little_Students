#include "subroutines/misclibs/misclibs.h"
int main() {
    setbuf(stdout,0);
    // Dichiarazione variabili
    Personaggio listaPersonaggi[MAX_NUM_GIOCATORI];
    CartaCFU *mazzoCfu = NULL;
    CartaCFU *mazzoCfuScarti = NULL;
    CartaOstacolo *mazzoOstacoli = NULL;
    Giocatore *listaGiocatori = NULL;
    char nomeSave[MAX_NOME_SAVE];

    srand(time(NULL));

    // printf del titolo del gioco
    visualizzaPresentazione();

    char scelta;
    do {
        printf("\nVuoi caricare un salvataggio? (y/n): ");
        scanf(" %c", &scelta);
        if((scelta != 'y' && scelta != 'Y') && (scelta != 'n' && scelta != 'N'))
            printf("SCELTA NON VALIDA\n");
    } while((scelta != 'y' && scelta != 'Y') && (scelta != 'n' && scelta != 'N'));

    if ((scelta == 'n' || scelta == 'N')) {
        faseUno(listaPersonaggi, &mazzoCfu, &mazzoCfuScarti, &mazzoOstacoli, &listaGiocatori, nomeSave);
    }else {
        caricaPartita(nomeSave, &listaGiocatori, &mazzoCfu, &mazzoCfuScarti, &mazzoOstacoli);
    }
    printf("\n");
    faseDue(listaPersonaggi, &mazzoCfu, &mazzoCfuScarti, &mazzoOstacoli, &listaGiocatori,nomeSave);
    freeall(listaPersonaggi, &mazzoCfu, &mazzoCfuScarti, &mazzoOstacoli, &listaGiocatori);

    return 0;
}
