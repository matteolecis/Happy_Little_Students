#include "inizioTurno.h"

void inizioTurno(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI],
                 CartaCFU **mazzoCfu,
                 CartaCFU **mazzoCfuScarti,
                 CartaOstacolo **mazzoOstacoli,
                 Giocatore **listaGiocatori,
                 CartaOstacoloEstratta *cartaEstratta){
    Giocatore *giocatoreCorrente = *listaGiocatori;

    while (giocatoreCorrente != NULL) {
        // Conta il numero di carte CFU attualmente possedute dal giocatore
        int numCarte = contaCarteCFU(giocatoreCorrente);
        while (numCarte < MAX_CARTE_MANO) {
            if (*mazzoCfu == NULL) {
                printf("Il mazzo delle carte CFU è vuoto! Verrà mescolato il mazzo delle carte CFU scartate e verrà usato quello");
                shuffleMazzoCfu(mazzoCfuScarti, LOOPS);
                *mazzoCfu = *mazzoCfuScarti;
            }

            // Prendi la carta CFU superiore dal mazzo
            CartaCFU *cartaNuova = malloc(sizeof(CartaCFU));
            if (cartaNuova == NULL) {
                printf("Errore di allocazione memoria per la carta CFU.\n");
                exit(EXIT_FAILURE);
            }
            *cartaNuova = pescaCartaCfu(mazzoCfu);

            // Aggiungi la nuova carta CFU alla mano del giocatore
            cartaNuova->next = giocatoreCorrente->carte_cfu;
            giocatoreCorrente->carte_cfu = cartaNuova;

            numCarte++; // Incrementa il conteggio delle carte del giocatore
        }
        // Passa al prossimo giocatore nella lista
        giocatoreCorrente = giocatoreCorrente->next;
    }
    //TODO CLEARSCREEN QUI
    clearScreen();
    cartaEstratta->carta = pescaCartaOstacolo(mazzoOstacoli);
}
