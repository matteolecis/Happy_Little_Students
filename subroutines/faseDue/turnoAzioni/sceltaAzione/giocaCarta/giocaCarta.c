#include "giocaCarta.h"
Giocata* giocaCarta(Giocatore *giocatoreCorrente, CartaCFU **mazzoCFU, CartaCFU **mazzoCFUScarti) {
    //TODO CLEARSCREEN QUI
    clearScreen();
    printf("Giocatore %s, ecco le tue carte CFU:\n", giocatoreCorrente->nomeUtente);
    stampaCarteCFU(giocatoreCorrente);

    int indiceCarta;
    int cartePossedute = contaCarteCFU(giocatoreCorrente);
    CartaCFU *cartaScelta = NULL;
    do
    {
        do
        {
            printf("\nScegli una carta CFU dalla tua mano (indice da 0 a %d): ", cartePossedute - 1);
            scanf("%d", &indiceCarta);

            if (indiceCarta < 0 || indiceCarta >= cartePossedute) {
                printf("SCELTA NON VALIDA\n");
            }
        }while(indiceCarta < 0 || indiceCarta >= cartePossedute);

        cartaScelta = getCartaCFU(giocatoreCorrente, indiceCarta);

        if (cartaScelta->effetto < NESSUNO || cartaScelta->effetto > ANNULLA) {
            printf("SCELTA NON VALIDA: Puoi giocare solo carte punto.\n");
            cartaScelta = NULL; // Resetta la carta scelta
        }

    } while (cartaScelta == NULL);

    cartaScelta = rimuoviCartaCFU(giocatoreCorrente, indiceCarta);

    // Inserisce la carta nel mazzo degli scarti
    cartaScelta->next = *mazzoCFUScarti;
    *mazzoCFUScarti = cartaScelta;

    Giocata *giocata = (Giocata *)malloc(sizeof(Giocata));
    giocata->giocatore = giocatoreCorrente;
    giocata->carta = cartaScelta;
    giocata->next = NULL;
    memorizzaCarteGiocateNelTurno(&giocata, giocata->giocatore, giocata->carta);

    return giocata;
}